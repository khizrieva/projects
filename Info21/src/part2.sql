--Процедура добавления P2P проверки (ник проверяемого, ник проверяющего, название задания, статус P2P проверки, время)
CREATE OR REPLACE PROCEDURE add_p2p_review(Reviewee varchar, Reviewer varchar, TaskTitle varchar, Status check_status, ReviewTime time)
AS $$
BEGIN
	IF Status = 'Start' THEN
		INSERT INTO checks(Peer, Task, _Date)
		VALUES (Reviewee, TaskTitle, current_date);
		INSERT INTO P2P(_Check, CheckingPeer, _State, _Time)
		VALUES ((SELECT MAX(id) FROM Checks), Reviewer, Status, ReviewTime);
	ELSE 
		INSERT INTO P2P(_Check, CheckingPeer, _State, _Time)
		VALUES ((SELECT Checks.id FROM Checks JOIN P2P ON P2P._Check = Checks.id WHERE Checks.Peer = Reviewee AND Checks.Task = TaskTitle AND P2P._State = 'Start' ORDER BY 1 DESC LIMIT 1), Reviewer, Status, ReviewTime);
	END IF;
END;
$$ LANGUAGE plpgsql;

CALL add_p2p_review('kossmali'::varchar, 'xeniamad'::varchar, 'DO1_Linux'::varchar, 'Start'::check_status, current_time::time);
CALL add_p2p_review('kossmali'::varchar, 'xeniamad'::varchar, 'DO1_Linux'::varchar, 'Success'::check_status, current_time::time);

SELECT * FROM p2p;
SELECT * FROM checks;

--Процедура добавления проверки Verter'ом (ник проверяемого, название задания, статус проверки Verter'ом, время)
CREATE OR REPLACE PROCEDURE add_verter_test(Reviewee varchar, TaskTitle varchar, Status check_status, TestTime time)
AS $$
BEGIN
	INSERT INTO Verter(_Check, _State, _Time)
	VALUES ((SELECT id FROM (SELECT Checks.id, P2P._Time FROM Checks JOIN P2P ON P2P._Check = Checks.id 
			WHERE Checks.Peer = Reviewee AND Checks.Task = TaskTitle AND P2P._State = 'Success'
			ORDER BY 2 DESC LIMIT 1) AS sq), 
			Status, TestTime);
END;
$$ LANGUAGE plpgsql;

CALL add_verter_test('kossmali'::varchar, 'DO1_Linux'::varchar, 'Start'::check_status, current_time::time);
CALL add_verter_test('kossmali'::varchar, 'DO1_Linux'::varchar, 'Success'::check_status, current_time::time);

SELECT * FROM verter;

--Триггер: после добавления записи со статутом "начало" в таблицу P2P, изменить соответствующую запись в таблице TransferredPoints
-- Таблица transferredpeers автоматически дополняется новыми парами в случае отсутствия
CREATE OR REPLACE FUNCTION fun_trg_transfer_points() RETURNS TRIGGER
AS $$
BEGIN
	IF (SELECT count(id) FROM transferredpoints WHERE checkingpeer = NEW.CheckingPeer 
		AND checkedpeer = (SELECT Peer FROM Checks WHERE Checks.id = NEW._Check)) = 0 THEN
		INSERT INTO transferredpoints(checkingpeer, checkedpeer, pointsamount) VALUES (NEW.CheckingPeer, (SELECT Peer FROM Checks WHERE Checks.id = NEW._Check), 0);
	END IF;
	UPDATE transferredpoints SET pointsamount = pointsamount + 1 
		WHERE checkingpeer = NEW.CheckingPeer 
		AND checkedpeer = (SELECT Peer FROM Checks WHERE Checks.id = NEW._Check);
	RETURN NEW; -- если в теле функции использовали ссылку NEW
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_transfer_points AFTER INSERT ON P2P
FOR EACH ROW EXECUTE FUNCTION fun_trg_transfer_points();

-- Функции для проверки:

CALL add_p2p_review('lycheess'::varchar, 'valeride'::varchar, 'DO1_Linux'::varchar, 'Start'::check_status, current_time::time);

SELECT * FROM transferredpoints; 

-- Триггер: перед добавлением записи в таблицу XP, проверяет корректность добавляемой записи

CREATE OR REPLACE FUNCTION fun_trg_check_xp() RETURNS TRIGGER
AS $$
BEGIN
	IF NEW.XPAmount <= (SELECT MaxXP FROM Tasks JOIN Checks ON Checks.Task = Tasks.Title WHERE Checks.id = NEW._Check) AND (SELECT _State FROM Verter WHERE Verter."_check" = NEW._Check ORDER BY 1 DESC LIMIT 1) = 'Success' THEN
		RETURN NEW;
	ELSE RETURN NULL;
	END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER trg_check_xp BEFORE INSERT ON XP
FOR EACH ROW EXECUTE FUNCTION fun_trg_check_xp();

INSERT INTO XP(_Check, XPAmount)
VALUES (5, 22);

-- Функции для проверки:

SELECT * FROM checks;
SELECT * FROM XP ORDER BY 3;

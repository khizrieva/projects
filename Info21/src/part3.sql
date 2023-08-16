-- 1) Написать функцию, возвращающую таблицу TransferredPoints в более человекочитаемом виде
-- Ник пира 1, ник пира 2, количество переданных пир поинтов. 
-- Количество отрицательное, если пир 2 получил от пира 1 больше поинтов.

-- drop function if exists fnc_readable_transferred_points();

CREATE OR REPLACE
FUNCTION fnc_readable_transferred_points()
	RETURNS TABLE(Peer1 varchar,
Peer2 varchar,
PointsAmount int) AS
$$
BEGIN
	RETURN query(
SELECT
	tp1.CheckingPeer AS Peer1, 
				 		tp1.CheckedPeer AS Peer2,
				 (CASE
				WHEN tp2.ID IS NOT NULL THEN
					(tp1.PointsAmount - tp2.PointsAmount)
		ELSE tp1.PointsAmount
	END)
				                        AS PointsAmount
FROM
	TransferredPoints tp1
LEFT JOIN TransferredPoints tp2 ON
	tp2.ID != tp1.ID
	AND tp1.checkingpeer = tp2.checkedpeer
	AND tp1.checkedpeer = tp2.checkingpeer
	);
END;

$$ LANGUAGE plpgsql;

-- select * from fnc_readable_transferred_points();

-- 2) Написать функцию, которая возвращает таблицу вида: ник пользователя, название проверенного задания, кол-во полученного XP


-- drop function if exists fnc_success_tasks();

CREATE OR REPLACE
FUNCTION fnc_success_tasks()
	RETURNS TABLE(Peer varchar,
Task varchar,
XP bigint) AS
$$
BEGIN
		RETURN query (
SELECT
	Checks.Peer AS Peer,
	Checks.Task AS Task,
	XP.XPAmount AS XP
FROM
	Checks
JOIN XP ON
	XP._Check = Checks.Id
ORDER BY
	Peer
		);
END;

$$ LANGUAGE plpgsql;

-- select * from fnc_success_tasks();

-- 3) Написать функцию, определяющую пиров, которые не выходили из кампуса в течение всего дня

DROP FUNCTION IF EXISTS fnc_no_exit();

CREATE OR REPLACE
FUNCTION fnc_no_exit(IN _Day Date)
	RETURNS SETOF varchar AS
$$
BEGIN
		RETURN query (
SELECT
	TimeTracking.Peer
FROM
	TimeTracking
WHERE
	TimeTracking._Date = _Day
GROUP BY
	TimeTracking.Peer,
	TimeTracking._Date
HAVING
	count(_State)<3
ORDER BY
	Peer
		);
END;

$$ LANGUAGE plpgsql;

SELECT
	*
FROM
	fnc_no_exit('2023-02-07');

-- #4

CREATE OR REPLACE PROCEDURE get_points_change (ref refcursor)
AS $$
BEGIN OPEN ref FOR
WITH SpentPoints AS (SELECT CheckedPeer AS Peer, sum(PointsAmount) AS amount FROM transferredpoints GROUP BY CheckedPeer),
RecievedPoints AS (SELECT CheckingPeer AS Peer, sum(PointsAmount) AS amount FROM transferredpoints GROUP BY CheckingPeer)
SELECT RecievedPoints.Peer, RecievedPoints.amount - SpentPoints.amount AS PointsChange FROM RecievedPoints JOIN SpentPoints ON RecievedPoints.Peer = SpentPoints.Peer ORDER BY 2 DESC;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

 BEGIN;
 CALL get_points_change('ref');
 FETCH ALL IN "ref";
 CLOSE ref;
 COMMIT;

-- #5

CREATE OR REPLACE PROCEDURE get_points_change2 (ref refcursor)
AS $$
BEGIN OPEN ref FOR
WITH PlusPoints AS (SELECT peer1 AS Peer, sum(pointsamount) AS amount FROM fnc_readable_transferred_points() WHERE pointsamount > 0 GROUP BY peer1),
MinusPoints AS (SELECT peer2 AS Peer, sum(pointsamount) AS amount FROM fnc_readable_transferred_points() WHERE pointsamount > 0 GROUP BY peer2)
SELECT pp.Peer, COALESCE(pp.amount - mp.amount, pp.amount) AS PointsChange FROM PlusPoints pp LEFT JOIN MinusPoints mp ON mp.peer = pp.peer
UNION ALL
SELECT mp.Peer, pp.amount - mp.amount AS PointsChange FROM PlusPoints pp JOIN MinusPoints mp ON mp.peer = pp.peer WHERE mp.Peer NOT IN (SELECT peer FROM PlusPoints)
ORDER BY 2 desc;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

 BEGIN;
 CALL get_points_change2('ref');
 FETCH ALL IN "ref";
 CLOSE ref;
 COMMIT;

-- #6

CREATE OR REPLACE PROCEDURE get_most_popular_task (ref refcursor)
AS $$
BEGIN OPEN ref FOR
SELECT _date, task
FROM (
  SELECT _date, task, COUNT(*) AS task_count,
         RANK() OVER (PARTITION BY _date ORDER BY COUNT(*) DESC) AS rank
  FROM checks
  GROUP BY _date, task
) AS subquery
WHERE rank = 1;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

BEGIN;
CALL get_most_popular_task('ref');
FETCH ALL IN "ref";
CLOSE ref;
COMMIT;

-- #7

CREATE OR REPLACE FUNCTION get_peers_completed_block (block text)
RETURNS TABLE (Peer varchar, Day date)
AS $$
BEGIN
  CASE
    WHEN block = 'C' THEN
      RETURN QUERY
      SELECT p.nickname, c._date
      FROM peers p
      JOIN checks c ON c.peer = p.nickname
      WHERE c.task = 'C8_3DViewer_v1.0'
        AND c.id IN (
          SELECT c.id
          FROM verter
          WHERE verter."_check" = c.id
            AND verter."_state" = 'Success'
        )
      ORDER BY 2;
      
    WHEN block = 'CPP' THEN
      RETURN QUERY
      SELECT p.nickname, c._date
      FROM peers p
      JOIN checks c ON c.peer = p.nickname
      WHERE c.task = 'CPP4_3DViewer_v2.0'
        AND c.id IN (
          SELECT c.id
          FROM verter
          WHERE verter."_check" = c.id
            AND verter."_state" = 'Success'
        )
      ORDER BY 2;
      
    WHEN block = 'DO' THEN
      RETURN QUERY
      SELECT p.nickname, c._date
      FROM peers p
      JOIN checks c ON c.peer = p.nickname
      WHERE c.task = 'DOE-T'
        AND c.id IN (
          SELECT c.id
          FROM verter
          WHERE verter."_check" = c.id
            AND verter."_state" = 'Success'
        )
      ORDER BY 2;
  END CASE;
END;
$$ LANGUAGE plpgsql;

-- для проверки:

SELECT * FROM get_peers_completed_block('C');

-- #8

CREATE OR REPLACE PROCEDURE get_recommended_peers_for_all (ref refcursor)
AS $$
BEGIN OPEN ref FOR
WITH Friends_n AS
(SELECT * FROM (SELECT p.nickname, COALESCE(f.peer1, f.peer2) AS Friend FROM peers p JOIN friends f ON f.peer1 = p.nickname OR f.peer2 = p.nickname) AS f
WHERE f.nickname != f.friend)
SELECT DISTINCT ON (nickname) nickname, recommendedpeer FROM (SELECT fn.nickname, r.recommendedpeer, count(r.recommendedpeer) points FROM Friends_n AS fn JOIN recommendations r ON r.peer = fn.friend
GROUP BY 1, 2
ORDER BY 1, 3 DESC) AS sq;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

BEGIN;
CALL get_recommended_peers_for_all('ref');
FETCH ALL IN "ref";
CLOSE ref;
COMMIT;

-- #9

CREATE OR REPLACE FUNCTION get_percentage_of_blocks (block1 TEXT, block2 TEXT)
RETURNS TABLE (StartedBlock1 float, StartedBlock2 float, StartedBothBlocks float, DidntStartAnyBlock float)
AS $$
BEGIN
	RETURN query
	WITH Block1Started AS (
	SELECT DISTINCT peer AS peer1 FROM checks WHERE task = 
	CASE 
		WHEN block1 = 'C' THEN 'C2_SimpleBashUtils'
		WHEN block1 = 'CPP' THEN 'CPP1_s21_matrix+'
		WHEN block1 = 'DO' THEN 'DO1_Linux'
	END),
	Block2Started AS (
	SELECT DISTINCT peer AS peer2 FROM checks WHERE task = 
	CASE 
		WHEN block2 = 'C' THEN 'C2_SimpleBashUtils'
		WHEN block2 = 'CPP' THEN 'CPP1_s21_matrix+'
		WHEN block2 = 'DO' THEN 'DO1_Linux'
	END),
	BothStarted AS (
	SELECT peer1 AS bothpeer FROM Block1Started WHERE 
	peer1 IN (SELECT * FROM Block1Started) AND peer1 IN (SELECT * FROM Block2Started)
	),
	NoOneBlock AS (
	SELECT count(nickname) AS count4 FROM peers
	WHERE nickname NOT IN (SELECT * FROM Block1Started) AND nickname NOT IN (SELECT * FROM Block2Started)
	),
	Only1Block AS (
	SELECT count(peer1) AS count1 FROM Block1Started WHERE peer1 NOT IN (SELECT * FROM BothStarted)),
	Only2Block AS (
	SELECT count(peer2) AS count2 FROM Block2Started WHERE peer2 NOT IN (SELECT * FROM BothStarted)),
	AllPeers AS (
	SELECT count(nickname) countall FROM peers)
	
	SELECT count1::float/(SELECT * FROM Allpeers)*100, count2::float/(SELECT * FROM Allpeers)*100, (SELECT count(bothpeer) FROM BothStarted)::float/(SELECT * FROM Allpeers)*100 AS count3, count4::float/(SELECT * FROM Allpeers)*100 FROM Only1Block, Only2Block, NoOneBlock;
	
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

SELECT * FROM get_percentage_of_blocks('C', 'CPP');

-- #10

CREATE OR REPLACE PROCEDURE get_birthday_success_check_percentage (ref refcursor)
AS $$
BEGIN OPEN ref FOR
WITH SuccessfulChecksAtBirthday AS (
SELECT count(*) AS successful FROM verter v JOIN (
SELECT * FROM peers p JOIN checks c ON 
EXTRACT(MONTH FROM p.birthday) = EXTRACT(MONTH FROM c."_date")
AND EXTRACT(DAY FROM p.birthday) = EXTRACT(DAY FROM c."_date") 
AND p.nickname = c.peer) cab ON v."_check" = cab.id
WHERE _state = 'Success'),
FaildChecksAtBirthday AS (
SELECT count(*) AS failed FROM verter v JOIN (
SELECT * FROM peers p JOIN checks c ON 
EXTRACT(MONTH FROM p.birthday) = EXTRACT(MONTH FROM c."_date")
AND EXTRACT(DAY FROM p.birthday) = EXTRACT(DAY FROM c."_date") 
AND p.nickname = c.peer) cab ON v."_check" = cab.id
WHERE _state = 'Failure')
SELECT successful::float/(successful+failed)*100 AS "SuccessfulChecks", failed::float/(successful+failed)*100 AS "UnsuccessfulChecks" 
FROM SuccessfulChecksAtBirthday, FaildChecksAtBirthday;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

BEGIN;
CALL get_birthday_success_check_percentage('ref');
FETCH ALL IN "ref";
CLOSE ref;
COMMIT;

-- #11

CREATE OR REPLACE FUNCTION get_peers_SSF (task1 TEXT, task2 TEXT, task3 TEXT)
RETURNS TABLE (Peer varchar)
AS $$
BEGIN
	RETURN query SELECT nickname FROM peers
	WHERE nickname IN (SELECT c.peer FROM checks c JOIN p2p ON c.id = p2p."_check" JOIN verter v ON v."_check" = c.id
	WHERE p2p."_state" = 'Success' AND v."_state" = 'Success' AND task = task1)
	AND nickname IN (SELECT c.peer FROM checks c JOIN p2p ON c.id = p2p."_check" JOIN verter v ON v."_check" = c.id
	WHERE p2p."_state" = 'Success' AND v."_state" = 'Success' AND task = task2)
	AND nickname NOT IN (SELECT c.peer FROM checks c JOIN p2p ON c.id = p2p."_check" JOIN verter v ON v."_check" = c.id
	WHERE p2p."_state" = 'Success' AND v."_state" = 'Success' AND task = task3);
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

SELECT * FROM get_peers_SSF('C5_s21_decimal', 'C3_s21_string+', 'C4_s21_math');

-- #12

CREATE OR REPLACE PROCEDURE get_tasks_to_unlock(REF refcursor) AS 
$$
BEGIN 
	OPEN REF FOR
	WITH RECURSIVE count_tasks AS 
	(SELECT Title, 0 AS _count, ParentTask
	FROM Tasks
	WHERE ParentTask IS NULL
	UNION
	SELECT t.Title, _count + 1, t.ParentTask
	FROM tasks AS t
	JOIN count_tasks AS ct ON ct.Title = t.ParentTask)
	
	SELECT Title AS Task,
	_count AS LastCount
	FROM count_tasks ORDER BY 1;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

BEGIN;
CALL get_tasks_to_unlock('ref');
FETCH ALL IN "ref";
CLOSE ref;
COMMIT;

-- #13

-- Формат вывода: список дней

CREATE OR REPLACE FUNCTION get_good_days(N int)
RETURNS TABLE ("Day" date)
AS
$$
BEGIN
	RETURN query 
    WITH ChecksInfo AS 
    (SELECT c.id, _date, peer, v._check  AS id_check, t.maxxp AS max_xp, x.xpamount AS peer_get_xp, v._state
  	FROM checks c
    INNER JOIN p2p on c.id = p2p._check AND (p2p._state = 'Success')
    INNER JOIN verter v on c.id = v._check AND (v._state = 'Success')
    INNER JOIN tasks t on t.title = c.task
    INNER JOIN xp x on c.id = x._check
    ORDER BY _date)
    
    SELECT _date FROM ChecksInfo AS ci
    WHERE ci.peer_get_xp > ci.max_xp * 0.8
    GROUP BY _date
    HAVING count(_date) >= N;
END
$$ LANGUAGE plpgsql;

-- Для проверки:

SELECT * FROM get_good_days(3);


-- #14

CREATE OR REPLACE PROCEDURE get_top_1_xp (ref refcursor)
AS $$
BEGIN OPEN ref FOR
SELECT peer, sum(xpamount) AS XP FROM checks c JOIN XP ON c.id = XP."_check" GROUP BY peer
ORDER BY 2 DESC LIMIT 1;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

BEGIN;
CALL get_top_1_xp('ref');
FETCH ALL IN "ref";
CLOSE ref;
COMMIT;

-- #15

CREATE OR REPLACE FUNCTION get_peers_visited_before_time (selected_time time, N bigint)
RETURNS TABLE (Nickname varchar)
AS $$ BEGIN
RETURN query SELECT peer FROM timetracking t
WHERE _time < selected_time
GROUP BY peer
HAVING count(peer) > N;
END;
$$ LANGUAGE plpgsql;

-- Для проверки

SELECT * FROM get_peers_visited_before_time('120000', 1);

-- #16

CREATE OR REPLACE FUNCTION get_peers_exits_last_n_days_m_times (N integer, M integer)
RETURNS TABLE (Nickname varchar)
AS $$ BEGIN
RETURN query 
WITH LastDate AS (SELECT _date FROM timetracking ORDER BY 1 DESC LIMIT 1)
SELECT peer FROM timetracking t
WHERE _date BETWEEN (SELECT _date - N FROM LastDate) AND (SELECT _date FROM LastDate) AND _state = 2
GROUP BY peer
HAVING count(peer) > M;
END;
$$ LANGUAGE plpgsql;

-- Для проверки

SELECT * FROM get_peers_exits_last_n_days_m_times(5, 0);

-- #17

CREATE OR REPLACE PROCEDURE get_early_entries (ref refcursor)
AS $$
BEGIN OPEN ref FOR
WITH AllEntries AS (
SELECT TO_CHAR(_date, 'month') AS m, count(_date) AS ea FROM timetracking t
WHERE EXTRACT(MONTH FROM _date) = (SELECT EXTRACT(MONTH FROM birthday) FROM peers WHERE peer = nickname) AND _state = 1
GROUP BY _date)
SELECT TO_CHAR(_date, 'month') AS "Month", count(_date)/ea::float*100 AS "EarlyEntries" FROM timetracking t JOIN AllEntries ON
AllEntries.m = TO_CHAR(_date, 'month')
WHERE EXTRACT(MONTH FROM _date) = (SELECT EXTRACT(MONTH FROM birthday) FROM peers WHERE peer = nickname) AND _state = 1
AND EXTRACT(HOUR FROM _time) < '12'
GROUP BY _date, ea;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

BEGIN;
CALL get_early_entries('ref');
FETCH ALL IN "ref";
CLOSE ref;
COMMIT;

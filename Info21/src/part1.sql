CREATE TABLE Peers (
	Nickname varchar(255) NOT NULL PRIMARY KEY,
	Birthday date NOT NULL
);

CREATE TABLE Tasks (
	Title varchar(255) PRIMARY KEY,
	ParentTask varchar(255),
	MaxXP int DEFAULT 1 NOT NULL,
		CONSTRAINT fk_Tasks_ParentTask_Tasks_Title FOREIGN KEY (ParentTask) REFERENCES Tasks(Title)
);

/* */
CREATE TABLE Checks (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	Peer varchar(255) NOT NULL,
	Task varchar(255) NOT NULL,
	_Date date DEFAULT current_date NOT NULL,
		CONSTRAINT fk_Checks_Peer_Peers_Nickname FOREIGN KEY (Peer) REFERENCES Peers(Nickname),
		CONSTRAINT fk_Checks_Tasks_Tasks_Title FOREIGN KEY (Task) REFERENCES Tasks(Title)
);

/*Статус проверки*/
CREATE TYPE check_status AS ENUM ('Start',
'Success',
'Failure');

/* */
CREATE TABLE P2P (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	_Check bigint NOT NULL,
	CheckingPeer varchar(255) NOT NULL,
	_State check_status DEFAULT 'Start' NOT NULL,
	_Time time,
		CONSTRAINT fk_P2P_Check_Checks_id FOREIGN KEY (_Check) REFERENCES Checks(id),
		CONSTRAINT fk_P2P_CP_Peers_Nickname FOREIGN KEY (CheckingPeer) REFERENCES Peers(Nickname)
);

/* */
CREATE TABLE Verter (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	_Check bigint NOT NULL,
	_State check_status DEFAULT 'Start' NOT NULL,
	_Time time,
		CONSTRAINT fk_Verter_Check_Checks_id FOREIGN KEY (_Check) REFERENCES Checks(id)
);

CREATE TABLE TransferredPoints (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY ,
	CheckingPeer varchar(255) NOT NULL,
	CheckedPeer varchar(255) NOT NULL,
	PointsAmount int,
		CONSTRAINT fk_TransferredPoints_CheckingPeer_Peers_Nickname FOREIGN KEY (CheckingPeer) REFERENCES Peers(Nickname),
		CONSTRAINT fk_TransferredPoints_CheckedPeer_Peers_Nickname FOREIGN KEY (CheckedPeer) REFERENCES Peers(Nickname),
		CONSTRAINT ch_TransferredPoints_eq_peers_checking CHECK (CheckingPeer <> CheckedPeer)
);

CREATE TABLE Friends (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
	Peer1 varchar(255) NOT NULL,
	Peer2 varchar(255) NOT NULL,
		CONSTRAINT fk_Friends_Peer1_Peers_Nickname FOREIGN KEY (Peer1) REFERENCES Peers(Nickname),
		CONSTRAINT fk_Friends_Peer2_Peers_Nickname FOREIGN KEY (Peer2) REFERENCES Peers(Nickname),
		CONSTRAINT ch_Friends_eq_peers CHECK (Peer1 <> Peer2)
);

CREATE TABLE Recommendations (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY ,
	Peer varchar(255) NOT NULL,
	RecommendedPeer varchar(255) NOT NULL,
		CONSTRAINT fk_Recommendations_Peer_Peers_Nickname FOREIGN KEY (Peer) REFERENCES Peers(Nickname),
		CONSTRAINT fk_Recommendations_RecommendedPeer_Peers_Nickname FOREIGN KEY (RecommendedPeer) REFERENCES Peers(Nickname),
		CONSTRAINT ch_Recommendations_eq_peers_recommendations CHECK (Peer <> RecommendedPeer)
);

CREATE TABLE XP (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY ,
	_Check bigint NOT NULL,
	XPAmount bigint NOT NULL CHECK (XPAmount >= 0),
		CONSTRAINT fk_XP_Check_Checks_id FOREIGN KEY (_Check) REFERENCES Checks(id)
);

CREATE TABLE TimeTracking (
	id bigint GENERATED ALWAYS AS IDENTITY PRIMARY KEY ,
	Peer varchar(255) NOT NULL,
	_Date date DEFAULT current_date NOT NULL,
	_Time time DEFAULT current_time NOT NULL,
	_State int CHECK (_State = 1
OR _State = 2),
		CONSTRAINT fk_TimeTracking_Peer_Peers_Nickname FOREIGN KEY (Peer) REFERENCES Peers(Nickname)
);

--Процедура экспорта(Таблица, куда, разделитель)
CREATE OR REPLACE
PROCEDURE export(IN tablename varchar, IN PATH TEXT,
IN separator char) AS $$
    BEGIN
        EXECUTE format('COPY %s TO ''%s'' DELIMITER ''%s'' CSV HEADER;',
            tablename,
PATH,
separator);
END;

$$ LANGUAGE plpgsql;
--Процедура импорта(Таблица, откуда, разделитель)
CREATE OR REPLACE
PROCEDURE IMPORT(IN tablename varchar, IN PATH TEXT,
IN separator char) AS $$
    BEGIN
        EXECUTE format('COPY %s FROM ''%s'' DELIMITER ''%s'' CSV HEADER;',
            tablename,
PATH,
separator);
END;
$$ LANGUAGE plpgsql;


/*Данные для таблицы Tasks*/
insert into Tasks
values ('C2_SimpleBashUtils', NULL, 350),
       ('C3_s21_string+', 'C2_SimpleBashUtils', 750),
       ('C4_s21_math', 'C2_SimpleBashUtils', 300),
       ('C5_s21_decimal', 'C3_s21_string+', 350),
       ('C6_s21_matrix', 'C5_s21_decimal', 200),
       ('C7_SmartCalc_v1.0', 'C6_s21_matrix', 500),
       ('C8_3DViewer_v1.0', 'C7_SmartCalc_v1.0', 750),
       ('DO1_Linux', 'C3_s21_string+', 300),
       ('DO2_Linux_Network', 'DO1_Linux', 250),
       ('DO3_LinuxMonitoring_v1.0', 'DO2_Linux_Network', 350),
       ('DO4_LinuxMonitoring_v2.0', 'DO3_LinuxMonitoring_v1.0', 350),
       ('DO5_SimpleDocker', 'DO3_LinuxMonitoring_v1.0', 300),
       ('DO6_CICD', 'DO5_SimpleDocker', 300),
       ('DOE-T', 'DO6_CICD', 200),
       ('CPP1_s21_matrix+', 'C8_3DViewer_v1.0', 300),
       ('CPP2_s21_containers', 'CPP1_s21_matrix+', 350),
       ('CPP3_SmartCalc_v2.0', 'CPP2_s21_containers', 600),
       ('CPP4_3DViewer_v2.0', 'CPP3_SmartCalc_v2.0', 750);

-- заполнение таблиц  --
-- для проверок: поменяйте путь на свой
CALL import ('Peers(Nickname, Birthday)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Peers.csv', ',');
CALL import ('Friends(Peer1, Peer2)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Friends.csv', ',');
CALL import ('Recommendations (Peer,RecommendedPeer)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Recommendations.csv', ',');
CALL import ('TransferredPoints (CheckingPeer,CheckedPeer,PointsAmount)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/TransferredPoints.csv', ',');
CALL import ('Checks (Peer,Task,_Date)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Checks.csv', ',');
CALL import ('Verter (_Check, _State, _Time)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Verter.csv', ',');
CALL import ('P2P (_Check, CheckingPeer, _State, _Time)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/P2P.csv', ',');
CALL import ('TimeTracking (Peer, _Date, _Time, _State)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/TimeTracking.csv', ',');
CALL import ('XP(_Check, XPAmount)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/XP.csv', ',');




-- /*Вывод*/
-- select * from Peers;
-- select * from P2P;
-- select * from Friends;
-- select * from Recommendations;
-- select * from TimeTracking;
-- select * from TransferredPoints;
-- select * from Tasks;
-- select * from Checks;
-- select * from XP;
-- /*Очистка и удаление таблицы*/
-- TRUNCATE Peers, P2P, Friends, Recommendations, TimeTracking, TransferredPoints, Tasks, Checks, XP, Verter;			
-- drop table Peers, P2P, Friends, Recommendations, TimeTracking, TransferredPoints, Tasks, Checks, XP, Verter;
-- truncate friends;
-- drop table friends;

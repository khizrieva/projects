-- --Процедура экспорта(Таблица, куда, разделитель)
-- CREATE OR REPLACE PROCEDURE export(IN tablename varchar, IN path text, IN separator char) AS $$
--     BEGIN
--         EXECUTE format('COPY %s TO ''%s'' DELIMITER ''%s'' CSV HEADER;',
--             tablename, path, separator);
--     END;
-- $$ LANGUAGE plpgsql;

-- --Процедура импорта(Таблица, откуда, разделитель)
-- CREATE OR REPLACE PROCEDURE import(IN tablename varchar, IN path text, IN separator char) AS $$
--     BEGIN
--         EXECUTE format('COPY %s FROM ''%s'' DELIMITER ''%s'' CSV HEADER;',
--             tablename, path, separator);
--     END;
-- $$ LANGUAGE plpgsql;

-- /*Данные для таблицы Tasks*/
-- insert into Tasks
-- values ('C2_SimpleBashUtils', NULL, 350),
--        ('C3_s21_string+', 'C2_SimpleBashUtils', 750),
--        ('C4_s21_math', 'C2_SimpleBashUtils', 300),
--        ('C5_s21_decimal', 'C3_s21_string+', 350),
--        ('C6_s21_matrix', 'C5_s21_decimal', 200),
--        ('C7_SmartCalc_v1.0', 'C6_s21_matrix', 500),
--        ('C8_3DViewer_v1.0', 'C7_SmartCalc_v1.0', 750),
--        ('DO1_Linux', 'C3_s21_string+', 300),
--        ('DO2_Linux_Network', 'DO1_Linux', 250),
--        ('DO3_LinuxMonitoring_v1.0', 'DO2_Linux_Network', 350),
--        ('DO4_LinuxMonitoring_v2.0', 'DO3_LinuxMonitoring_v1.0', 350),
--        ('DO5_SimpleDocker', 'DO3_LinuxMonitoring_v1.0', 300),
--        ('DO6_CICD', 'DO5_SimpleDocker', 300),
--        ('DOE-T', 'DO6_CICD', 200),
--        ('CPP1_s21_matrix+', 'C8_3DViewer_v1.0', 300),
--        ('CPP2_s21_containers', 'CPP1_s21_matrix+', 350),
--        ('CPP3_SmartCalc_v2.0', 'CPP2_s21_containers', 600),
--        ('CPP4_3DViewer_v2.0', 'CPP3_SmartCalc_v2.0', 750);

-- -- заполнение таблиц  --
-- -- для проверок: поменяйте путь на свой
-- CALL import ('Peers(Nickname, Birthday)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Peers.csv', ',');
-- CALL import ('Friends(Peer1, Peer2)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Friends.csv', ',');
-- CALL import ('Recommendations (Peer,RecommendedPeer)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Recommendations.csv', ',');
-- CALL import ('TransferredPoints (CheckingPeer,CheckedPeer,PointsAmount)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/TransferredPoints.csv', ',');
-- CALL import ('Checks (Peer,Task,_Date)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Checks.csv', ',');
-- CALL import ('Verter (_Check, _State, _Time)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/Verter.csv', ',');
-- CALL import ('P2P (_Check, CheckingPeer, _State, _Time)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/P2P.csv', ',');
-- CALL import ('TimeTracking (Peer, _Date, _Time, _State)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/TimeTracking.csv', ',');
-- CALL import ('XP(_Check, XPAmount)', '/Users/kossmali/SQL2_Info21_v1.0-1/src/tablesdata/XP.csv', ',');


-- /*
-- Фейл проверки:
-- Фейл вертер - 5, 21
-- Фейл пир ту пир - 6, 14,30,31

-- В чекс должно быть 32 строки
-- В вертер доходят все проверки, которые не зафейлены пирами - 28 строк
-- В пир ту пир - тоже 32 строки
-- в хр доходят только успешные проверки - 26 строк

-- */

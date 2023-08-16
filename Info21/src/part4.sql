CREATE DATABASE OnlyFansDB;

CREATE TABLE "TableName_Person" (
	id bigint,
	_name varchar,
	_age int
);

CREATE TABLE "TableName_Donations" (
	amount bigint,
	_date date
);

CREATE TABLE "TableName_Fans" (
	nickname varchar
);

CREATE TABLE "Photos" (
	photo_id bigint
);

CREATE FUNCTION count_fans() RETURNS TRIGGER AS $trg_fans_insert_audit$
BEGIN
SELECT count(*) FROM "TableName_Fans";
END;
$trg_fans_insert_audit$ LANGUAGE plpgsql;

CREATE TRIGGER trg_fans_insert_audit
AFTER INSERT ON "TableName_Fans"
FOR EACH ROW
EXECUTE FUNCTION count_fans();

CREATE OR REPLACE PROCEDURE remove_tables_table_name() LANGUAGE plpgsql AS $$
DECLARE
    table_name1 TEXT;
BEGIN
    FOR table_name1 IN
        SELECT table_name
        FROM information_schema.tables
        WHERE table_name LIKE 'TableName%'
    LOOP
        EXECUTE 'DROP TABLE IF EXISTS ' || quote_ident(table_name1) || ' CASCADE';
    END LOOP;
END;
$$;

CALL remove_tables_table_name();

--4.2
CREATE OR REPLACE PROCEDURE get_all_functions (ref refcursor)
AS $$
BEGIN OPEN ref FOR
SELECT ir.routine_name, ip.data_type  FROM information_schema.routines ir
JOIN information_schema.parameters ip ON ir.specific_name = ip.specific_name
WHERE ir.specific_schema NOT IN ('information_schema', 'pg_catalog')
AND ip.ordinal_position >= 1
ORDER BY routine_name;
END;
$$ LANGUAGE plpgsql;

-- Для проверки:

 BEGIN;
 CALL get_all_functions('ref');
 FETCH ALL IN "ref";
 CLOSE ref;
 COMMIT;
 
--4.3 работает
CREATE OR REPLACE PROCEDURE remove_triggers(out delete_trigger_count bigint) LANGUAGE plpgsql AS $$
DECLARE
    trigger_name1 TEXT;
BEGIN
	delete_trigger_count:=0;
    FOR trigger_name1 IN
        SELECT trigger_name
        FROM information_schema.triggers
        WHERE trigger_schema = current_schema()
    LOOP
        EXECUTE 'DROP TRIGGER IF EXISTS ' || quote_ident(trigger_name1) || ' ON ' || quote_ident(trigger_name1);
		delete_trigger_count = 1 + delete_trigger_count;
    END LOOP;
END;
$$;

CALL remove_triggers(delete_trigger_count :=0);



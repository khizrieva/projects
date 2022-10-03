CC = gcc
STDFLAGS = -Wall -Wextra -Werror --coverage




all: s21_math.a test gcov_report

test: s21_math.a
	gcc -std=c11 test.c s21_math.a -L./ --coverage -o test.out -lcheck
	./test.out

s21_math.a:
	gcc -std=c11 -Wall -Wextra -Werror --coverage -c -g s21_math.c 
	ar rcs s21_math.a *.o
	ranlib s21_math.a

gcov_report: test
	lcov -t "report" -o report.info -c -d .
	genhtml -o report report.info

clean: 
	rm -rf *.gcda *.gcno *.gcov *.a *.o ./report *.info

rebuild: clean all
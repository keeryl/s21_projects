SAN = -fsanitize=address
W = -Wall -Werror -Wextra
FLAGS = -std=c11
GCC = gcc
LIBS = -lcheck
GCOV = --coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS += -lsubunit -lm -lrt -lpthread
endif

all: clean s21_math.a test gcov_report 
	
check: lint-fix lint-errors

clean:
	rm -rf *.o *.a *.out *.gcno *.gcda *.info report/

s21_math.o:
	${GCC} ${FLAGS} ${W} -c s21_math.c -o s21_math.o

s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o

brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

gcov_report:
	${GCC} ${FLAGS} ${W} ${GCOV} ${LIBS} s21_math.test.c s21_math.c -o test.out
	./test.out
	lcov -t "gcov_report" -o test_coverage.info -c -d .
	genhtml -o report test_coverage.info
	open report/index.html
	rm -f *.o *.a *.out *.gcno *.gcda *.info

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

lint-fix:
	clang-format -i -style=Google *.c *.h

lint-errors:
	clang-format -n -style=Google *.c *.h

test: clean check
	${GCC} ${FLAGS} ${W} ${LIBS} s21_math.test.c s21_math.c -o test.out
	./test.out

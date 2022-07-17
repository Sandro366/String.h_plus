CC = gcc
LDFLAGS = -Wall -Wextra -Werror
CFLAGS = -c
NAME = s21_string
TEST = TEST

OS = $(shell uname)

ifeq ($(OS), Linux)
	LIB_FLAGS = -lsubunit -lrt -lpthread -lm
else
	LIB_FLAGS =
endif

default: all

all: clean s21_string.a test

rebuild: clean all

test: s21_string.a
	$(CC) $(LDFLAGS) $(TEST).c $(NAME).a -lcheck $(LIB_FLAGS) -o $(TEST)
	./$(TEST)

s21_string.a:
	$(CC) $(CFLAGS) -o $(NAME).o $(NAME).c
	ar rcs $(NAME).a $(NAME).o
	ranlib $@
	cp $@ lib$@

gcov_report:
	$(CC) $(TEST).c $(NAME).c -lcheck $(LIB_FLAGS) --coverage -o $(TEST) 
	./$(TEST)
	lcov -t "$(TEST)" -o $(TEST).info -c -d .
	genhtml -o report $(TEST).info

clean:
	rm -rf *.a *.o *.so $(TEST) *.gc* *.info report

linter:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c
	python3 ../materials/linters/cpplint.py --extensions=h *.h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leaks:
	CK_FORK=no leaks --atExit -- ./$(TEST)

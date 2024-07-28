CC=g++
GT= -lgtest -pthread -lgtest_main -std=c++17 #-lgmock #-g
FLAGS= -Wall -Werror -Wextra
LIBS_LINUX= -lcheck -lm -lpthread -lrt -lsubunit -D_GNU_SOURCE
LIBS_MACOS= -L /usr/local/lib -lcheck

OS = $(shell uname)
ifeq ($(OS), Darwin)
OPEN=open gcov_report/index.html
LIBS=$(LIBS_MACOS)
LEAK_CHECK = CK_FORK=no leaks -atExit -- ./containers
endif

ifeq ($(OS), Linux)
OPEN=lynx
LIBS=$(LIBS_LINUX)
# LEAK_CHECK = valgrind --leak-check=full --show-leak-kinds=all -s ./containers
endif

all: test gcov_report

containers: clean
	$(CC) $(FLAGS) test_containers.cc -o containers $(GT) --coverage
	./containers

containersplus: clean
	$(CC) $(FLAGS) test_containersplus.cc -o containers $(GT) --coverage
	./containers

test: clean
	$(CC) $(FLAGS) test_containers.cc test_containersplus.cc -o containers $(GT) --coverage
	./containers

gcov_report: test
	gcovr --html --html-details -o report.html
	open report.html

style:
	clang-format -style=google -n *.cc
	clang-format -style=google -n *.h
	clang-format -style=google -n *.inl

clean:
	rm -rf *.out *.dSYM *.gch *.gcda *.gcno *.o *.a report.* s21_test.* test_with_gcov* *.gcov containers

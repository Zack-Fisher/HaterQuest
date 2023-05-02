CC = gcc
CFLAGS = -Wall -Wextra -I../include
LIBS = -lcheck -lm -lrt -lpthread -lsubunit
TARGET_DIR = ../src
TEST_SRCS = $(wildcard *.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_EXES = $(TEST_SRCS:.c=)

all: $(TEST_EXES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.o
	$(CC) $(CFLAGS) $(TARGET_DIR)/$*.o $< -o $@ $(LIBS)

.PHONY: run_tests
run_tests: $(TEST_EXES)
	for test_exe in $^; do \
		./$$test_exe; \
	done

clean:
	rm -f *.o $(TEST_EXES)

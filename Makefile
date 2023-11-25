CC := gcc
CFLAGS := -W -Wall

TEST_CFLAGS := $(CFLAGS)
TEST_LIBDIR := -L/usr/lib
TEST_LIB := -lcunit

all: test benchmark

.PHONY: test
test: test.c gcd.c
	$(CC) $^ $(TEST_CFLAGS) $(TEST_LIBDIR) $(TEST_LIB) -o $@ && ./$@

.PHONY: benchmark
benchmark: benchmark.c gcd.c
	$(CC) $^ $(CFLAGS) -O0 -o $@ && ./$@

.PHONY: clean
clean:
	-rm test benchmark

.DEFAULT_GOAL=all

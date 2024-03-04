CFLAGS = -std=gnu11 -Wall -Werror -Wextra

.PHONY: all
all: program1 program2

.PHONY: clean
clean:
	$(RM) common.o program1 program2

common.o: common.c common.h

program1: program1.c common.o

program2: program2.c common.o

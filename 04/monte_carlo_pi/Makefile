CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Werror -std=c17 -O3 -march=native -g
LDFLAGS=-lpthread

TARGETS=mc_pi_pthreads

.PHONY: all clean

all: $(TARGETS)

clean:
	$(RM) $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

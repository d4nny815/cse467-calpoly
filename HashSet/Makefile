CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g
LDFLAGS = -lm
MAIN = test_HashSet

OBJS = HashSet
PROGS = $(MAIN)

all : $(PROGS)

$(MAIN) : $(MAIN).c $(OBJS:%=%.o)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o : %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(PROGS) *.o


CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g -O
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


CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g -O
MAIN = Primitives_test

OBJS = Primitives
PROGS = $(MAIN)

all : $(PROGS)

$(MAIN) : $(MAIN).c $(OBJS:%=%.o)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(PROGS) *.o


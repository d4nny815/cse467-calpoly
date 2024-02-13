CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g
MAIN = main
BUILD_DIR = build
OBJS = ArrayList OffFile

PROGS = $(MAIN) 
all : dirs $(PROGS)

$(MAIN) : $(MAIN).c $(OBJS:%=$(BUILD_DIR)/%.o)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/ArrayList.o : ArrayList/ArrayList.c ArrayList/ArrayList.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/OffFile.o : OffFile/OffFile.c OffFile/OffFile.h
	$(CC) $(CFLAGS) -c -o $@ $<

dirs: 
	mkdir -p $(BUILD_DIR)

clean :
	rm -rf $(BUILD_DIR)
	rm $(MAIN)
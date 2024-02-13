CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g -O
MAIN = main
BUILD_DIR = build
OBJS = ArrayList OffFile Primitives Transformation

PROGS = $(MAIN) 
all : dirs $(PROGS)

$(MAIN) : $(MAIN).c $(OBJS:%=$(BUILD_DIR)/%.o)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/ArrayList.o : ArrayList/ArrayList.c ArrayList/ArrayList.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Primitives.o : Primitives/Primitives.c Primitives/Primitives.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/OffFile.o : OffFile/OffFile.c OffFile/OffFile.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Transformation.o : Transformation/Transformation.c Transformation/Transformation.h
	$(CC) $(CFLAGS) -c -o $@ $<

dirs: 
	mkdir -p $(BUILD_DIR)

clean :
	rm -rf $(BUILD_DIR)
	rm $(MAIN)
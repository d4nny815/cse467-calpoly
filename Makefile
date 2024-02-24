CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g
LDFLAGS = -lm
MAIN = main
BUILD_DIR = build
OBJS = ArrayList OffFile Primitives Transformation Lighting Projection Rasterization PGMFile

PROGS = $(MAIN) 
all : dirs $(PROGS)

$(MAIN) : $(MAIN).c $(OBJS:%=$(BUILD_DIR)/%.o)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/ArrayList.o : ArrayList/ArrayList.c ArrayList/ArrayList.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Primitives.o : Primitives/Primitives.c Primitives/Primitives.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/OffFile.o : OffFile/OffFile.c OffFile/OffFile.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Transformation.o : Transformation/Transformation.c Transformation/Transformation.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Lighting.o : Lighting/Lighting.c Lighting/Lighting.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Projection.o : Projection/Projection.c Projection/Projection.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/Rasterization.o : Rasterization/Rasterization.c Rasterization/Rasterization.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/PGMFile.o : PGMFile/PGMFile.c PGMFile/PGMFile.h
	$(CC) $(CFLAGS) -c -o $@ $<


dirs: 
	mkdir -p $(BUILD_DIR)

clean :
	rm -rf $(BUILD_DIR)
	rm -f $(MAIN)

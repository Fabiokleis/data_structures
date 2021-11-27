CC = gcc
COMPILER_FLAGS = -W
SOURCES = ./src/*.c
OBJ_NAME = ./build/sort

all:
	mkdir -p build
	$(CC) $(SOURCES) $(COMPILER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -f ./build/sort

run:
	./build/sort

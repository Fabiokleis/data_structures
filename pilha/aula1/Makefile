CC = gcc
COMPILER_FLAGS = -W
SOURCES = ./src/*.c
INCLUDES = ./include/
LINKER_FLAGS = 
OBJ_NAME = ./build/stack

all:
	mkdir -p build
	$(CC) $(SOURCES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -I $(INCLUDES) -o $(OBJ_NAME)

clean:
	rm -f ./build/stack

run:
	./build/stack 

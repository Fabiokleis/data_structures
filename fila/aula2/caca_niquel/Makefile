CC = gcc
COMPILER_FLAGS = -w
SOURCES = ./src/*.c
INCLUDES = ./include/
LINKER_FLAGS = 
OBJ_NAME = ./build/main

all: 
	$(CC) $(SOURCES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -I $(INCLUDES) -o $(OBJ_NAME)

clean:
	rm -f ./build/main

run:
	chmod +x init.sh
	./init.sh

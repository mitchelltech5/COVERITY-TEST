# Name of the executable
TARGET = main

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC = main.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target to build the executable
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Clean build artifacts
clean:
	rm -f $(TARGET) $(OBJ)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g  # Add -g for debugging and -Wall to enable all warnings

# Source files
SRC = jeopardy_main.c jeopardy_questions.c jeopardy_validation.c jeopardy_board.c

# Object files (same as source files, but with .o extension)
OBJ = $(SRC:.c=.o)

# Final executable target
TARGET = jeopardy

# Default target: build the program
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule to compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

# Optional: Make sure that clean doesn't conflict with a file named 'clean'
.PHONY: clean

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -g

# Source file and executable name
SRC := 0-parser.c 0-func1.c 0-main.c
EXE := hnm

# Default target (executable)
all: $(EXE)

# Compile the source file into an executable
$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $(EXE) $(SRC)

# Clean up object files and executable
clean:
	rm -f $(EXE)

.PHONY: all clean

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = main.c util.c

# Object files
OBJS = main.o util.o

# Output binary
TARGET = my_program

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compiling .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o $(TARGET)

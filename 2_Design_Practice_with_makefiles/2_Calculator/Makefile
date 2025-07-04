# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Source files
SRCS = main.c $(wildcard source/*.c)

# Object files in build/ folder
OBJS = $(patsubst %.c,build/%.o,$(notdir $(SRCS)))

# Executable name
TARGET = calculator

.PHONY: all clean

all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile each source file into build/*.o
build/%.o: source/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Compile main.c separately (since it's in root, not source/)
build/main.o: main.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Create build folder if it doesn't exist
build:
	mkdir build

clean:
	del /Q build\*.o $(TARGET).exe
	rmdir /S /Q build

# Define the compiler
CC := gcc

# Define the flags for compilation
CFLAGS := -Wall -Wextra -O2 -D__linux__ -Iinclude -Isource

# Define the linker flags
LDFLAGS :=

# Define the output executable name
OUTPUT := my_program

# Define the source directories
SRC_DIRS := source

# Collect all source files in the specified directories
SOURCES := $(shell find $(SRC_DIRS) -name '*.c')

# Exclude the source files in the excluded directory
SOURCES := $(filter-out source/layer/3ds/%, $(SOURCES))

# Generate the corresponding object file names
OBJS := $(SOURCES:.c=.o)

# Default target
all: $(OUTPUT)

# Compile and link the output executable
$(OUTPUT): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJS) $(OUTPUT)

.PHONY: all clean

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

# compile all files, except the ones in the layer directory outside of our target layer
SOURCES := $(shell find $(SRC_DIRS) -name '*.c')
SOURCES := $(filter-out source/layer/%, $(SOURCES))
SOURCES += $(shell find source/layer/sdl2 -name '*.c')

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

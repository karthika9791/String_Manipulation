# Specifies the GNU C compiler
CC = gcc
# Defines the name of the final executable file to be created
TARGET = string_operation
# Finds all .c source files in the current directory and all subdirectories
SRCS = $(shell find . -name "*.c")
# Finds all subdirectories, adds them as include paths
INCLUDES = $(addprefix -I,$(shell find . -type d))
# Sets compiler flags: enable all warnings (-Wall), include debug info (-g), 
# add include paths.
CFLAGS = -Wall -g $(INCLUDES)
# Creates list of object files 
OBJS = $(SRCS: .c=.o)
 # The default rule that tells Make to build the final target executable.
all: $(TARGET)
# Link all compiled object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
# rule telling to compile any .c file into its corresponding .o object file.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
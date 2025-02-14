# Set all your object files (the object files of all the .c files in your project)
OBJ = main.o inline_font.o

# Set any dependent header files so that if they are edited they cause a complete re-compile
DEPS = inline_font.h font1.h

# Any special libraries you are using in your project
INCLUDES = $(shell pkg-config --libs sdl2)

# Set any compiler flags you want to use
local_CFLAGS = $(CFLAGS) $(shell pkg-config --cflags sdl2) -Wall -Wextra -O2 -pipe -I.

# Set the compiler you are using (gcc for C or g++ for C++)
CC = gcc

# Set the filename extension of your C files
EXTENSION = .c

# Define a rule that applies to all files ending in the .o suffix
%.o: %$(EXTENSION) $(DEPS)
	$(CC) -c -o $@ $< $(local_CFLAGS)

# Combine them into the output file
# Set your desired exe output file name here
BitmapFontTest: $(OBJ)
	$(CC) -o $@ $^ $(local_CFLAGS) $(INCLUDES)

# Cleanup
.PHONY: clean

clean:
	rm -f *.o *~ BitmapFontTest



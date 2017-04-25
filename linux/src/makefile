# This is the makefile for HaxWorld
CC = g++
# Keep files alphabetically sorted for convenience
FILES = animation.c audio.c config.c define.h game.c intro.c loadimage.h version.c video.c 
OUT_EXE = haxworld

# Make sure you add attributes to the end of
# @$(CC) -o $(OUT_EXE) $(FILES)

build: $(FILES)
	@echo "Remember to edit version.c to change revision number before compiling!\n"
	@echo "Building...\nFiles: $(FILES)\n"
	@$(CC) -o $(OUT_EXE) $(FILES) -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
	@echo "\nDone."

clean:
	rm -f *.o core

rebuild: clean build

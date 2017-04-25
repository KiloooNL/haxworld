CC = g++
FILES = animation.c intro.c video.c version.c 
OUT_EXE = haxworld

build: $(FILES)
	@echo "Remember to edit version.c to change revision number before compiling!\n"
	@echo "Building...\nFiles: $(FILES) define.h version.c"
	@$(CC) -o $(OUT_EXE) $(FILES) -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
	@echo "\nDone."

clean:
	rm -f *.o core

rebuild: clean build

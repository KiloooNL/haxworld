CC = g++
FILES = intro.c menu.c animation.c
OUT_EXE = haxworld

build: $(FILES)
	@echo "Building...\nFiles: $(FILES)"
	@$(CC) -o $(OUT_EXE) $(FILES) -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
	@echo "\nDone."

clean:
	rm -f *.o core

rebuild: clean build

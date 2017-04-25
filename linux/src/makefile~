CC = g++
FILES = intro.c
OUT_EXE = haxworld

build: $(FILES)
	@echo "Building...\nFiles: $(FILES)"
	@$(CC) -o $(OUT_EXE) $(FILES) -lSDL
	@echo "\nDone."

clean:
	rm -f *.o core

rebuild: clean build


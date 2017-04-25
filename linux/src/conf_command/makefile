CC = g++
FILES = conf_command.cpp
OUT_EXE = conf_command

build: $(FILES)
	@echo "Building conf_command"
	@$(CC) -o $(OUT_EXE) $(FILES) 
	@echo "\nDone."

clean:
	rm -f *.o core

rebuild: clean build

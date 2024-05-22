ifeq ($(OS), Windows_NT)
	DELETE = del
	EXECUTABLE = exec.exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S), Linux)
		DELETE = rm
		EXECUTABLE = exec
    endif
    ifeq ($(UNAME_S), Darwin)
		DELETE = rm
		EXECUTABLE = exec
	endif
endif

HEADER_DIR = Inc
SOURCE_DIR = Src

SOURCE = $(SOURCE_DIR)/*.cpp

build:
	@g++ -std=c++20 -I $(HEADER_DIR) $(SOURCE) -o $(EXECUTABLE)

execute:
	@$(EXECUTABLE)

clear:
	@$(DELETE) $(EXECUTABLE)

.PHONY: build execute clear

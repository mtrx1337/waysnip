GLADE=$(shell pkg-config --cflags --libs gladeui-2.0)

CFLAGS=-Wall -Wextra -fsanitize=address $(GLADE)
SRC=./src/main.c

create_dirs:
	test -d ./bin || mkdir ./bin
	test -d ./out || mkdir ./out

compile: create_dirs
	clang -o ./bin/waysnip.bin $(CFLAGS) $(CLIB) $(SRC)

compile-prod: create_dirs
	clang -o ./bin/waysnip.bin $(CLIB) $(SRC)

debug: create_dirs
	clang -g -v -o ./bin/debug.bin $(CFLAGS) $(CLIB) $(SRC)

run:
	GDK_BACKEND=wayland ./bin/waysnip.bin

build: compile

rebuild: compile run

clean:
	rm ./bin/*

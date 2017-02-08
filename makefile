all: program

program: main.o game.o array.o
	gcc -o program main.o game.o array.o

main.o: main.c
	gcc -c main.c

game.o: game.c game.h
	gcc -c game.c

array.o: array.c array.h
	gcc -c array.c

clean:
	rm program main.o game.o array.o

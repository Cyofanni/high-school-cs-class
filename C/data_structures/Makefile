CC=gcc
CFLAGS= -c -Wall
all: main
main: main.o list.o
	$(CC) main.o list.o -o main
main.o: main.c
	$(CC) $(CFLAGS) main.c
list.o: list.c
clean:
	rm -rf *.o

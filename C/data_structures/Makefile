CC=gcc
CFLAGS= -c -Wall
all: main
main: main.o list.o bin_tree.o
	$(CC) main.o list.o bin_tree.o -o main
main.o: main.c
	$(CC) $(CFLAGS) main.c
list.o: list.c
bin_tree.o: bin_tree.c
clean:
	rm -rf *.o

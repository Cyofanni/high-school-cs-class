CC=gcc
CFLAGS= -c -Wall
all: main
main: main.o list.o queue_array.o bin_tree.o heap.o
	$(CC) main.o list.o queue_array.o bin_tree.o heap.o -o main
main.o: main.c
	$(CC) $(CFLAGS) main.c
list.o: list.c
queue_array.o: queue_array.c
bin_tree.o: bin_tree.c
heap.o: heap.c
clean:
	rm -rf *.o

CC=gcc
CFLAGS= -c -Wall
all: main
main: main.o list.o queue_array.o
	$(CC) main.o list.o queue_array.o -o main
main.o: main.c
	$(CC) $(CFLAGS) main.c
list.o: list.c
queue_array.o: queue_array.c
clean:
	rm -rf *.o

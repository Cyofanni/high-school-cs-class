CC=g++
CFLAGS= -c -Wall
all: main
main: main.o queue.o
	$(CC) main.o queue.o -o main
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
queue.o: queue.cpp
	$(CC) $(CFLAGS) queue.cpp
clean:
	rm -rf *.o

EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC): util.o heap.o
	$(CC) -o $(EXEC) util.o heap.o

util.o: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean:
	rm *.o
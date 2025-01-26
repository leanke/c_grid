CC = gcc
CFLAGS = -I./include
LDFLAGS = -lncurses

all: main

main: src/main.o src/grid.o src/entity.o src/item.o src/object.o src/tile.o
	$(CC) -o main src/main.o src/grid.o src/entity.o src/item.o src/object.o src/tile.o $(LDFLAGS)

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/grid.o: src/grid.c
	$(CC) $(CFLAGS) -c src/grid.c -o src/grid.o

src/entity.o: src/entity.c
	$(CC) $(CFLAGS) -c src/entity.c -o src/entity.o

src/item.o: src/item.c
	$(CC) $(CFLAGS) -c src/item.c -o src/item.o

src/object.o: src/object.c
	$(CC) $(CFLAGS) -c src/object.c -o src/object.o

src/tile.o: src/tile.c
	$(CC) $(CFLAGS) -c src/tile.c -o src/tile.o

clean:
	rm -f main src/*.o

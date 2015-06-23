CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

PROG = grafo

all: grafo

main.o: main.c
memo.o: memo.c memo.h
vertice.o: vertice.c vertice.h
lista.o: lista.c lista.h
grafo.o: grafo.c grafo.h

grafo: principal.o memo.o vertice.o lista.o grafo.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f *.o $(PROG)
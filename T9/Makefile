CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

PROG = grafo

all: grafo

main.o: main.c
memo.o: memo.c memo.h
vertice.o: vertice.c vertice.h
lista.o: lista.c lista.h
fila.o: fila.c fila.h
grafo.o: grafo.c grafo.h

grafo: main.o memo.o vertice.o lista.o fila.o grafo.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f *.o $(PROG)
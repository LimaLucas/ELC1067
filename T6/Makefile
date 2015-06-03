CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

PROG = expressao

all: expressao

principal.o: principal.c
pilha.o: pilha.c pilha.h
arv.o: arv.c arv.h
memo.o: memo.c memo.h

expressao: principal.o pilha.o arv.o memo.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
clean:
	rm -f *.o $(PROG)

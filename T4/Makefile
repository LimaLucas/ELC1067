###############################################################################
# Makefile para compilacao
###############################################################################
# define o compilador C
CC = gcc
# define flags do compilador
CFLAGS = -Wall -g
# define flags do ligador
LDFLAGS = -lm -lncurses

# define uma variavel com o nome do programa
PROG = solitaire

###############################################################################
# comeca aqui os alvos de compilacao
# cada alvo e formado de:
# alvo: dep1 dep2 
# 
# onde alvo e o arquivo gerado, e dep1 e dep2 sao dependencias para gerar o alvo.

# o primeiro alvo e o padrao.
all: solitaire

# descreve o objeto principal.o, compilado de forma implicita
principal.o: principal.c

# descreve o objeto vetor.o, compilado de forma implicita
vetor.o: vetor.c vetor.h

# descreve o objeto carta.o, compilado de forma implicita
carta.o: carta.c carta.h

# descreve o objeto memo.o, compilado de forma implicita
memo.o: memo.c memo.h

tela.o: tela.c tela.h
fila.o: fila.c fila.h
pilha.o: pilha.c pilha.h
jogo.o: jogo.c jogo.h
jogo_desenha.o: jogo_desenha.c 

# programa principal, compilado de forma implicita
solitaire: principal.o vetor.o carta.o memo.o fila.o pilha.o jogo.o jogo_desenha.o tela.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	

# comando para limpar arquivos, digite
# $ make clean 
clean:
	rm -f *.o $(PROG)

###############################################################################
# Makefile para compilacao
###############################################################################
# define o compilador C
CC = gcc
# define flags do compilador
CFLAGS = -Wall -g
# define flags do ligador
LDFLAGS = -lm

# define uma variavel com o nome do programa
PROG = principal

###############################################################################
# comeca aqui os alvos de compilacao
# cada alvo e formado de:
# alvo: dep1 dep2 
# 
# onde alvo e o arquivo gerado, e dep1 e dep2 sao dependencias para gerar o alvo.

# o primeiro alvo e o padrao.
all: principal

# descreve o objeto principal.o, compilado de forma implicita
principal.o: principal.c

# descreve o objeto vetor.o, compilado de forma implicita
vetor.o: vetor.c vetor.h

# descreve o objeto carta.o, compilado de forma implicita
carta.o: carta.c carta.h

# descreve o objeto memo.o, compilado de forma implicita
memo.o: memo.c memo.h

# programa principal, compilado de forma implicita
principal: principal.o vetor.o carta.o memo.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	

# comando para limpar arquivos, digite
# $ make clean 
clean:
	rm -f *.o $(PROG)

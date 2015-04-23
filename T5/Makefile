
CC = gcc
CFLAGS := $(CFLAGS) -g -Wall 
LDFLAGS := $(LDFLAGS) -lm -lallegro -lallegro_main \
    -lallegro_color -lallegro_font -lallegro_primitives -lallegro_image

all: editor

principal.o: principal.c
geom.o: geom.c geom.h
tela.o: tela.c tela.h
texto.o: texto.c texto.h
memo.o: memo.c memo.h
lista.o: lista.c lista.h

editor: principal.o geom.o tela.o  texto.o memo.o lista.o
	$(CC) $(CFLAGS) -o $@  $^ $(LDFLAGS)

clean:
	rm -f editor *.o

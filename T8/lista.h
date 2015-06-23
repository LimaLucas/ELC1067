#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"

struct vertice;

typedef struct lista {
	struct vertice* elem;
	struct lista* next;
} lista_t;

/* insere um novo elemento na lista */
lista_t* lista_insere();

/* remove um elemento da lista */
lista_t* lista_remove();

/* busca um elemento na lista */
lista_t* lista_busca();


#endif /* _LISTA_H_ */
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

/* remove um elemento vértice da lista */
lista_t* lista_remove();

/* busca um elemento vértice na lista */
vertice_t* lista_busca(lista_t* lst, char* sigla);


#endif /* _LISTA_H_ */
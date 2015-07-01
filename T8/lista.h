#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"

struct vertice;

typedef struct lista {
	struct vertice* noh;
	struct lista* next;
} lista_t;

/* insere um vértice na lista */
lista_t* lista_insere_vertice(lista_t* lst, struct vertice* noh);

/* remove um vértice da lista */
lista_t* lista_remove_vertice(lista_t* lst);

/* busca um elemento vértice na lista */
vertice_t* lista_busca(lista_t* lst, char* chave);

/* imprime uma lista */
void lista_imprime(lista_t* lst);

#endif /* _LISTA_H_ */
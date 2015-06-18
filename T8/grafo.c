#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"

/* cria um grafo vazio */
grafo_t* grafo_cria(void){

}

/* insere um vértice no grafo */
bool grafo_insere_vertice(grafo_t* g, vertice_t* v){

}

/* retorna um vértice associado a uma chave (usar strcmp) */
vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){

}

/*
 * Insere uma aresta entre os vértices v1 e v2. Como o grafo
 * é não-direcionado, a função deve procurar os dois vértices
 * (função anterior) e inserir um ao outro em sua lista de
 * adjacência (v1 na lista de v2, e v2 na lista de v1).
 */
bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2){

}

/* função que imprime vértices e arestas conforme formato */
void grafo_imprime(grafo_t* g){

}

/* destroi e libera memória de um grafo */
void grafo_destroi(grafo_t* g){

}


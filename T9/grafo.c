#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"
#include "fila.h"


grafo_t* grafo_cria(void){

	grafo_t* g = (grafo_t*) memo_aloca(sizeof(grafo_t));
	g->vertices = NULL;
	g->nvertices = 0;

	return g;
}


bool grafo_insere_vertice(grafo_t* g, vertice_t* noh){

	g->vertices = lista_insere_vertice(g->vertices, noh);
	g->nvertices++;
	
	return true;
}


vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){

	return lista_busca(g->vertices, chave);
}


bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2){

	vertice_t* noh1 = grafo_busca_vertice(g, v1);
	vertice_t* noh2 = grafo_busca_vertice(g, v2);

	if(noh1 != NULL && noh2 != NULL)
		noh1 = vertice_insere_aresta(noh1, noh2);

	return true;
}


void grafo_imprime(grafo_t* g){

	lista_t* aux = g->vertices;
	lista_t* auxi = aux->next;

	while(aux != NULL){
		if(aux->noh->adjacentes == NULL)
			printf(" %s -> --- ", aux->noh->chave);
		else
			printf(" %s -> ", aux->noh->chave);

		lista_imprime(aux->noh->adjacentes);
		
		aux = auxi;
		if(aux != NULL)
			auxi = aux->next;
	}
}

void grafo_imprime_vertices(grafo_t* g){

	lista_t* aux = g->vertices;
	lista_t* auxi = aux->next;
	
	while(aux != NULL){
		printf("%s -> %s \n", aux->noh->chave, aux->noh->nome);
		aux = auxi;
		if(aux != NULL)
			auxi = aux->next;
	}
}

void grafo_busca_largura(grafo_t* g, vertice_t* v){
	/*lista_t *Q, *aux, v;
	vertice_t* u;

	aux = g->vertices;
	while(aux != NULL){
		aux->noh->cor = BRANCO;
		aux = aux->next;
	}


	
	Q = fila_cria();
	Q = fila_insere(Q, s); // insere a fonte no final da fila
	
	while(fila_vazia(Q) == false){
		
		u = fila_remove(Q); // remove o primeiro da fila
		for( cada vertice adjacente v de u ) {
			if(v->cor == BRANCO){
				v->cor = CINZA; // marca como descoberto
				v->d = u->d + 1; // distancia do antecessor para este vertice
				v->ant = u; // antecessor do vertice v
				Q = fila_insere(Q, v);
			}
		}

		u->cor = PRETO; // visitou vertices adjacentes
	}*/
}


void grafo_caminho_curto(grafo_t* G, char* origem, char* destino){

}

void grafo_destroi(grafo_t* g){
	
	while(g->vertices != NULL)
		g->vertices = lista_remove_vertice(g->vertices);

	memo_libera(g);
}


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

void grafo_busca_largura(grafo_t* g, vertice_t* origem){
	lista_t *aux;
	vertice_t *u;

	aux = g->vertices;
	while(aux != NULL){
		aux->noh->cor = BRANCO;
		aux = aux->next;
	}
	
	fila_t* F = fila_cria();
	F = fila_insere_vertice(F, origem); // insere a origem no final da fila
	
	while(fila_vazia(F) == false){
		
		u = fila_remove_vertice(F); // remove o primeiro da fila
		for(aux = u->adjacentes; aux != NULL; aux = aux->next) {
			if(aux->noh->cor == BRANCO){
				aux->noh->cor = CINZA; // marca como descoberto
				aux->noh->distancia = u->distancia + 1; // distancia do antecessor para este vertice
				aux->noh->ant = u; // antecessor do vertice v
				F = fila_insere_vertice(F, aux->noh);
			}
		}

		u->cor = PRETO; // visitou vertices adjacentes
	}
}


void grafo_caminho_curto(grafo_t* g, char* origem, char* destino){
	vertice_t* o = grafo_busca_vertice(g, origem);
	vertice_t* d = grafo_busca_vertice(g, destino);
	
	if(o == d){
		printf("%s ", o->nome);
		return;
	}
	
	if(d->ant == NULL)
		printf("Nao existe caminho de %s até %s\n", o->nome, d->nome);
	else{
		grafo_caminho_curto(g, origem, d->ant->chave);
		printf("-> %s ", d->nome);
	}
}

void grafo_destroi(grafo_t* g){
	
	while(g->vertices != NULL)
		g->vertices = lista_remove_vertice(g->vertices);

	memo_libera(g);
}


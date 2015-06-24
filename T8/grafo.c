#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"


grafo_t* grafo_cria(void){

	grafo_t* g = (grafo_t*) memo_aloca(sizeof(grafo_t));
	g->vertices = NULL;
	g->nvertices = 0;

	return g;
}


bool grafo_insere_vertice(grafo_t* g, vertice_t* v){

	lista_t* novo = (lista_t*) malloc(sizeof(lista_t));

	novo->elem = v;
	novo->next = g->vertices;

	g->vertices = novo;

	g->nvertices++;
	
	return true;
}


vertice_t* grafo_busca_vertice(grafo_t* g, char* chave){

	return lista_busca(g->vertices, chave);
}


bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2){

	vertice_t* vt1 = grafo_busca_vertice(g, v1);
	vertice_t* vt2 = grafo_busca_vertice(g, v2);

	if(vt1 != NULL && vt2 != NULL){

		/* coloca o vt2 como aresta de vt1 */
		lista_t* novo = memo_aloca(sizeof(lista_t));

		novo->elem = vt2;
		novo->next = vt1->adjacentes;

		/* coloca o vt1 como aresta de vt2 */
		novo = memo_aloca(sizeof(lista_t));

		novo->elem = vt1;
		novo->next = vt2->adjacentes;		

	}
	
	return true;
}


void grafo_imprime(grafo_t* g){

	lista_t* aux = g->vertices;
	lista_t* auxi = aux->next;
	
	while(aux != NULL){
		if(aux->elem->adjacentes == NULL)
			printf("%s -> sem arestas ", aux->elem->chave);
		else
			printf("%s -> ", aux->elem->nome);

		while(aux->elem->adjacentes != NULL){
			printf("%s", aux->elem->adjacentes->elem->chave);
			
			if(aux->elem->adjacentes->next != NULL)
				printf(", ");

			aux->elem->adjacentes = aux->elem->adjacentes->next;
		}
		printf("\n");
		
		aux = auxi;
		if(aux != NULL)
			auxi = aux->next;
	}

}

void grafo_imprime_vertices(grafo_t* g){

	lista_t* aux = g->vertices;
	lista_t* auxi = aux->next;
	
	while(aux != NULL){
		printf("%s -> %s \n", aux->elem->chave, aux->elem->nome);		
		aux = auxi;
		if(aux != NULL)
			auxi = aux->next;
	}

}

void grafo_destroi(grafo_t* g){
	
	lista_t* aux = g->vertices;
	lista_t* auxi = aux->next;
	
	while(aux != NULL){

		while(aux->elem->adjacentes != NULL){
			aux->elem->adjacentes = vertice_remove_aresta(aux->elem);
		}

		memo_libera(aux->elem->chave);
		memo_libera(aux->elem->nome);
		memo_libera(aux->elem);
		
		aux = auxi;
		if(aux != NULL)
			auxi = aux->next;
	}

	memo_libera(g);
}


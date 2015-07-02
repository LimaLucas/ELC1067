#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lista.h"
#include "memo.h"


lista_t* lista_insere_vertice(lista_t* lst, struct vertice* noh){
	
	lista_t *novo *aux;
	novo = (lista_t*) memo_aloca(sizeof(lista_t));

	novo->noh = noh;
	novo->next = NULL;

	if(lst == NULL)
		return novo;
	
	else{
		aux = lst;
		while(aux->next != NULL)
			aux = aux->next;
		
		return aux;
	}
}

lista_t* lista_remove_vertice(lista_t* lst){
	vertice_t* aux;
	aux = lst->noh;
	
	lista_t* auxi = lst->next;

	while(aux->adjacentes != NULL)
		aux->adjacentes = vertice_remove_aresta(aux->adjacentes);

	memo_libera(aux->chave);
	memo_libera(aux->nome);
	memo_libera(aux);
	memo_libera(lst);
	
	return auxi;
}

struct vertice* lista_busca(lista_t* lst, char* chave){

	lista_t* aux;
	aux = lst;

	while(aux != NULL){
		if(!strcmp(aux->noh->chave, chave)){
			return aux->noh;
		}
		aux = aux->next;
	}

	return NULL;
}

void lista_imprime(lista_t* lst){
	lista_t* aux = lst;
	
	while(aux != NULL){
			printf("%s", aux->noh->chave);
			
			if(aux->next != NULL)
				printf(", ");

			aux = aux->next;
		}
		printf("\n");
}


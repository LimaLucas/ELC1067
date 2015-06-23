#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"

lista_t* lista_insere(){

}

lista_t* lista_remove(){

}

vertice_t* lista_busca(lista_t* lst, char* sigla){

	lista_t* aux;
	aux = lst;

	while(aux != NULL){
		if(!strcmp(aux->elem->chave, sigla)){
			return aux->elem;
		}
		aux = aux->next;
	}

	return NULL;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lista.h"
#include "memo.h"

vertice_t* lista_busca(lista_t* lst, char* chave){

	lista_t* aux;
	aux = lst;

	while(aux != NULL){
		if(!strcmp(aux->elem->chave, chave)){
			return aux->elem;
		}
		aux = aux->next;
	}

	return NULL;
}


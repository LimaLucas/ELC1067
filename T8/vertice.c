#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"

vertice_t* vertice_cria(int tam_chave, int tam_nome){
	vertice_t* v = (vertice_t*) memo_aloca(sizeof(vertice_t));
 			
	v->chave = (char*) memo_aloca(sizeof(char)*tam_chave);
	v->nome = (char*) memo_aloca(sizeof(char)*tam_nome);
	v->adjacentes = NULL;

	return v;
}

struct lista* vertice_remove_aresta(vertice_t* v){

	lista_t* aux = v->adjacentes->next;
	memo_libera(v->adjacentes);

	return aux;
}

vertice_t* vertice_busca_aresta(vertice_t* v, char* chave){

	return lista_busca(v->adjacentes, chave);
}

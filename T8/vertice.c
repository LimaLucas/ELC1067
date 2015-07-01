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

vertice_t* vertice_insere_aresta(vertice_t* v1, vertice_t* v2){
	
	lista_t* novo;	

	/* coloca o vt2 como aresta de vt1 */
	novo = memo_aloca(sizeof(lista_t));

	novo->noh = v2;
	novo->next = v1->adjacentes;

	v1->adjacentes = novo;

	/* coloca o vt1 como aresta de vt2 */
	novo = memo_aloca(sizeof(lista_t));

	novo->noh = v1;
	novo->next = v2->adjacentes;

	v2->adjacentes = novo;

	return v1;
}

struct lista* vertice_remove_aresta(struct lista* lst){

	lista_t* aux = lst->next;
	memo_libera(lst);

	return aux;
}

vertice_t* vertice_busca_aresta(vertice_t* v, char* chave){

	return lista_busca(v->adjacentes, chave);
}

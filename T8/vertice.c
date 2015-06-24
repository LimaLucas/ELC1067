#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"

struct lista* vertice_remove_aresta(vertice_t* v){

	lista_t* aux = v->adjacentes->next;
	memo_libera(v->adjacentes);

	return aux;
}

vertice_t* vertice_busca_aresta(vertice_t* v, char* chave){

	return lista_busca(v->adjacentes, chave);
}

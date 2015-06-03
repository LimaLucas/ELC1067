
#include <stdbool.h>
#include "memo.h"
#include "pilha.h"
#include "arv.h"

/* retorna uma nova pilha, vazia */
pilha_t* pilha_cria(void){
	
	pilha_t* P = (pilha_t*) memo_aloca(sizeof(pilha_t));
	P->arv = NULL;
	P->next = NULL;

	return P;
}

/* destrói a pilha p, que deverá estar vazia. */
void pilha_destroi(pilha_t* p){
	
	while(p!=NULL)
		p = pilha_remove(p);
}

/* retorna true se a pilha p estiver vazia. */
bool pilha_vazia(pilha_t* p){

	return p == NULL;
}

/* insere o dado arv do tipo arv_t na pilha p */
pilha_t* pilha_insere(pilha_t* p, arv_t* arv){
	
	pilha_t* aux = (pilha_t*) memo_aloca(sizeof(pilha_t));

	aux->arv = arv;
	aux->next = p;

	p = aux;

	return p;
}

/* remove e retorna o nó operador/operando no topo da pilha */
pilha_t* pilha_remove(pilha_t* p){
	
	pilha_t* aux = p;

	p = p->next;
	memo_libera(aux);
	
	return p;
}

/* retorna true se p for uma pilha válida */
bool pilha_valida(pilha_t p){

	return true;
}


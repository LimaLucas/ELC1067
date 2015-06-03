
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "memo.h"
#include "arv.h"
#include "pilha.h"

/* criar uma árvore com o operador ou operando */
arv_t* arv_cria(op_t op){

	arv_t* A = (arv_t*) memo_aloca(sizeof(arv_t));

	A->esq = NULL;
	A->dir = NULL;
	A->dado = op;

	return A;
}

/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, arv_t* esquerda){

	arv->esq = esquerda;
	return arv;
}

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, arv_t* direita){

	arv->dir = direita;
	return arv;
}

/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv){
	
	if(arv != NULL){
		if(arv->dado.tipo == OPERANDO)
			printf("%g ", arv->dado.u.operando);
		else
			printf("%c ", arv->dado.u.operador);
		
		arv_imprime_pre_ordem(arv->esq);
		arv_imprime_pre_ordem(arv->dir);
	}
}

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv){
	
	if(arv != NULL){
		arv_imprime_em_ordem(arv->esq);
		
		if(arv->dado.tipo == OPERANDO)
			printf("%g ", arv->dado.u.operando);
		else
			printf("%c ", arv->dado.u.operador);
		
		arv_imprime_em_ordem(arv->dir);
	}
}

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv){

	if(arv != NULL){
		arv_imprime_pos_ordem(arv->esq);
		arv_imprime_pos_ordem(arv->dir);
		
		if(arv->dado.tipo == OPERANDO)
			printf("%g ", arv->dado.u.operando);
		else
			printf("%c ", arv->dado.u.operador);
		
	}
}

/*  destroi toda a árvore */
void arv_destroi(arv_t* arv){
	
	if(arv != NULL){
		arv_destroi(arv->esq);
		arv_destroi(arv->dir);
		memo_libera(arv);
	}
}


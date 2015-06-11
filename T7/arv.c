
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

		if(arv->dado.tipo == OPERADOR)
			printf("(");

		arv_imprime_em_ordem(arv->esq);
		
		if(arv->dado.tipo == OPERANDO)
			printf("%g", arv->dado.u.operando);
		else
			printf(" %c ", arv->dado.u.operador);
		
		arv_imprime_em_ordem(arv->dir);

		if(arv->dado.tipo == OPERADOR)
			printf(")");
	}
}

/* imprime a árvore em ordem: esquerda, raiz, e direita (n=1-esq, n=2-dir) */
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

/* Calcula a expressão salva na árvore */
double calcula_arv(arv_t* arv){

	if(arv->dado.tipo == OPERANDO){
		return arv->dado.u.operando;

	}else{
		if(arv->dado.u.operador == '+')
			return calcula_arv(arv->esq) + calcula_arv(arv->dir);
		
		else if(arv->dado.u.operador == '-')
			return calcula_arv(arv->esq) - calcula_arv(arv->dir);
		
		else if(arv->dado.u.operador == '*')
			return calcula_arv(arv->esq) * calcula_arv(arv->dir);
		
		else if(arv->dado.u.operador == '/')
			return calcula_arv(arv->esq) / calcula_arv(arv->dir);
	}
	return 0;
}

/*  destroi toda a árvore */
void arv_destroi(arv_t* arv){
	
	if(arv != NULL){
		arv_destroi(arv->esq);
		arv_destroi(arv->dir);
		memo_libera(arv);
	}
}


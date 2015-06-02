
#ifndef _ARV_H_
#define _ARV_H_

#include <stdbool.h>

/* criar uma árvore com o operador ou operando */
arv_t* arv_cria(op_t op){

	arv_t A = (arv_t*) memoaloca(sizeof(arv_t));

	A->esq = NULL;
	A->dir = NULL;
	A->dado = op;

	return A;

}

/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, op_t op){

}

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, op_t op){

}

/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv){

}

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv){

}

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv){

}

/*  destroi toda a árvore */
void arv_destroi(arv_t* arv){
	
	if(arv != NULL){
		arv_destroi(arv->esq);
		arv_destroi(arv->dir);
		memo_libera(arv);
	}
}


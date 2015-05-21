#ifndef _ARV_H_
#define _ARV_H_
/*
 * arv.h
 * TAD que implementa uma árvore binária.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdbool.h>

/* enumerador para operador ou operando */
typedef enum {OPERADOR, OPERANDO} op_tipo_t;

typedef struct op_t {
	op_tipo_t tipo;			/* tipo operador ou operando */
	/* union de operador/operando: apenas um deles pode ser usado */
	/* nunca usar ambos ao mesmo tempo */
	union {
		double operando;
		char operador;
	} u;
} op_t;

typedef struct _arv {
	struct _arv* esq;
	struct _arv* dir;

	/* o tipo do nó será operador ou operando */
	op_t dado;
} arv_t;

/* criar uma árvore com o operador ou operando */
arv_t* arv_cria(op_t op);

/* insere um novo dado na árvore a esquerda */
arv_t* arv_insere_esquerda(arv_t* arv, op_t op);

/* insere um novo dado na árvore a direita */
arv_t* arv_insere_direita(arv_t* arv, op_t op);

/* imprime a árvore em pré-ordem: raiz, esquerda, e direita */
void arv_imprime_pre_ordem(arv_t* arv);

/* imprime a árvore em ordem: esquerda, raiz, e direita */
void arv_imprime_em_ordem(arv_t* arv);

/* imprime a árvore em pós-ordem: esquerda, direita, e raiz */
void arv_imprime_pos_ordem(arv_t* arv);

/*  destroi toda a árvore */
void arv_destroi(arv_t* arv);

#endif /* _ARV_H_ */

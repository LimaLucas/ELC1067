/*
 * fila.c
 * TAD que implementa uma fila de elementos do tipo fila.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 *               2005       Benhur Stein, UFSM
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

/*
 * Créditos do código acima.
 * Com alterações realizadas pelo aluno Lucas Lima
 * de Oliveira para realização do trabalho T4 e T9, da matéria de 
 * Laboratório de Programação II
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "memo.h"
#include "fila.h"
#include "lista.h"
#include "vertice.h"

/* retorna uma nova fila, vazia */
fila_t* fila_cria(void){

	fila_t* f = (fila_t*) memo_aloca(sizeof(fila_t));

	f->first = NULL;
	f->last = NULL;
	
	return f;
}

/* destrói a fila f, que deverá estar vazia. */
void fila_destroi(fila_t* f){
	memo_libera(f);
}

/* retorna true se a fila f estiver vazia. */
bool fila_vazia(fila_t* f){

	return (f->first == NULL);
}

/* insere o dado c do tipo carta na fila f */
fila_t* fila_insere_vertice(fila_t* f, vertice_t* v){

	lista_t* novo = (lista_t*) memo_aloca(sizeof(lista_t));

	novo->noh = v;
	novo->next = NULL;

	if(f->last == NULL)
		f->first = novo;
	else
		f->last->next = novo;

	f->last = novo;
	return f;
}

/* remove e retorna a carta no topo da fila */
vertice_t* fila_remove_vertice(fila_t* f){

	lista_t* laux;
	laux = f->first;

	vertice_t* vaux;
	vaux = laux->noh;

	f->first = f->first->next;
	if(f->first == NULL)
		f->last = f->first;

	memo_libera(laux);
	return vaux;
}


#ifndef _FILA_H_
#define _FILA_H_
/*
 * fila.h
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

#include <stdbool.h>
#include "carta.h"

/* definicao do tipo fila */
typedef struct _fila* fila;

/* funções que permitem realizar operações sobre uma fila */

/* retorna uma nova fila, vazia */
fila fila_cria(void);

/* destrói a fila f, que deverá estar vazia. */
void fila_destroi(fila f);

/* retorna true se a fila f estiver vazia. */
bool fila_vazia(fila f);

/* insere o dado c do tipo carta na fila f */
void fila_insere_carta(fila f, carta c);

/* remove e retorna a carta no topo da fila */
carta fila_remove_carta(fila f);

/* retorna true se f for uma fila válida */
bool fila_valida(fila f);

#endif

/*
 * pilha.c
 * TAD que implementa uma fila de elementos do tipo pilha.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 JoÃ£o V. Lima, UFSM
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

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "pilha.h"

struct _pilha {
	fila topo;
};

pilha pilha_cria(void)
{
	pilha p = (struct _pilha*)malloc(sizeof(struct _pilha));
	p->topo = fila_cria();
	return p;
}

void pilha_destroi(pilha p)
{
	fila_destroi(p->topo);
	free(p);
}

bool pilha_vazia(pilha p)
{
	return fila_vazia(p->topo);
}

void pilha_insere_carta(pilha p, carta c)
{
	fila_insere_carta(p->topo, c);
}

carta pilha_remove_carta(pilha p)
{
	return fila_remove_carta(p->topo);
}

bool pilha_valida(pilha p)
{
	return ((p != NULL) && (p->topo != NULL));
}

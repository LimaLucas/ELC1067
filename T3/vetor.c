/*
 * vetor.c
 * TAD que implementa um vetor dinamico.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

#define TAM 50

struct vetor {
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */
	bool removido; /* verifica se houver remoção de uma carta */
};

vetor_t* vetor_cria(void)
{
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet->n = 0;
	int i;

	vet->baralho = (carta*) memo_aloca(TAM*sizeof(carta));

	for(i=0; i<TAM; i++)
        vet->baralho[i] = NULL;

	return vet;
}

void vetor_destroi(vetor_t* vet)
{
	memo_libera(vet->baralho);
	memo_libera(vet);
}

int vetor_numelem(vetor_t *vet)
{
	return vet->n;
}

void vetor_insere_carta(vetor_t *vet, int indice, carta c)
{
	int i, novoTam;

	if(vet->n%TAM == 0 && !vet->removido){
        novoTam = vet->n*sizeof(vetor_t*) + TAM*sizeof(vetor_t*);
        vet->baralho = (vetor_t*) memo_realoca(vet->baralho, novoTam);

        for(i=vet->n; i<novoTam; i++)
            vet->baralho[i] = NULL;

        vet->removido = false;
	}

	vet->baralho[indice] = c;
	vet->n++;
}

carta vetor_remove_carta(vetor_t *vet, int indice)
{
    carta retorna;
    retorna = vet->baralho[indice];

    if(retorna == NULL)
        return NULL;

    vet->removido = true;
    for(indice; vet->baralho[indice]!=NULL; indice++)
        vet->baralho[indice] = vet->baralho[indice-1];

	vet->n--;
	return NULL;
}

carta vetor_acessa_carta(vetor_t *vet, int indice)
{
	return vet->baralho[indice];
}

bool vetor_valido(vetor_t *vet)
{
	return true;
}

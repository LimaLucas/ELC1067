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

/*
 * Créditos do código acima.
 * Com alterações realizadas pelo aluno Lucas Lima
 * de Oliveira para realização do trabalho T4, Solitaire, da matéria de 
 * Laboratório de Programação II
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

#define TAM 10

struct vetor {
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */
};

vetor_t* vetor_cria(void)
{
	vetor_t *vet = (vetor_t*) memo_aloca(sizeof(vetor_t));
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

	if(vet->n%TAM == 0 && vet->n != 0){
        novoTam = (vet->n+TAM)*sizeof(carta);
        vet->baralho = (carta*) memo_realoca(vet->baralho, novoTam);

        novoTam = vet->n + TAM;
        for(i=vet->n; i<novoTam; i++)
            vet->baralho[i] = NULL;
	}

	i = vet->n;
	while(i>indice){
        vet->baralho[i] = vet->baralho[i-1];
        i--;
	}

	vet->baralho[indice] = c;
	vet->n++;
}

carta vetor_remove_carta(vetor_t *vet, int indice)
{
    carta retorna;
    retorna = vet->baralho[indice];
    int i;

    if(retorna == NULL)
        return NULL;

    for(i=indice; i<vet->n; i++)
        vet->baralho[i] = vet->baralho[i+1];

	vet->n--;
	vet->baralho[vet->n]= NULL;
	return retorna;
}

carta vetor_acessa_carta(vetor_t *vet, int indice)
{
	return vet->baralho[indice];
}

bool vetor_valido(vetor_t *vet)
{
	return true;
}

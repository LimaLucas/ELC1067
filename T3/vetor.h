#ifndef _VETOR_H_
#define _VETOR_H_
/*
 * vetor.h
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

#include <stdbool.h>

#include "carta.h"

/* definicao do tipo vetor */
typedef struct vetor vetor_t;

/* funções que permitem realizar operações sobre um vetor */

/* retorna um novo vetor, vazio */
vetor_t* vetor_cria(void);

/* destrói o vetor vet, que deverá estar vazio. */
void vetor_destroi(vetor_t* vet);

/* retorna o número de elementos no vetor vet. */
int vetor_numelem(vetor_t *vet);

/* insere uma carta no vetor vet, na posição indice.
 * se a carta já existe nessa posição, as cartas subsequentes avançam uma
 * posição.
 * se o vetor não tem mais espaço (cheio), utiliza realloc.
 */
void vetor_insere_carta(vetor_t *vet, int indice, carta c);

/* remove uma carta que estava na posição indice.
 * As cartas depois de indice recuam 1 posição à frente.
 * Retorna a carta original que estava na posição indice do vetor vet.
 */
carta vetor_remove_carta(vetor_t *vet, int indice);

/* retorna o dado na posição indice do vetor vet */
carta vetor_acessa_carta(vetor_t *vet, int indice);

/* retorna true se o vetor vet for válido */
bool vetor_valido(vetor_t *vet);

#endif

#ifndef _JOGO_H_
#define _JOGO_H_
/*
 * jogo.h
 * TAD que implementa o jogo de cartas "solitaire".
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

#include "carta.h"
#include "pilha.h"
#include "tela.h"

typedef struct {
    int magico;
    pilha monte;        // monte de cartas de onde se pode comprar
    pilha descartes;    // cartas ja abertas do monte; a de cima pode ser usada
    pilha ases[4];      // as 4 pilhas de cartas da saída
    pilha pilhas[7];    // as 7 pilhas principais do jogo
    tela tela;          // a tela onde sao desenhadas as cartas

    /* acrescente mais variáveis ao jogo, se necessário */
} jogo_t;
typedef jogo_t *jogo;

jogo jogo_cria(void);
void jogo_destroi(jogo);

bool jogo_valido(jogo sol);

/* acessores */
tela jogo_tela(jogo sol);
pilha jogo_monte(jogo sol);
pilha jogo_descartes(jogo sol);
pilha jogo_ases(jogo sol, int i);
pilha jogo_pilha(jogo sol, int i);

/* desenha a mesa do jogo */
void jogo_desenha(jogo);

/* acrescente mais funções ao jogo, se necessário */
#endif


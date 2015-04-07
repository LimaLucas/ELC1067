#ifndef _TELA_H_
#define _TELA_H_
/*
 * tela.h
 * Funções de tela com ncurses.
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

#include <ncurses.h>

typedef struct {
    int y;
    int x;
} posicao;

typedef struct {
    int larg;
    int alt;
} tamanho;

typedef struct {
    int magico;
    tamanho tam_tela; /* tamanho total da tela */
} tela_t;
typedef tela_t *tela;

typedef enum {
    preto = 1,
    vermelho,
    verde,
    azul
} cor;

tela tela_cria(void);
void tela_destroi(tela t);

/* limpa a tela */
void tela_limpa(tela t);

/* posiciona o cursor em pos */
void tela_posiciona(tela t, posicao pos);

/* muda a cor */
void tela_muda_cor(tela t, cor c);

/* escreve o texto str na posicao do cursor */
void tela_escreve(tela t, char *str);

/* escreve o texto no espaco de larg caracteres, na pos atual do cursor */
void tela_escreve_centralizado(tela t, char *str, int larg);
void tela_escreve_esquerdado(tela t, char *str, int larg);
void tela_escreve_direitado(tela t, char *str, int larg);

/* atualiza a tela com as ultimas alteracoes (faz aparecer os tela_escreve) */
void tela_atualiza(tela t);

/* retorna a proxima tecla pressionada (man getch para os valores de retorno)*/
int tela_le(tela t);

/* le uma linha de caracteres (max tam caracteres) */
void tela_lelinha(tela t, char *s, int tam);
#endif                          /* _TELA_H_ */

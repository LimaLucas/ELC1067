/*
 * tela.c
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

#include "tela.h"
#include "memo.h"

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define TELA_MAGICO 0x7E7A
#define DESTRUIDO 0x80000000

__attribute__ ((unused)) static void tela_resumo(void)
{
}

bool tela_valida(tela t)
{
    return t != NULL && t->magico == TELA_MAGICO;
}

static void tela_atualiza_tamanho(tela t)
{
    assert(tela_valida(t));
    getmaxyx(stdscr, t->tam_tela.alt, t->tam_tela.larg);
}

tela tela_cria(void)
{
    tela t;
    
    assert((t = (tela)memo_aloca(sizeof(tela_t))) != NULL);
    t->magico = TELA_MAGICO;

    initscr();
    start_color();
    init_pair(preto, COLOR_BLACK, COLOR_WHITE);
    init_pair(vermelho, COLOR_RED, COLOR_WHITE);
    init_pair(verde, COLOR_GREEN, COLOR_WHITE);
    init_pair(azul, COLOR_BLUE, COLOR_WHITE);
    attrset(COLOR_PAIR(preto));
    cbreak();
    noecho();
    nonl();
    keypad(stdscr, TRUE);

    tela_atualiza_tamanho(t);
    return t;
}


void tela_destroi(tela t)
{
    assert(tela_valida(t));
    clear();
    refresh();
    endwin();
    memo_libera(t);
}

void tela_limpa(tela t)
{
    assert(tela_valida(t));
    erase();
}

void tela_posiciona(tela t, posicao pos)
{
    assert(tela_valida(t));
    assert(pos.y < t->tam_tela.alt && pos.y >= 0);
    assert(pos.x < t->tam_tela.larg || pos.x >= 0);
    move(pos.y, pos.x);
}

void tela_muda_cor(tela t, cor c)
{
    assert(tela_valida(t));
    attrset(COLOR_PAIR(c));
}

void tela_escreve(tela t, char *str)
{
    assert(tela_valida(t));
    addstr(str);
}

static int limita_larg(tela t, int larg)
{
    int x, y, e;
    
    assert(tela_valida(t));
    getyx(stdscr, y, x);
    e = t->tam_tela.larg - x;
    if (e<0)e=1;
    if (larg > e) return e;
    return larg;
}

static void strfill(char *s, char c, int l)
{
    int i;
    for (i=0; i<l; i++) *s++ = c;
    *s = '\0';
}

static void strcp(char *s, char *o, int l)
{
    while (l-- && *o) *s++ = *o++;
}

void tela_escreve_limitado(tela t, char *str, int ini, int larg)
{
    char s[larg+1];
    int l;
    
    assert(tela_valida(t));
    strfill(s, ' ', larg);

    if (ini < 0) ini = 0;
    strcp(s + ini, str, larg - ini);

    l = limita_larg(t, larg);
    *(s+l) = '\0';
    tela_escreve(t, s);
}

void tela_escreve_centralizado(tela t, char *str, int larg)
{
    int l;

    l = larg - strlen(str);
    l = l / 2;
    
    tela_escreve_limitado(t, str, l, larg);
}

void tela_escreve_esquerdado(tela t, char *str, int larg)
{
    tela_escreve_limitado(t, str, 0, larg);
}

void tela_escreve_direitado(tela t, char *str, int larg)
{
    int l;

    l = larg - strlen(str);
    tela_escreve_limitado(t, str, l, larg);
}

void tela_atualiza(tela t)
{
    assert(tela_valida(t));
    refresh();
}

int tela_le(tela t)
{
    int ch;
    assert(tela_valida(t));
    ch = getch();
    if (ch == KEY_RESIZE) {
	tela_atualiza_tamanho(t);
    }
    return ch;
}

void tela_lelinha(tela t, char *s, int tam)
{
    int ch;

    nocbreak();
    echo();
    while((--tam > 0) && ((ch = getch()) != '\n')) {
        *s++ = ch;
    }
    *s++ = '\0';
    cbreak();
    noecho();
}

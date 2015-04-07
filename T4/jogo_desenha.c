/*
 * -------------------------------------------------------------------
 * jogo_desenha.c
 * -------------------------------------------------------------------
 * implementação de desenho do solitaire em tela textual
 */

#include "jogo.h"
#include "tela.h"
#include <assert.h>

void jogo_desenha_linhas(jogo sol, posicao pos, char *l[])
{
    char *s;
    int i;
    
    i = 0;
    s = l[i];
    while (s != NULL) {
        tela_posiciona(jogo_tela(sol), pos);
        tela_escreve(jogo_tela(sol), s);
        pos.y++;
        i++;
        s = l[i];
    }
}

void jogo_desenha_espaco(jogo sol, posicao pos)
{
    char *linhas[] = {
        ". . . .",
        ".     .",
        ".     .",
        ". . . .",
        NULL
    };
    tela_muda_cor(jogo_tela(sol), azul);
    jogo_desenha_linhas(sol, pos, linhas);
}

void jogo_desenha_carta(jogo sol, posicao pos, carta c)
{
    char *linhas_a[] = {
        "+-----+",
        "|10 P |",
        "|     |",
        "+-----+",
        NULL
    };
    char *linhas_f[] = {
        "+-----+",
        "|X+X+X|",
        "|+X+X+|",
        "+-----+",
        NULL
    };
    if (carta_aberta(c)) {
        char l[8];
        naipe n;
        n = carta_naipe(c);
        if (n == OUROS || n == COPAS) {
            tela_muda_cor(jogo_tela(sol), vermelho);
        } else {
            tela_muda_cor(jogo_tela(sol), preto);
        }
        sprintf(l, "|%2s %s |", carta_valor_str(c), carta_naipe_str(c));
        linhas_a[1] = l;
        jogo_desenha_linhas(sol, pos, linhas_a);
    } else {
        tela_muda_cor(jogo_tela(sol), azul);
        jogo_desenha_linhas(sol, pos, linhas_f);
    }
}

void jogo_desenha_topo(jogo sol, posicao pos, pilha p)
{
    if (pilha_vazia(p)) {
        jogo_desenha_espaco(sol, pos);
    } else {
        carta c;
        c = pilha_remove_carta(p);
        jogo_desenha_carta(sol, pos, c);
        pilha_insere_carta(p, c);
    }
}

void jogo_desenha_pilha(jogo sol, posicao pos, pilha p)
{
    if (pilha_vazia(p)) {
        jogo_desenha_espaco(sol, pos);
    } else {
        pilha aux;
        carta c;
        aux = pilha_cria();
        while (!pilha_vazia(p)) {
            c = pilha_remove_carta(p);
            pilha_insere_carta(aux, c);
        }
        while (!pilha_vazia(aux)) {
            c = pilha_remove_carta(aux);
            jogo_desenha_carta(sol, pos, c);
            pos.y += 2;
            pilha_insere_carta(p, c);
        }
        pilha_destroi(aux);
    }
}

void jogo_desenha(jogo sol)
{
    int i;
    posicao posmonte = { 1, 5 };
    posicao posdescartes = { 1, 15 };
    posicao posases[] = { { 1, 30 }, { 1, 40 }, { 1, 50 }, { 1, 60 } };
    posicao pospilha[] = { { 7,  5 }, { 7, 15 }, { 7, 25 }, { 7, 35 },
                           { 7, 45 }, { 7, 55 }, { 7, 65 } };

    assert(jogo_valido(sol));
    
    tela_limpa(jogo_tela(sol));
    
    jogo_desenha_topo(sol, posmonte, jogo_monte(sol));
    jogo_desenha_topo(sol, posdescartes, jogo_descartes(sol));
    for (i = 0; i < 4; i++) {
        jogo_desenha_topo(sol, posases[i], jogo_ases(sol, i));
    }
    for (i = 0; i < 7; i++) {
        jogo_desenha_pilha(sol, pospilha[i], jogo_pilha(sol, i));
    }
    
    tela_atualiza(jogo_tela(sol));
}

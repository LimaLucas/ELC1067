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

void jogo_desenha_indice_pilhas(jogo sol, posicao pos, char *str){
    tela_posiciona(jogo_tela(sol), pos);
    tela_muda_cor(jogo_tela(sol), preto);
    tela_escreve(jogo_tela(sol), str);
}

void jogo_desenha_menu(jogo sol, posicao pos, char *str){
    tela_posiciona(jogo_tela(sol), pos);
    tela_muda_cor(jogo_tela(sol), preto);
    tela_escreve(jogo_tela(sol), str);
}

void jogo_desenha_nome(jogo sol, posicao pos){
    char *nome[] = {
        "+-\\O/-+",
        "|--|--|",
        "|--|--|",
        "+-/ \\-+",
        NULL
    };
    tela_muda_cor(jogo_tela(sol), vermelho);
    jogo_desenha_linhas(sol, pos, nome);
}

void jogo_desenha(jogo sol)
{
    int i;
    posicao posmonte = { 8, 5 };
    posicao posdescartes = { 8, 15 };
    posicao posases[] = { { 8, 35 }, { 8, 45 }, { 8, 55 }, { 8, 65 } };
    posicao pospilha[] = { { 15,  5 }, { 15, 15 }, { 15, 25 }, { 15, 35 }, { 15, 45 }, { 15, 55 }, { 15, 65 } };

    posicao posIndice[] = { { 7, 5 }, { 7, 15 },
                            { 7, 35 }, { 7, 45 }, { 7, 55 }, { 7, 65 }, 
                            { 14, 5 }, { 14, 15 }, { 14, 25 }, { 14, 35 }, { 14, 45 }, { 14, 55 }, { 14, 65 } };
    
    posicao posMenuJogo[] = { { 1,  5 }, { 2,  5 }, { 3,  5 }, { 4,  5 }, { 5,  5 }, { 6,  5 } };
    //posicao posNomeJogo = { 7, 25 };

    assert(jogo_valido(sol));
    
    tela_limpa(jogo_tela(sol));
    
    for (i = 0; i < 4; i++) {
        jogo_desenha_menu(sol, posMenuJogo[i], jogo_menu(sol,i));
    }
    printw("\n");

    jogo_desenha_indice_pilhas(sol, posIndice[0], jogo_indice_pilhas(sol, 0));
    jogo_desenha_topo(sol, posmonte, jogo_monte(sol));
    
    jogo_desenha_indice_pilhas(sol, posIndice[1], jogo_indice_pilhas(sol, 1));
    jogo_desenha_topo(sol, posdescartes, jogo_descartes(sol));
    //jogo_desenha_nome(sol, posNomeJogo);

    
    for (i = 2; i < 6; i++) {
        jogo_desenha_indice_pilhas(sol, posIndice[i], jogo_indice_pilhas(sol, i));
    }
    for (i = 0; i < 4; i++) {
        jogo_desenha_topo(sol, posases[i], jogo_ases(sol, i));
    }

    for (i = 6; i < 13; i++){
        jogo_desenha_indice_pilhas(sol, posIndice[i], jogo_indice_pilhas(sol, i));
    }
    for (i = 0; i < 7; i++) {
        jogo_desenha_pilha(sol, pospilha[i], jogo_pilha(sol, i));
    }
    printw("\n");
    
    tela_atualiza(jogo_tela(sol));
}

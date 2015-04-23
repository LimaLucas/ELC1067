/*
 * tela.h
 * Funções de tela com Allegro 5.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. F. Lima, UFSM
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
#ifndef _TELA_H_
#define _TELA_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>

#include "geom.h"

/* estrutura que define uma tela */
typedef struct {
    ALLEGRO_DISPLAY *display; // display X 
    ALLEGRO_COLOR ac_fundo; // cor de fundo
    ALLEGRO_COLOR ac_cor; // cor padrao
    ALLEGRO_EVENT_QUEUE* queue; // fila de eventos
    ALLEGRO_FONT* fonte; // fonte padrao
    /* ALLEGRO_TIMER *timer;  // timer */
    retangulo_t janela; // retangulo que contem nossa janela
    tamanho_t tam;    // tamanho da janela
    ponto_t rato;     // onde esta o mouse
    bool botao;       // estado do botao do mouse
    int tecla;        // ultima tecla apertada
    int modif;        /* tecla modificadora da última apertada */
} tela_t;


// estrutura que representa uma cor, com os componentes
// vermelho, verde e azul podendo variar entre 0 e 1.
typedef struct {
    float r;
    float g;
    float b;
} cor_t;

/* inicializa a tela; deve ser chamada no inicio da execucao do programa */
void tela_inicializa(tela_t* tela, tamanho_t tam, char* nome);

/* finaliza a tela; deve ser chamado no final do programa */
void tela_finaliza(tela_t* tela);

/* limpa a tela toda */
void tela_limpa(tela_t* tela);

/* desenha uma linha do ponto p1 ao ponto p2 */
void tela_linha(tela_t* tela, ponto_t p1, ponto_t p2);

/* desenha um retangulo */
void tela_retangulo(tela_t* tela, retangulo_t r);

/* desenha um circulo */
void tela_circulo(tela_t* tela, circulo_t c);

/* faz aparecer na janela o que foi desenhado */
void tela_mostra(tela_t* tela);

/* muda a cor dos proximos desenhos de linha/retangulo/caracteres/etc */
void tela_cor(tela_t *tela, cor_t c);

/* calcula o numero de pixels (horizontais) necessarios a string s */
int tela_strlen(tela_t *tela, char *s);

/* escreve o texto s a partir da posicao p da tela */
void tela_texto(tela_t *tela, ponto_t p, char *s);

/* tamanho necessario para se escrever o texto s */
tamanho_t tela_tamanho_texto(tela_t *t, char *s);

/* retorna o codigo da proxima tecla apertada (ou 0, se nao tiver tecla alguma) */
int tela_tecla(tela_t *tela);

/* retorna um conjuto de bits (int) com o codigo das teclas modificadoras (ctrl,alt,etc)
 * apertadas junto com a tecla normal (ou 0, se nao tiver tecla alguma) */
int tela_tecla_modificador(tela_t *tela);

/* retorna a posicao do cursor do mouse */
ponto_t tela_rato(tela_t *tela);

/* retorna true se o botao do mouse estiver apertado */
bool tela_botao(tela_t *tela);

/* tempo de espera da tela, em microsegundos */
void tela_espera(double ms);

/* retorna a altura em pixels para a fonte usada */
int tela_altura_fonte(tela_t *tela);

/* Tamanho da tela. */
tamanho_t tela_tamanho(tela_t *tela);

#endif                          /* _TELA_H_ */

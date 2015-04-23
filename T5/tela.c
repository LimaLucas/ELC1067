/*
 * tela.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tela.h"

/* Tamanho da janela */
#define	LARGURA	600
#define ALTURA	400

/* Frame rate */
#define	  FPS	60

/* Conversao de unidades do usuario para coordenadas X e vice-versa */
/* Independentemente do tamanho da janela, dizemos que ela tem 80x24 */
//#define XU2X(x) ((short)(LARGURA * (x) / 80))
//#define YU2X(y) ((short)(ALTURA * (y) / 24))
//#define XX2U(x) ((float)(x) / LARGURA * 80)
//#define YX2U(y) ((float)(y) / ALTURA * 24)
/* cada 1 nas coordenadas do usuario corresponde a 10 pixels para o X */
//#define XU2X(x) ((short)((x)*10))
//#define YU2X(y) ((short)((y)*10))
//#define XX2U(x) ((float)(x)/10)
//#define YX2U(y) ((float)(y)/10)

#define XU2X(x) (x)
#define YU2X(y) (y)
#define XX2U(x) (x)
#define YX2U(y) (y)

/* Ajustar de acordo com o servidor X, para acertar as cores */
/* se o servidor X estiver em 16 bits, comentar a linha abaixo */
#define VINTE_E_QUATRO
#ifdef VINTE_E_QUATRO
#define B_R 8
#define B_G 8
#define B_B 8
#else
#define B_R 5
#define B_G 6
#define B_B 5
#endif

void tela_inicializa(tela_t* tela, tamanho_t tam, char* nome)
{
    /* inicializa dados sobre o mouse */
    tela->rato.x = 0;
    tela->rato.y = 0;
    tela->botao = false;

    tela->tecla = 0;
    tela->modif = 0;

    /* inicializa o allegro */
    if (!al_init()) {
	fprintf(stderr, "falha na inicializacao do allegro\n");
	exit(-1);
    }
    
    /* conecta com tela X */
    tela->display = al_create_display(tam.larg, tam.alt);
    if (tela->display == NULL) {
        fprintf(stderr, "falha ao criar display do allegro\n");
        exit(-1);
    }

    tela->janela.pos.x = 0;
    tela->janela.pos.y = 0;
    tela->janela.tam.larg = XX2U(tam.larg);
    tela->janela.tam.alt  = YX2U(tam.alt);
    tela->tam = tam;

    /* Titulo da tela */
    al_set_window_title(tela->display, nome);

    /* cria contextos grafico */
    tela->ac_fundo =  al_map_rgb(255, 255, 255);
    tela->ac_cor =  al_map_rgb(0, 0, 0);
    
    /* instala o driver de mouse e teclado */
    al_install_mouse();
    al_install_keyboard();
    al_init_primitives_addon();

    /* configura fonte */
    al_init_font_addon();
    al_init_image_addon();
    //tela->fonte = al_load_bitmap_font("data/a4_font.tga");
    tela->fonte = al_load_font("data/fixed_font.tga", 0, 0);
    if(!tela->fonte){
        fprintf(stderr, "Falha ao carregar fonte do allegro (arquivo %s)\n", "data/fixed_font.tga");
        exit(-1);
    }

    /* inicia o timer */
    /* tela->timer = al_create_timer(1.000 / FPS); */

    /* fila para eventos */
    tela->queue = al_create_event_queue();
    if (tela->queue == NULL) {
        fprintf(stderr, "falha ao buscar eventos do allegro\n");
        exit(-1);
    }

    /* registra para receber eventos de tela/teclado/mouse */
    al_register_event_source(tela->queue, al_get_keyboard_event_source());
    al_register_event_source(tela->queue, al_get_display_event_source(tela->display));
    al_register_event_source(tela->queue, al_get_mouse_event_source());
    //al_register_event_source(tela->queue, al_get_timer_event_source(tela->timer)); 
}

void tela_finaliza(tela_t* tela)
{
    /* o programa vai morrer, o fim da conexao com o servidor X fecha tudo */
    al_destroy_display(tela->display);
    al_destroy_event_queue(tela->queue);
}

void tela_limpa(tela_t* tela)
{
    /* preenche um retangulo do tamanho da tela com a cor de fundo */
    al_clear_to_color(tela->ac_fundo);
}

void tela_retangulo(tela_t* tela, retangulo_t r)
{
    /* preenche o retangulo r com a cor padrao */
    al_draw_filled_rectangle(
		      /* canto superior esquerdo */
		      XU2X(r.pos.x), YU2X(r.pos.y),
		      /* canto inferior direito */
		      XU2X(r.pos.x+r.tam.larg), YU2X(r.pos.y+r.tam.alt),
		      tela->ac_cor );
}

void tela_circulo(tela_t* tela, circulo_t c)
{
    /* preenche o circulo r na tela com a cor padrao */
    al_draw_filled_circle(XU2X(c.centro.x), YU2X(c.centro.y), XU2X(c.raio), tela->ac_cor);
}

void tela_linha(tela_t* tela, ponto_t p1, ponto_t p2)
{
    /* une os dois pontos com uma linha na cor padrao */
    al_draw_line(XU2X(p1.x), YU2X(p1.y), XU2X(p2.x), YU2X(p2.y), tela->ac_cor, 0.0);
}

void tela_mostra(tela_t* tela)
{
    /* Troca os buffers de video, passando o que foi desenhado para tela */
    al_flip_display();
}

#define AJEITA(x) (x < 0 ? 0 : (x > 1 ? 1 : x))
void tela_cor(tela_t *tela, cor_t c)
{
    /* altera a cor padrao */
    int R, G, B;
    R = AJEITA(c.r) * ((1<<B_R)-1);
    G = AJEITA(c.g) * ((1<<B_G)-1);
    B = AJEITA(c.b) * ((1<<B_B)-1);
    tela->ac_cor =  al_map_rgb(R, G, B);
}

int tela_strlen(tela_t *tela, char *s)
{
  return al_get_text_width(tela->fonte, s);
}

void tela_texto(tela_t *tela, ponto_t p, char *s)
{
    /* escreve o texto s na posicao p da tela */
    al_draw_text( tela->fonte, tela->ac_cor, XU2X(p.x), YU2X(p.y), ALLEGRO_ALIGN_LEFT, s);
}

void tela_processa_eventos(tela_t *tela)
{
    /* processa eventos do servidor X, atualizando a posicao do mouse
     * e ultima tecla pressionada na variavel da tela. */
    ALLEGRO_EVENT event;

    //al_wait_for_event(tela->queue, &event);
    while(al_get_next_event(tela->queue, &event)) {
      switch (event.type) {
	  /* tecla foi pressionada */
	  /*case ALLEGRO_EVENT_KEY_DOWN: */
	  case ALLEGRO_EVENT_KEY_CHAR:
	    {
#if 0
	      const char* keyname = al_keycode_to_name(event.keyboard.keycode);
	      printf("code %x modif %x char '%c' name '%s' (q=%d)\n", event.keyboard.keycode,
		event.keyboard.modifiers, (char)event.keyboard.keycode, keyname, 'Q');
#endif
		tela->tecla = event.keyboard.keycode;
		tela->modif = event.keyboard.modifiers;
		    break;
	    }
	   case ALLEGRO_EVENT_MOUSE_AXES:
	   {
	      tela->rato.x = XX2U(event.mouse.x);
	      tela->rato.y = YX2U(event.mouse.y);
	      break;
	   }
	   case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
	   {
	      if (event.mouse.button == 1)
		tela->botao = true;
	      break;
	   }
	   case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
	   {
	      if (event.mouse.button == 1)
		tela->botao = false;
	     break;
	   }
	   case ALLEGRO_EVENT_TIMER:
	   {
	     break;
	   }
#if 0
	  /* botao de fechar janela pressionado */
	  case ALLEGRO_EVENT_DISPLAY_CLOSE:
		  {
			  return;
			  break;
		  }
#endif
	  default:
		  break;
	}
    }
}

int tela_tecla(tela_t *tela)
{
    /* retorna a ultima tecla pressionada */
    int tecla;
    tela_processa_eventos(tela);
    tecla = tela->tecla;
    tela->tecla = 0;
    return tecla;
}

int tela_tecla_modificador(tela_t *tela)
{
    int modif;
    modif = tela->modif;
    tela->modif = 0;
    return modif;
}

ponto_t tela_rato(tela_t *tela)
{
    /* retorna a posicao do mouse */
    tela_processa_eventos(tela);
    return tela->rato;
}

bool tela_botao(tela_t *tela)
{
    /* retorna o estado do botao principal do mouse (true == pressionado) */
    tela_processa_eventos(tela);
    return tela->botao;
}

/* tempo de espera em microsegundos */
void tela_espera(double ms)
{
  al_rest(ms/1e3);
}

tamanho_t tela_tamanho_texto(tela_t *t, char *s)
{
    tamanho_t tam;
    int bbx, bby, bbw, bbh;
    al_get_text_dimensions(t->fonte, s, &bbx, &bby, &bbw, &bbh);
    tam.larg = bbw; 
    tam.alt = bbh;
    return tam;
}

tamanho_t tela_tamanho(tela_t *tela)
{
    return tela->tam;
}

int tela_altura_fonte(tela_t *tela)
{
	return al_get_font_line_height(tela->fonte);
}

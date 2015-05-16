/*
 * texto.c
 * Funções para implementação de editor de texto.
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
#include <assert.h>
#include <string.h>

#include "texto.h"
#include "tela.h"
#include "memo.h"
#include "lista.h"

/* estados para o campo texto */
enum { nada, editando } estado;

texto_t* texto_inicia(char* file_name)
{

	texto_t* t = (texto_t*)memo_aloca(sizeof(texto_t));
	tamanho_t tam = { 600, 400 };	/* tamanho da tela */
	
	tela_inicializa(&t->tela, tam, "Outro Editor");
	tela_limpa(&t->tela);

	t->nome = file_name;
	t->nlin = 0;
	t->lincur = 0;
	t->colcur = 0;
	t->lin1 = 0;
	t->col1 = 0;

	t->linhas = list_create();

	return t;
}

void texto_destroi(texto_t* txt)
{
	tela_limpa(&txt->tela);
	tela_finaliza(&txt->tela);

	while(txt->linhas->n > 0)
		txt->linhas = list_remove(txt->linhas, txt->linhas->n);
	list_destroy(txt->linhas);
	
	memo_libera(txt);
}

tela_t* texto_tela(texto_t* txt)
{
	assert( txt != NULL );
	return &txt->tela;
}

void texto_desenha_cursor_tela(texto_t *txt)
{
	cor_t preto = {0.0, 0.0, 0.0};
	tamanho_t tt;
	ponto_t pt1, pt2;

	{
		line* ln = list_search(txt->linhas->first, txt->lincur);
		char* texto =  ln->text;
		char subtexto[60];
		strncpy(subtexto, texto, txt->colcur*sizeof(char));
		subtexto[txt->colcur] = '\0';
		tt = tela_tamanho_texto(&txt->tela, subtexto);
	}
	/* posicao x (horizontal) do cursor */
	pt1.x = tt.larg + 1;
	/* posicao y (vertical) do cursor */
	pt1.y = txt->lincur * tt.alt;
	pt2.x = pt1.x;
	pt2.y = pt1.y + tt.alt;
	tela_cor(&txt->tela, preto);
	tela_linha(&txt->tela, pt1, pt2);
}

void texto_desenha_tela(texto_t *txt)
{
	cor_t cor;
	tamanho_t tt;
	ponto_t pt;
	int i;
	line* ln;

	cor.r = cor.g = cor.b = (float)0;
	
	/* limpa a tela. Comentar se ficar lento */
	tela_limpa(&txt->tela);
	
	for(i=1; i<=txt->nlin+1; i++){
		ln = list_search(txt->linhas->first, i-1);
		tt = tela_tamanho_texto(&txt->tela, ln->text);

		/* calcula posicao da nova linha */
		pt.x = 1;
		pt.y = (i - 1)*tt.alt + 1;

		/* muda cor e desenha linha */
		tela_cor(&txt->tela, cor);
		tela_texto(&txt->tela, pt, ln->text);
	}

	texto_desenha_cursor_tela(txt);
}

void texto_atualiza_tela(texto_t *txt)
{
	texto_desenha_tela(txt);
	tela_mostra(texto_tela(txt));
	tela_espera(30);
}

bool texto_processa_comandos(texto_t* txt)
{
	int tecla = tela_tecla(texto_tela(txt));
	int tecla_a = tela_tecla_a(texto_tela(txt));
	int modificador = tela_tecla_modificador(texto_tela(txt));
	/* Comandos para definir ações:
		ALLEGRO_EVENT_DISPLAY_CLOSE
		ALLEGRO_KEYMOD_CTRL && ALLEGRO_KEY_Q
		ALLEGRO_KEYMOD_CTRL && ALLEGRO_KEY_S 
		ALLEGRO_KEYMOD_CTRL && ALLEGRO_KEY_E
	*/
	if( tecla == ALLEGRO_EVENT_DISPLAY_CLOSE || tecla == 42 ){
		printf("DISPLAY CLOSE\n");
		return false;

	}else if( (modificador & ALLEGRO_KEYMOD_CTRL) && tecla_a == ALLEGRO_KEY_Q ) {
		printf("CTRL+Q = SAIR\n");
		return false;

	}else if( (modificador & ALLEGRO_KEYMOD_CTRL) && tecla_a == ALLEGRO_KEY_S ) {
		printf("CTRL+S = SALVAR e PARAR DE EDITAR\n");
		/* muda estado na variável para não editar */
		estado = nada;
		
		int i;
		FILE* file;
		file = fopen(txt->nome, "w+");
		
		for(i=0; i<=txt->linhas->n-1; i++){
			fprintf(file, "%s\n", list_search(txt->linhas->first, i)->text);
		}

		fclose(file);

	}else if( (modificador & ALLEGRO_KEYMOD_CTRL) && tecla_a == ALLEGRO_KEY_E ) {
		printf("CTRL+E = EDITAR\n");
		/* muda estado na variável para editando */
		estado = editando;
	}

	/* Teclas direcionais 
		ALLEGRO_KEY_LEFT
		ALLEGRO_KEY_RIGHT
		ALLEGRO_KEY_UP
		ALLEGRO_KEY_DOWN
		ALLEGRO_KEYMOD_CTRL && ALLEGRO_KEY_HOME
		ALLEGRO_KEY_HOME
		ALLEGRO_KEYMOD_CTRL && ALLEGRO_KEY_END
		ALLEGRO_KEY_END
	*/

	else if( (modificador & ALLEGRO_KEYMOD_CTRL) && tecla_a == ALLEGRO_KEY_HOME ){
		txt->colcur = 0;
		txt->lincur = 0;
	
	}else if( tecla_a == ALLEGRO_KEY_HOME )
		txt->colcur = 0;

	else if( (modificador & ALLEGRO_KEYMOD_CTRL) && tecla_a == ALLEGRO_KEY_END ){
		txt->lincur = txt->linhas->n-1;
		txt->colcur = strlen(list_search(txt->linhas->first, txt->lincur)->text);
	
	}else if( tecla_a == ALLEGRO_KEY_END )
		txt->colcur = strlen(list_search(txt->linhas->first, txt->lincur)->text);

	else if( tecla_a == ALLEGRO_KEY_LEFT )
		texto_move_esq(txt);

	else if( tecla_a == ALLEGRO_KEY_RIGHT )
		texto_move_dir(txt);

	else if( tecla_a == ALLEGRO_KEY_UP )
		texto_move_cima(txt);

	else if( tecla_a == ALLEGRO_KEY_DOWN )
		texto_move_baixo(txt);

	/* Teclas para a edição do arquivo: 
		ALLEGRO_KEY_ENTER
		ALLEGRO_KEY_BACKSPACE
		ALLEGRO_KEY_0 .. ALLEGRO_KEY_9
		ALLEGRO_KEY_A .. ALLEGRO_KEY_Z
		ALLEGRO_KEY_SPACE
	*/

	else if(estado == editando){
		if( tecla_a == ALLEGRO_KEY_ENTER ){
			texto_quebra_linha(txt);
		
		}else if( tecla_a == ALLEGRO_KEY_BACKSPACE || tecla_a == ALLEGRO_KEY_DELETE ){
			texto_remove_char(txt);
		
		}else if( tecla >= 1 ){
			if(tecla == 9){
				texto_insere_char(txt, ' ');
				texto_insere_char(txt, ' ');
				texto_insere_char(txt, ' ');
			}else{
				texto_insere_char(txt, tecla);
			}
		}
	}

	return true;
}

void texto_insere_char(texto_t *txt, char c)
{	
	line* ln;
	ln = list_search(txt->linhas->first, txt->lincur);

	int size_text;
	size_text = strlen(ln->text);

	if(size_text == 0){
		ln->text = memo_realoca(ln->text, size_text + sizeof(char));
		ln->text[0] = c;
		ln->text[1] = '\0';
		txt->colcur++;
	
	}else{
		int i;
		ln->text = memo_realoca(ln->text, size_text + sizeof(char));

		for(i = strlen(ln->text); i>txt->colcur; i--)
			ln->text[i] = ln->text[i-1];

		ln->text[i] = c;
		txt->colcur++;
	}
}

void texto_remove_char(texto_t *txt)
{	
	line* ln;
	ln = list_search(txt->linhas->first, txt->lincur);

	int size_text;
	size_text = strlen(ln->text);

	if(size_text == 0 && txt->lincur > 0){
		list_remove(txt->linhas, txt->lincur);
		txt->lincur--;
		txt->colcur = strlen(list_search(txt->linhas->first, txt->lincur)->text);
		txt->nlin--;
	
	}else if(txt->lincur > 0 && txt->colcur == 0 && size_text > 0){
		texto_gruda_linha(txt);
	
	}else if(txt->colcur == size_text && size_text > 0){
		ln->text[txt->colcur-1] = '\0';
		ln->text = memo_realoca(ln->text, sizeof(char));
		txt->colcur--;

	}else if(txt->colcur > 0){
		int i;

		for(i=txt->colcur-1; i<=size_text; i++)
			ln->text[i] = ln->text[i+1];

		ln->text = memo_realoca(ln->text, size_text - sizeof(char));
		txt->colcur--;
	}
}

void texto_gruda_linha(texto_t *txt)
{
	line *ln1, *ln2;
	ln1 = list_search(txt->linhas->first, txt->lincur-1);
	ln2 = list_search(txt->linhas->first, txt->lincur);
	
	int i, j, size_text;
	size_text = strlen(ln1->text) + strlen(ln2->text) * sizeof(char);
	
	txt->colcur = strlen(ln1->text);
	ln1->text = memo_realoca(ln1->text, size_text);

	for(i=strlen(ln1->text), j=0; i<=size_text; i++, j++)
		ln1->text[i] = ln2->text[j];

	list_remove(txt->linhas, txt->lincur);	
	
	txt->lincur--;
	txt->nlin--;

}

void texto_quebra_linha(texto_t *txt)
{
	line *ln1, *ln2;
	ln1 = list_search(txt->linhas->first, txt->lincur);
	
	int i, j, size_text;
	size_text = strlen(ln1->text);

	txt->linhas = list_insert(txt->linhas, txt->lincur+1);
	ln2 = list_search(txt->linhas->first, txt->lincur+1);

	if(txt->colcur != size_text){
		for(i=txt->colcur, j=0; i<=size_text; i++, j++){
			ln2->text = memo_realoca(ln2->text, strlen(ln2->text) + sizeof(char));
			ln2->text[j] = ln1->text[i];
		}

		ln1->text[txt->colcur] = '\0';
		ln1->text = memo_realoca(ln1->text, (txt->colcur+1) * sizeof(char));
	}

	txt->colcur = 0;
	txt->lincur++;
	txt->nlin++;
}

void texto_le_arquivo(texto_t *txt, char *nome, FILE *arq)
{
	char c;
	int i, j;
	line* ln;

	i = j = 0;

	c = fgetc(arq);

	while(feof(arq)==0){
		txt->linhas = list_insert(txt->linhas, i);
		ln = list_search(txt->linhas->first, i);

		do{
			ln->text = memo_realoca(ln->text, strlen(ln->text)+sizeof(char));
			ln->text[j] = c;
			j++;
			c = fgetc(arq);
		}while(c!='\n' && feof(arq)==0);
		ln->text[j] = '\0';
		j = 0;
		i++;
		c = fgetc(arq);
	}
	txt->nlin = txt->linhas->n;
}

void texto_move_esq(texto_t *txt)
{
	if(txt->colcur == 0 && txt->lincur > 0){
		txt->lincur--;
		txt->colcur = strlen(list_search(txt->linhas->first, txt->lincur)->text);
	}else if(txt->colcur > 0){
		txt->colcur--;
	}
}

void texto_move_dir(texto_t *txt)
{	
	int size_text = strlen(list_search(txt->linhas->first, txt->lincur)->text);
	if(txt->colcur == size_text && txt->lincur < txt->nlin){
		txt->lincur++;
		txt->colcur = 0;
	}else if(txt->colcur < size_text && txt->lincur <= txt->nlin){
		txt->colcur++;
	}
}

void texto_move_baixo(texto_t *txt)
{
	if(txt->lincur <= txt->nlin-1)
		txt->lincur++;
}

void texto_move_cima(texto_t *txt)
{
	if(txt->lincur > 0)
		txt->lincur--;
}

void texto_ajeita_tela(texto_t *txt){

}


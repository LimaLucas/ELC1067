/*
 * principal.c Esse programa testa as TADs implementadas para um jogo
 * solitário.
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM 2005       Benhur Stein, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * Créditos do código acima.
 * Com alterações realizadas pelo aluno Lucas Lima
 * de Oliveira para realização do trabalho T4, Solitaire, da matéria de 
 * Laboratório de Programação II
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

#include "memo.h"
#include "jogo.h"
#include "vetor.h"
#include "fila.h"
#include "carta.h"
#include "pilha.h"
#include "tela.h"

#define QTD 52
#define PILHAS 28

/* Inicia o jogo */
void inicia_jogo(jogo solit){

	vetor_t* cartas = vetor_cria();
	vetor_t*  fora_ordem = vetor_cria();
	int i, j;

	srand(time(NULL));

	for(i=0; i<4; i++)
		for(j=1; j<14; j++)
			vetor_insere_carta(cartas, (i*13)+j-1, carta_cria(j, i));

	for(i=0; i<QTD; i++){
		j = ((int)rand())%vetor_numelem(cartas);
		carta c = vetor_remove_carta(cartas, j);
		vetor_insere_carta(fora_ordem, i, c);
	}

	for(i=0; i<7; i++){
		carta c;

		for(j=0; j<=i; j++){
			c = vetor_remove_carta(fora_ordem, 0);
			pilha_insere_carta(jogo_pilha(solit, i), c);
		}
		carta_abre(c);
	}

	for(i=0; i<QTD-PILHAS; i++){
		carta c = vetor_remove_carta(fora_ordem, 0);
		pilha_insere_carta(jogo_monte(solit), c);
	}

	vetor_destroi(cartas);
	vetor_destroi(fora_ordem);
}

/* 
 * Abre uma carta do monte para o descarte e 
 * volta todas as cartas caso o monte esteja vazio 
 */
void abre_carta_monte(jogo solit){
	carta c;

	if(pilha_vazia(jogo_monte(solit))){
		while(!pilha_vazia(jogo_descartes(solit))){
			c = pilha_remove_carta(jogo_descartes(solit));
			carta_fecha(c);
			pilha_insere_carta(jogo_monte(solit), c);
		}
	}else{
		c = pilha_remove_carta(jogo_monte(solit));
		carta_abre(c);
		pilha_insere_carta(jogo_descartes(solit), c);

	}
	jogo_desenha(solit);
}

/* Passa a primeira carta do descarte para uma pilha de ases */
void passa_descarte_ases(jogo solit, int destino){

	carta comp, c = pilha_acessa_carta(jogo_descartes(solit));

	if(pilha_vazia(jogo_ases(solit, destino))){
		
		if(carta_valor(c) == 1){

			c = pilha_remove_carta(jogo_descartes(solit));
			pilha_insere_carta(jogo_ases(solit, destino), c);
			jogo_desenha(solit);

		}else tela_escreve_centralizado(jogo_tela(solit), "A pilha esta vazia e a carta não é um As!", 72);

	}else{
		comp = pilha_acessa_carta(jogo_ases(solit, destino));

		if(carta_naipe(c) == carta_naipe(comp) && carta_valor(c) == carta_valor(comp) +1){

			c = pilha_remove_carta(jogo_descartes(solit));
			pilha_insere_carta(jogo_ases(solit, destino), c);
			jogo_desenha(solit);

		}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não pode ser movida para este destino!", 72);
	}
}

/* Passa a primeira carte do descarte para um das pilhas */
void passa_descarte_pilhas(jogo solit, char destinoC){
	int destino = atoi(&destinoC)-1;
	carta comp, c = pilha_acessa_carta(jogo_descartes(solit));

	if(pilha_vazia(jogo_pilha(solit, destino))){
		
		if(carta_valor(c) == 13){

			c = pilha_remove_carta(jogo_descartes(solit));
			pilha_insere_carta(jogo_pilha(solit, destino), c);
			jogo_desenha(solit);

		}else tela_escreve_centralizado(jogo_tela(solit), "Apenas o Rei pode ser movido para um destino vazio!", 72);

	}else{

		comp = pilha_acessa_carta(jogo_pilha(solit, destino));

		if(carta_valor(c) +1 == carta_valor(comp)){

			switch(carta_naipe(comp)){
				case PAUS: case ESPADAS:
					if(carta_naipe(c) == COPAS || carta_naipe(c) == OUROS){

						c = pilha_remove_carta(jogo_descartes(solit));
						pilha_insere_carta(jogo_pilha(solit, destino), c);
						jogo_desenha(solit);

					}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui um naipe correto para este destino!", 72);
					break;

				case COPAS: case OUROS:
					if(carta_naipe(c) == PAUS || carta_naipe(c) == ESPADAS){

						c = pilha_remove_carta(jogo_descartes(solit));
						pilha_insere_carta(jogo_pilha(solit, destino), c);
						jogo_desenha(solit);

					}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui um naipe correto para este destino!", 72);
					break;
			}

		}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui o valor correto para este destino!", 72);
	}
}

/* Passa a ultima carta de uma das pilhas para uma das pilhas de ases */
void passa_carta_ases(jogo solit, int origem, int destino){

	carta comp, c = pilha_acessa_carta(jogo_pilha(solit, origem));

	if(pilha_vazia(jogo_ases(solit, destino))){
		
		if(carta_valor(c) == 1){

			c = pilha_remove_carta(jogo_pilha(solit, origem));
			pilha_insere_carta(jogo_ases(solit, destino), c);

			if(!pilha_vazia(jogo_pilha(solit, origem))){
				c = pilha_acessa_carta(jogo_pilha(solit, origem));
				carta_abre(c);
			}
			
			jogo_desenha(solit);

		}else tela_escreve_centralizado(jogo_tela(solit), "A pilha esta vazia e a carta não é um As!", 72);

	}else{
		comp = pilha_acessa_carta(jogo_ases(solit, destino));

		if(carta_naipe(c) == carta_naipe(comp) && carta_valor(c) == carta_valor(comp) +1){

			c = pilha_remove_carta(jogo_pilha(solit, origem));
			pilha_insere_carta(jogo_ases(solit, destino), c);

			if(!pilha_vazia(jogo_pilha(solit, origem))){
				c = pilha_acessa_carta(jogo_pilha(solit, origem));
				carta_abre(c);
			}

			jogo_desenha(solit);

		}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não pode ser movida para este destino!", 72);
	}
}

/* Passa a ultima carta de uma pilha para outra */
void passa_carta_pilhas(jogo solit, char origemC, char destinoC, char qtdeC){
	
	int origem = atoi(&origemC)-1, destino = atoi(&destinoC)-1, qtde = atoi(&qtdeC), verif = 0;
	carta comp, c = pilha_acessa_carta(jogo_pilha(solit, origem));
	pilha temp = pilha_cria();

	while(!pilha_vazia(jogo_pilha(solit, origem)) && carta_aberta(c) && verif<qtde){

		c = pilha_remove_carta(jogo_pilha(solit, origem));
		pilha_insere_carta(temp, c);
		c = pilha_acessa_carta(jogo_pilha(solit, origem));
		verif++;
	}

	if(verif != qtde){
		while(!pilha_vazia(temp)){
			c = pilha_remove_carta(temp);
			pilha_insere_carta(jogo_pilha(solit, origem), c);
			verif--;
		}
		tela_escreve_centralizado(jogo_tela(solit), "Não existem cartas suficientes nesta pilha para esta quantidade!", 72);

	}else{
		c = pilha_acessa_carta(temp);

		if(pilha_vazia(jogo_pilha(solit, destino))){
			
			if(carta_valor(c) == 13){
				
				while(!pilha_vazia(temp)){
					c = pilha_remove_carta(temp);
					pilha_insere_carta(jogo_pilha(solit, destino), c);
					verif--;
				}

				if(!pilha_vazia(jogo_pilha(solit, origem))){
					c = pilha_acessa_carta(jogo_pilha(solit, origem));
					carta_abre(c);
				}

				jogo_desenha(solit);

			}else{

				while(!pilha_vazia(temp)){
					c = pilha_remove_carta(temp);
					pilha_insere_carta(jogo_pilha(solit, origem), c);
					verif--;
				}
				tela_escreve_centralizado(jogo_tela(solit), "Apenas o Rei pode ser movido para um destino vazio!", 72);
			}

		}else{

			comp = pilha_acessa_carta(jogo_pilha(solit, destino));

			if(carta_valor(c) +1 == carta_valor(comp)){

				switch(carta_naipe(comp)){
					case PAUS: case ESPADAS:
						if(carta_naipe(c) == COPAS || carta_naipe(c) == OUROS){

							while(!pilha_vazia(temp)){
								c = pilha_remove_carta(temp);
								pilha_insere_carta(jogo_pilha(solit, destino), c);
								verif--;
							}

							if(!pilha_vazia(jogo_pilha(solit, origem))){
								c = pilha_acessa_carta(jogo_pilha(solit, origem));
								carta_abre(c);
							}

							jogo_desenha(solit);

						}else{
							while(!pilha_vazia(temp)){
								c = pilha_remove_carta(temp);
								pilha_insere_carta(jogo_pilha(solit, origem), c);
								verif--;
							}
							tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui um naipe correto para este destino (COPAS ou OUROS)! ", 72);
						}
						break;

					case COPAS: case OUROS:
						if(carta_naipe(c) == PAUS || carta_naipe(c) == ESPADAS){

							while(!pilha_vazia(temp)){
								c = pilha_remove_carta(temp);
								pilha_insere_carta(jogo_pilha(solit, destino), c);
								verif--;
							}

							if(!pilha_vazia(jogo_pilha(solit, origem))){
								c = pilha_acessa_carta(jogo_pilha(solit, origem));
								carta_abre(c);
							}

							jogo_desenha(solit);

						}else{
							while(!pilha_vazia(temp)){
								c = pilha_remove_carta(temp);
								pilha_insere_carta(jogo_pilha(solit, origem), c);
								verif--;
							}
							tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui um naipe correto para este destino (PAUS ou ESPADAS!", 72);
						}
						break;
				}

			}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui o valor correto para este destino!", 72);
		}
	}
	pilha_destroi(temp);
}

/* Passa a última carta de uma das pilhas de ases para uma pilha */
void passa_ases_pilha(jogo solit, int origem, char destinoC){

	int destino = atoi(&destinoC)-1;
	carta comp, c;

	if(!pilha_vazia(jogo_ases(solit, origem))){
		c = pilha_acessa_carta(jogo_ases(solit, origem));

		if(pilha_vazia(jogo_pilha(solit, destino))){
			
			if(carta_valor(c) == 13){

				c = pilha_remove_carta(jogo_ases(solit, origem));
				pilha_insere_carta(jogo_pilha(solit, destino), c);
				jogo_desenha(solit);

			}else tela_escreve_centralizado(jogo_tela(solit), "Apenas o Rei pode ser movido para um destino vazio!", 72);

		}else{
			comp = pilha_acessa_carta(jogo_pilha(solit, destino));

			if(carta_valor(c) +1 == carta_valor(comp)){
				switch(carta_naipe(comp)){
					case PAUS: case ESPADAS:
						if(carta_naipe(c) == COPAS || carta_naipe(c) == OUROS){

							c = pilha_remove_carta(jogo_ases(solit, origem));
							pilha_insere_carta(jogo_pilha(solit, destino), c);
							jogo_desenha(solit);

						}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui um naipe correto para este destino!", 72);
						break;

					case COPAS: case OUROS:
						if(carta_naipe(c) == PAUS || carta_naipe(c) == ESPADAS){

							c = pilha_remove_carta(jogo_ases(solit, origem));
							pilha_insere_carta(jogo_pilha(solit, destino), c);
							jogo_desenha(solit);

						}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui um naipe correto para este destino!", 72);
						break;
				}
			}else tela_escreve_centralizado(jogo_tela(solit), "Esta carta não possui o valor correto para este destino!", 72);
		}
	}else tela_escreve_centralizado(jogo_tela(solit), "Esta pilha de ases está vazia!", 72);
}

/* Verifica se o jogo chegou ao fim */
bool fim_jogo(jogo solit){
	int i, qtde = 0;

	for(i=0; i<4; i++)
		if(pilha_topo(jogo_ases(solit, i)) == 13)
			qtde++;

	return (qtde == 4);
}

/* Função main */
int main(int argc, char **argv){
	jogo solit;
	solit = jogo_cria();
	char cmd[3];

	inicia_jogo(solit);
	jogo_desenha(solit);

	do{

		cmd[0] = tela_le(jogo_tela(solit));
		
		/* ESC -> Sai do jogo; */
		if(cmd[0] == 27) break;

		switch(cmd[0]){
			/* ESPAÇO -> Abre carta do monte no descarte; */
			case ' ': case 13:	
				abre_carta_monte(solit);
				break;
			
			/* M -> Mover uma carta do descarte para uma pilha; */
			case 'M': case 'm':	
				cmd[0] = tela_le(jogo_tela(solit));

				switch(cmd[0]){
					case 'A': case 'a':
						passa_descarte_ases(solit, 0);
						break;
					case 'S': case 's':
						passa_descarte_ases(solit, 1);
						break;
					case 'D': case 'd':
						passa_descarte_ases(solit, 2);
						break;
					case 'F': case 'f':
						passa_descarte_ases(solit, 3);
						break;
					case '1': case '2': case '3': case '4': case '5': case '6': case '7':
						passa_descarte_pilhas(solit, cmd[0]);
						break;
					default:
						tela_escreve_centralizado(jogo_tela(solit), "Pilha de destino inexistente!", 72);
						break;
				}
				break;

			/* 1, 2, 3, 4, 5, 6, 7 -> Mover uma ou mais cartas de uma pilha para outra */
			case '1': case '2':	case '3': case '4': case '5': case '6': case '7':
				cmd[1] = tela_le(jogo_tela(solit));

				if(cmd[0] == cmd[1]){
					tela_escreve_centralizado(jogo_tela(solit), "O destino desta carta não pode ser igual sua origem!", 72);
					break;
				}
				
				switch(cmd[1]){
					case 'A': case 'a':
						passa_carta_ases(solit, atoi(&cmd[0])-1, 0);
						break;
					case 'S': case 's':
						passa_carta_ases(solit, atoi(&cmd[0])-1, 1);
						break;
					case 'D': case 'd':
						passa_carta_ases(solit, atoi(&cmd[0])-1, 2);
						break;
					case 'F': case 'f':
						passa_carta_ases(solit, atoi(&cmd[0])-1, 3);
						break;
					case '1': case '2': case '3': case '4': case '5': case '6': case '7':
						cmd[2] = tela_le(jogo_tela(solit));

						if(cmd[2]=='1' || cmd[2]=='2' || cmd[2]=='3' || cmd[2]=='4' || cmd[2]=='5' || cmd[2]=='6' || cmd[2]=='7' || cmd[2]=='8' || cmd[2]=='9'){
							passa_carta_pilhas(solit, cmd[0], cmd[1], cmd[2]);
						}else tela_escreve_centralizado(jogo_tela(solit), "Quantidade informada inválida!", 72);
						
						break;

					default:
						tela_escreve_centralizado(jogo_tela(solit), "Pilha de destino inexistente!", 72);
						break;
				}
				break;

			/* A, a, S, s, D, d, F, f -> Mover uma da pilha de ases para uma pilha */
			case 'A': case 'a': case 'S': case 's': case 'D': case 'd': case 'F': case 'f':
				cmd[1] = tela_le(jogo_tela(solit));


				if(cmd[1]=='1' || cmd[1]=='2' || cmd[1]=='3' || cmd[1]=='4' || cmd[1]=='5' || cmd[1]=='6' || cmd[1]=='7' || cmd[1]=='8' || cmd[1]=='9'){
					switch(cmd[0]){
						case 'A': case 'a':
							passa_ases_pilha(solit, 0, cmd[1]);
							break;
						case 'S': case 's':
							passa_ases_pilha(solit, 1, cmd[1]);
							break;
						case 'D': case 'd':
							passa_ases_pilha(solit, 2, cmd[1]);
							break;
						case 'F': case 'f':
							passa_ases_pilha(solit, 3, cmd[1]);
							break;
						default:
							tela_escreve_centralizado(jogo_tela(solit), "Pilha de origem inválida!", 72);
							break;
					}
				}else tela_escreve_centralizado(jogo_tela(solit), "Pilha de destino inválida!", 72);
				break;

			/* Caso não encontre nenhum comando válido, exibe mensagem de ERRO; */
			default:
				tela_escreve_centralizado(jogo_tela(solit), "Comando inexistente!", 72);
				break;
		}

	}while(!fim_jogo(solit));

	jogo_destroi(solit);

	/* relatório de memória */
	memo_relatorio();

	return 0;
}

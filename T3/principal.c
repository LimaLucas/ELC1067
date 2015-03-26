/*
 * principal.c
 * Esse programa testa as TADs implementadas.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
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
#include <time.h>
#include <stdbool.h>

/* Inclui definições de TADs. */
#include "vetor.h"
#include "carta.h"
#include "memo.h"

int main(int argc, char** argv)
{
	const int ncartas = 20;
	int i;
	vetor_t *baralho = NULL;
        carta c;

	/* semente para números aleatórios */
	srand(time(NULL));

	printf("0 - criando vetor\n");
	/* inicializa TAD vetor */
	baralho = vetor_cria();

	/* insere cartas */
	for(i= 0; i < ncartas; i++){
		/* cria uma carta de valor aleatório, naipe aleatório */
		c = carta_cria( (rand()%13)+1, (rand()%4) );
		vetor_insere_carta( baralho, i, c );
		printf("carta insere %d valor '%s' naipe '%s' (baralho com %d cartas)\n",
			i, carta_valor_str(c), carta_naipe_str(c), vetor_numelem(baralho));
	}

	/* testa inserir/remover ao abrir cartas */
	printf("1 - iniciando teste do vetor\n");
	for(i= 0; i < ncartas; i++){
		c = vetor_remove_carta( baralho, i );
		if(c == NULL){
			printf("ERRO ao remover carta (pos=%d)\n", i);
			exit(-1);
		}
		carta_abre(c);
		vetor_insere_carta( baralho, i, c);
		c = vetor_acessa_carta( baralho, i );
		/* se a carta não está aberta, erro! */
		if( carta_aberta(c)  == false )
			printf("ERRO: carta %d valor '%s' naipe '%s' não foi aberta\n",
				i, carta_valor_str(c), carta_naipe_str(c));
	}

	/* remove valores do baralho e libera */
	printf("2 - destruindo vetor\n");
	for(i= 0; i < ncartas; i++){
		/* retira sempre da primeira posição do vetor */
		c = vetor_remove_carta( baralho, 0 );
		if(c == NULL){
			printf("ERRO ao remover carta (pos=%d)\n", i);
			exit(-1);
		}
		printf("carta remove %d valor '%s' naipe '%s' (baralho com %d cartas)\n",
			i, carta_valor_str(c), carta_naipe_str(c), vetor_numelem(baralho) );
		carta_destroi(c);
	}
	vetor_destroi( baralho );

	/* relatório de memória */
	memo_relatorio();

	return 0;
}

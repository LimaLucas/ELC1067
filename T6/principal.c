/*
 * principal.c
 * Implementação de árvore de expressões aritméticas.
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

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "arv.h"
#include "pilha.h"
#include "memo.h"

int main(int argc, char **argv)
{
	arv_t *noh, *elem;
	pilha_t *pilha;
	op_t op;
	int num;
	char c;

	pilha = pilha_cria();

	c = getchar(); 
	while(c != '=' && c != '\n'){
		if(((c >= '0' && c <= '9') || (c >= 'a' || c <= 'z')) && c != ' '){
			
			num = atoi(&c);
			
			op.tipo = OPERANDO;
			op.u.operando = num;
			
			elem = arv_cria(op);
			pilha = pilha_insere(pilha, elem);

		}else if((c == '+' || c == '-' || c == '*' || c == '/') && c != ' '){
			
			op.tipo = OPERADOR;
			op.u.operador = c;
			
			elem = arv_cria(op);
			
			noh = pilha->arv;
			noh = arv_insere_esquerda(noh, elem);
			pilha = pilha_remove(pilha);

			noh = pilha->arv;
			noh = arv_insere_direita(noh, elem);
			pilha = pilha_remove(pilha);

			pilha = pilha_insere(pilha, elem);

		}

		c = getchar();

	}

	printf("\nExpressão pré-ordem: ");
	arv_imprime_pre_ordem(noh);

	printf("\nExpressão em ordem: ");
	arv_imprime_em_ordem(noh);

	printf("\nExpressão pós-ordem: ");
	arv_imprime_pos_ordem(noh);

	arv_destroi(noh);
	arv_destroi(elem);
	pilha_destroi(pilha);

	memo_relatorio();
	return 0;
}

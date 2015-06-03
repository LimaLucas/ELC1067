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
	arv_t arvore, arv;
	pilha_t pilha;
	op_t op;
	double num;
	char c;

	pilha = pilha_cria();

	c = getchar();
	while(c != '=' || c != '\n'){
		if(((c >= '0' && c <= '9') || (c >= 'a' || c <= 'z')) && c != ' '){
			
			num = atof(c);
			
			op.tipo = OPERANDO;
			op.u.operando = num;
			
			arv = arv_cria(op);
			pilha_insere(pilha, op);

		}else if((c == '+' || c == '-' || c == '*' c == '/') && c != ' '){
			
			op.tipo = OPERADOR;
			op.u.operador = c;
			
			arv = arv_cria(op);
			
			
			pilha_insere(pilha, op);

		}
	}

	printf("\nExpressão pré-ordem: ");
	arv_imprime_pre_ordem(arvore);

	printf("\nExpressão em ordem: ");
	arv_imprime_em_ordem(arvore);

	printf("\nExpressão pós-ordem: ");
	arv_imprime_pos_ordem(arvore);

	memo_relatorio();
	return 0;
}

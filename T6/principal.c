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
	/* exemplo simples de árvore */
	arv_t* raiz;
	op_t soma, n1, n2;
	pilha_t* pilha;

	/* inicia expressão */
	/* operador + */
	soma.tipo = OPERADOR;
	soma.u.operador = '+';
	/* primeiro operando */
	n1.tipo = OPERANDO;
	n1.u.operando = 1.0;
	/* segundo operando */
	n2.tipo = OPERANDO;
	n2.u.operando = 2.0;

	/* cria uma árvore */
	raiz = arv_cria( soma );
	raiz = arv_insere_esquerda( raiz, n1 );
	raiz = arv_insere_direita( raiz, n2 );

	/* simples uso da pilha */
	pilha = pilha_cria();
	pilha_insere( pilha, raiz );
	pilha_destroi( pilha );

	/* destroi árvore */
	arv_destroi( raiz );

	return 0;
}

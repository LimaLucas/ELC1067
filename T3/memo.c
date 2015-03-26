/*
 * memo.c
 * Funções para alocação de memória.
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

#include <stdio.h> // printf
#include <stdlib.h> // malloc/realloc/free

static long _memo_aloc = 0;
static long _memo_free = 0;
static size_t _memo_aloc_bytes = 0;
static size_t _memo_realoc_bytes = 0;

void* memo_aloca( size_t tam )
{
	void *p = malloc( tam );
	if(p == NULL){
		printf("ERRO: não consegui alocar memória.\n");
		exit(-1);
	}
	_memo_aloc++;
	_memo_aloc_bytes += tam;
	return p;
}

void* memo_realoca( void* ptr, size_t tam )
{
	void* p = realloc( ptr, tam );
	if(p == NULL){
		printf("ERRO: não consegui realocar memória.\n");
		exit(-1);
	}
	_memo_realoc_bytes += tam;
	return p;
}

void memo_libera( void* ptr )
{
	if(ptr == NULL){
		printf("ERRO: ponteiro nulo!\n");
		exit(-1);
	}
	free(ptr);
	_memo_free++;
}

void memo_relatorio( void )
{
	printf("\n** RELATÓRIO DE ALOCAÇÕES DE MEMÓRIA **\n");
	printf(" * Alocações  : %ld (total de %lu bytes)\n", _memo_aloc, _memo_aloc_bytes );
	printf(" * Liberações : %ld\n", _memo_free ); 
	printf(" * Realocações: %lu bytes\n", _memo_realoc_bytes );
	printf(" * SALDO      : %ld (alocações menos liberações)\n", _memo_aloc-_memo_free );
	printf("\n");
}


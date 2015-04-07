/*
 * carta.c
 * TAD que implementa o tipo de dados carta, que representa uma carta
 * de baralho.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 *               2005       Benhur Stein, UFSM
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

#include "carta.h"
#include "memo.h"

struct _carta {
	valor v;
	naipe t;
	bool aberta;
};

/* retorna uma nova carta, criado a partir do valor v e naipe n.
 * a carta será criada fechada.
 * Se v ou n forem inválidos, retorna NULL.
 */
carta carta_cria(valor v, naipe n)
{
	struct _carta* c = (struct _carta*)memo_aloca(sizeof(struct _carta));
	c->v = v;
	c->t = n;
	c->aberta = false;
	return c;
}

/* destrói a carta c */
void carta_destroi(carta c)
{
	memo_libera(c);
}

/* retorna o valor da carta c. */
valor carta_valor(carta c)
{
	return c->v;
}
char *carta_valor_str(carta c)
{
	static char* cartas[14] = {
		"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "V", "D", "R"
	};
	return cartas[(int)carta_valor(c)];
}

/* retorna o naipe da carta c. */
naipe carta_naipe(carta c)
{
	return c->t;
}
char *carta_naipe_str(carta c)
{
	static char* naipes[4] = {
		    "P",
		    "E",
		    "C",
		    "O"
	};
	return naipes[carta_naipe(c)];
}

/* abre a carta c */
void carta_abre(carta c)
{
	c->aberta= true;
}

/* fecha a carta c */
void carta_fecha(carta c)
{
	c->aberta= false;
}

/* retorna true se a carta c estiver aberta. */
bool carta_aberta(carta c)
{
	return c->aberta;
}

/* retorna true se c for uma carta válida */
bool carta_valida(carta c)
{
	return true;
}

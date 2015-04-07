#ifndef _CARTA_H_
#define _CARTA_H_
/*
 * carta.h
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
 
#include <stdlib.h> // para NULL
#include <stdbool.h> // para bool

/* definicao do tipo carta */
typedef struct _carta* carta;

typedef enum {
    PAUS,
    ESPADAS,
    COPAS,
    OUROS
} naipe;

typedef enum {
    AS = 1,
    VALETE = 11,
    DAMA,
    REI
} valor;

/* funções que permitem realizar operações sobre uma carta */

/* retorna uma nova carta, criado a partir do valor v e naipe n.
 * a carta será criada fechada.
 * Se v ou n forem inválidos, retorna NULL.
 */
carta carta_cria(valor v, naipe n);

/* destrói a carta c */
void carta_destroi(carta c);

/* retorna o valor da carta c. */
valor carta_valor(carta c);
char *carta_valor_str(carta c);

/* retorna o naipe da carta c. */
naipe carta_naipe(carta c);
char *carta_naipe_str(carta c);

/* abre a carta c */
void carta_abre(carta c);

/* fecha a carta c */
void carta_fecha(carta c);

/* retorna true se a carta c estiver aberta. */
bool carta_aberta(carta c);

/* retorna true se c for uma carta válida */
bool carta_valida(carta c);

#endif

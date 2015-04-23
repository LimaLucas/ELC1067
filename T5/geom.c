/*
 * geom.c
 * Funções geométricas para TADs ponto, retangulo, e círculo.
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

#include "geom.h"
#include <math.h>

// Funções

// retorna a distancia entre dois pontos
float distancia(ponto_t a, ponto_t b)
{
    return 0;
}

// retorna true se o ponto estiver dentro do circulo, false caso contrario
bool ptemcirc(ponto_t p, circulo_t c)
{
    return false;
}

// retorna true se o ponto estiver dentro do retangulo
bool ptemret(ponto_t a, retangulo_t r)
{
    return false;
}

// retorna true se houver uma interseccao entre o circulo e o retangulo
bool intercr(circulo_t c, retangulo_t r)
{
    return false;
}

// retorna true se houver uma interseccao entre os dois retangulos
bool interrr(retangulo_t r1, retangulo_t r2)
{
    return false;
}

// retorna true se houver uma interseccao entre os dois circulos
bool intercc(circulo_t c1, circulo_t c2)
{
    return false;
}


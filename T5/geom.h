/*
 * geom.h
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

// As duas linhas seguintes, e a ultima do arquivo, servem para que este arquivo nao seja
// incluido mais de uma vez
#ifndef GEOM_H
#define GEOM_H

// geom.h
// ------
// declaracoes de tipos de dados e funcoes para manipulacao de formas
// geometricas simples (ponto, retangulo, circulo)

#include <stdbool.h>

// Tipos de dados

// Um ponto, constituído por uma coordenada no eixo x e no eixo y
typedef struct {
    float x;
    float y;
} ponto_t;

// tamanho_t, constituído por altura e largura, do tipo float
typedef struct {
    float larg;
    float alt;
} tamanho_t;

// retangulo_t, constituído por um ponto (que contém as coordenadas do canto 
//              inferior esquerdo do retangulo) e um tamanho
typedef struct {
    ponto_t pos;
    tamanho_t tam;
} retangulo_t;

// circulo_t, constituido por um ponto (o centro do circulo) e um float (o raio)
typedef struct {
    ponto_t centro;
    float raio;
} circulo_t;


// Funções

// retorna a distancia entre dois pontos
float distancia(ponto_t p1, ponto_t p2);

// retorna true se o ponto estiver dentro do circulo, false caso contrario
bool ptemcirc(ponto_t p, circulo_t c);

// retorna true se o ponto estiver dentro do retangulo
bool ptemret(ponto_t p, retangulo_t r);

// retorna true se houver uma interseccao entre o circulo e o retangulo
bool intercr(circulo_t c, retangulo_t r);

// retorna true se houver uma interseccao entre os dois retangulos
bool interrr(retangulo_t r1, retangulo_t r2);

// retorna true se houver uma interseccao entre os dois circulos
bool intercc(circulo_t c1, circulo_t c2);

#endif // fim da protecao contra inclusoes multiplas

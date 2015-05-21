T6 - Árvore de expressões aritméticas.
ENTREGA: 02/06/2015 pelo GitHub (crie pasta T6 com os fontes)

* DESCRIÇÃO
Implemente um programa que tem como entrada uma expressão pós-fixa 
e representa ela usando uma árvore binária. Após ler a expressão,
o programa deve imprimir a mesma expressão usando as ordens:
1 - pré-ordem (raiz, esquerda, e direita)
2 - em-ordem (esquerda, raiz, direita)
3 - pós-ordem (esquerda, direia, raiz)

Uma expressão aritmética in-fixa é a notação convencional, onde um operador
aparece entre dois operandos. Parênteses são necessários para especificar a
ordem das operações. Por exemplo:
((x * x) + 2)/(x + 1)

Enquanto quem expressões pós-fixa (ou notação Polonesa) elimina o uso de parênteses.
Nela o operador é escrito depois dos operandos. Os parênteses não são necessários.
Por exemplo:
x x * 2 + x 1 + /

A construção da árvore deve fazer uso de uma pilha para empilhar operandos das
expressões aritméticas. Para facilitar a implementação, a pilha deve armazenar
nós da árvore. O algoritmo de construção da árvore funciona da seguinte forma:
Lê próximo operador ou operando.
Se operando
	cria um nó operando e empilha.
Se operador
	desempilha os 2 operandos da pilha.
	cria um nó operador e insere na esquerda e direita os operandos.
	empilha o nó operador.

Nessa etapa, será necessário apenas imprimir nas ordens requisitadas. Não é
necessário resolver a expressão. 

As estruturas de árvore e pilha, assim como um exemplo de uso, estão no GitHub
pasta "T6". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

* ENTREGA
Na data da entrega, a pasta T6 deverá estar presente no GitHub.

* DICAS
- teste seu programa!
- separe cada comando em funções diferentes.
- se achar necessário, faça alterações em outros arquivos além do principal.c
- use o valgrind para evitar erros de memória.

* REGRAS
- Avaliação: nota de 0 até 10.
- Respeite o formato no repositório Git.
- Caso o repositório Git não tenha histórico, nota será próxima do zero.
- Atrasos tem desconto, a critério do professor.
- Plágio implica em nota zero.


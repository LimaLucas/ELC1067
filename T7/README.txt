T7 - Resolução de uma árvore de expressões aritméticas.
ENTREGA: 11/06/2015 pelo GitHub (crie pasta T7 com os fontes)

* DESCRIÇÃO
Baseado no trabalho anterior (T6), modifique o programa para imprimir na tela o
resultado da expressão aritmética. A entrada do programa será a mesma, uma
expressão aritmética pós-fixa (ou notação Polonesa).

Relembre que expressões pós-fixa (ou notação Polonesa) elimina o uso de parênteses.
Nela o operador é escrito depois dos operandos. Os parênteses não são necessários.
Por exemplo:
x x * 2 + x 1 + /

A construção da árvore continua semelhante ao descrito no T6.

Para calcular o resultado da expressão aritmética, basta percorrer a árvore
pós-ordem (esquerda, direita, raiz) sempre que o nó atual for um operador.
O algoritmo recursivo é o seguinte:
double calcula(arv_t* arv)
    se arv é operando
      retorna o valor de arv que é um double
    senão (arv é um operador)
      valor1 = chama calcula(arv->esq) para o valor da esquerda
      valor2 = chama calcula(arv->dir) para o valor da direita
      retorna o valor do operador de arv (+-/*) com operandos valor1 e valor2

Esta descrição está no GitHub pasta "T7". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

* ENTREGA
Na data da entrega, a pasta T7 deverá estar presente no GitHub.

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


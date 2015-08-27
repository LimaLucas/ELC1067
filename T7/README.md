#T7 - Resolução de uma árvore de expressões aritméticas.
ENTREGA: 11/06/2015 pelo GitHub (crie pasta T7 com os fontes)<br>
<br>
* DESCRIÇÃO<br>
Baseado no trabalho anterior (T6), modifique o programa para imprimir na tela o
resultado da expressão aritmética. A entrada do programa será a mesma, uma
expressão aritmética pós-fixa (ou notação Polonesa).<br>

Relembre que expressões pós-fixa (ou notação Polonesa) elimina o uso de parênteses.<br>
Nela o operador é escrito depois dos operandos. Os parênteses não são necessários.<br>
Por exemplo:<br>
x x * 2 + x 1 + /<br>
<br>
A construção da árvore continua semelhante ao descrito no T6.<br>
<br>
Para calcular o resultado da expressão aritmética, basta percorrer a árvore
pós-ordem (esquerda, direita, raiz) sempre que o nó atual for um operador.<br>
O algoritmo recursivo é o seguinte:<br>
<code>
double calcula(arv_t* arv)</br>
	se arv é operando
		retorna o valor de arv que é um double
	senão (arv é um operador)
		valor1 = chama calcula(arv->esq) para o valor da esquerda
		valor2 = chama calcula(arv->dir) para o valor da direita
		retorna o valor do operador de arv (+-/*) com operandos valor1 e valor2

<br>
Esta descrição está no GitHub pasta "T7". Para clonar:<br>
git clone https://github.com/joao-lima/elc1067-2015-1.git<br>
<br>
* ENTREGA<br>
Na data da entrega, a pasta T7 deverá estar presente no GitHub.<br>
<br>
* DICAS<br>
- teste seu programa!<br>
- separe cada comando em funções diferentes.<br>
- se achar necessário, faça alterações em outros arquivos além do principal.c<br>
- use o valgrind para evitar erros de memória.<br>
<br>
* REGRAS<br>
- Avaliação: nota de 0 até 10.<br>
- Respeite o formato no repositório Git.<br>
- Caso o repositório Git não tenha histórico, nota será próxima do zero.<br>
- Atrasos tem desconto, a critério do professor.<br>
- Plágio implica em nota zero.<br>
<br>

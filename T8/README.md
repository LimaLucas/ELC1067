#T8 - Grafo com listas de adjacência
ENTREGA: 23/06/2015 pelo GitHub (crie pasta T8 com os fontes)<br>
<br>
* DESCRIÇÃO<br>
Este trabalho consiste em ler um arquivo texto (formato abaixo) e implementar
um grafo não-direcionado com listas de adjacência. Ao final, o programa deverá
imprimir o grafo com vértices e arestas.<br>

A entrada inicia com o número de vértices e arestas na primeira linha, seguido
dos vértices (identificador e nome em cada linha) e das arestas (um par de
identificador de vértices por linha).<br>
Um exemplo de entrada segue abaixo:<br>
8 9<br>
SMA Santa Maria<br>
POA Porto Alegre<br>
SC  Santa Cruz<br>
CH  Cidade Hipotetica<br>
CH1 Outra Cidade<br>
PF  Passo Fundo<br>
CS  Caxias do Sul<br>
FS Faxinal do Soturno<br>
SMA POA <br>
SMA SC <br>
POA SC <br>
SC CH1<br>
SC PF<br>
CH1 PF<br>
CH1 CS<br>
PF FS<br>
CS FS<br>
<br>
A saída do programa deverá ter em cada linha um vértice e suas arestas no
formato abaixo (a ordem não é importante):<br>
SMA -> POA CH<br>
POA -> SMA SC<br>
SC -> POA CH1 PF<br>
CH -> SMA<br>
CH1 -> SC PF CS<br>
PF -> SC CH1 FS<br>
CS -> CH1 FS<br>
FS -> PF CS <br>
<br>
As funções que devem ser implementadas estão no GitHub pasta "T8". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git<br>
<br>
O tipo grafo está em grafo.h, e vértice em vertice.h. Algumas funções que devem
ser implementadas nesse trabalho (descrição em grafo.h do Git):<br>
grafo_t* grafo_cria(void);<br>
bool grafo_insere_vertice(grafo_t* g, vertice_t* v);<br>
vertice_t* grafo_busca_vertice(grafo_t* g, char* chave);<br>
bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2);<br>
void grafo_imprime(grafo_t* g);<br>
void grafo_destroi(grafo_t* g);<br>
<br>
* MATERIAL DE APOIO SOBRE GRAFOS<br>
http://www2.dcc.ufmg.br/livros/algoritmos/cap7/slides/c/completo1/cap7.pdf<br>
http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-16-greedy-algorithms-minimum-spanning-trees/lec16.pdf<br>
<br>
* ENTREGA<br>
Na data da entrega, a pasta T8 deverá estar presente no GitHub.<br>
<br>
* DICAS<br>
- teste seu programa!<br>
- separe cada comando em funções diferentes.<br>
- se achar necessário, faça alterações em outros arquivos além do principal.c<br>
- use o valgrind para evitar erros de memória.<br>
<br>
* REGRAS<br>
- Avaliação: nota de 0 até 10.
- Respeite o formato no repositório Git.
- Caso o repositório Git não tenha histórico, nota será próxima do zero.
- Atrasos tem desconto, a critério do professor.
- Plágio implica em nota zero.<br>
<br>

T8 - Grafo com listas de adjacência
ENTREGA: 23/06/2015 pelo GitHub (crie pasta T8 com os fontes)

* DESCRIÇÃO
Este trabalho consiste em ler um arquivo texto (formato abaixo) e implementar
um grafo não-direcionado com listas de adjacência. Ao final, o programa deverá
imprimir o grafo com vértices e arestas.

A entrada inicia com o número de vértices e arestas na primeira linha, seguido
dos vértices (identificador e nome em cada linha) e das arestas (um par de
identificador de vértices por linha).
Um exemplo de entrada segue abaixo:
8 9
SMA Santa Maria
POA Porto Alegre
SC  Santa Cruz
CH  Cidade Hipotetica
CH1 Outra Cidade
PF  Passo Fundo
CS  Caxias do Sul
FS Faxinal do Soturno
SMA POA 
SMA SC 
POA SC 
SC CH1
SC PF
CH1 PF
CH1 CS
PF FS
CS FS

A saída do programa deverá ter em cada linha um vértice e suas arestas no
formato abaixo (a ordem não é importante):
SMA -> POA CH
POA -> SMA SC
SC -> POA CH1 PF
CH -> SMA
CH1 -> SC PF CS
PF -> SC CH1 FS
CS -> CH1 FS
FS -> PF CS 

As funções que devem ser implementadas estão no GitHub pasta "T8". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

O tipo grafo está em grafo.h, e vértice em vertice.h. Algumas funções que devem
ser implementadas nesse trabalho (descrição em grafo.h do Git):
```C
grafo_t* grafo_cria(void);
bool grafo_insere_vertice(grafo_t* g, vertice_t* v);
vertice_t* grafo_busca_vertice(grafo_t* g, char* chave);
bool grafo_insere_aresta(grafo_t* g, char* v1, char* v2);
void grafo_imprime(grafo_t* g);
void grafo_destroi(grafo_t* g);
```
* MATERIAL DE APOIO SOBRE GRAFOS
http://www2.dcc.ufmg.br/livros/algoritmos/cap7/slides/c/completo1/cap7.pdf
http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-16-greedy-algorithms-minimum-spanning-trees/lec16.pdf

* ENTREGA
Na data da entrega, a pasta T8 deverá estar presente no GitHub.

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

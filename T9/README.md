#T9 - Caminho mais curto em grafos não-direcionados
ENTREGA: 02/07/2015 pelo GitHub (crie pasta T9 com os fontes)<br>
<br>
* DESCRIÇÃO<br>
Este trabalho consiste na implementação de um algoritmo que busca o caminho
mais curto entre dois vértices de um grafo não direcionado.  A partir do
trabalho anterior (T8), o algoritmo utilizará um grafo com listas de
adjacência. O cálculo do menor caminho pode ser obtido por meio da BUSCA EM
LARGURA (ver algoritmo abaixo).<br>

O programa deve receber na linha de comando (prompt do Linux) o nome do arquivo
de entrada, o vértice de origem e o vértice de destino. Por exemplo:
$ ./principal grafo.txt POA FS<br>

Onde:<br>
- grafo.txt é o arquivo de entrada (argv[1])<br>
- POA é o vértice de origem (argv[2])<br>
- FS é o vértice de destino (argv[3])<br>
<br>
O formato do arquivo de entrada é o mesmo do T8.  No exemplo abaixo:<br>
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
A saída será:<br>
Porto Alegre -> Santa Cruz -> Passo Fundo -> Faxinal do Soturno<br>
<br>
Esta descrição e o arquivo de entrada estão no GitHub pasta "T9". Para clonar:<br>
git clone https://github.com/joao-lima/elc1067-2015-1.git<br>
<br>
* ALGORITMO DE BUSCA EM LARGURA<br>
Um esboço do algoritmo de busca em largura (breadth-first search ou BFS) é
mostrado abaixo:<br>
// recebe o grafo G e o vertice de fonte s<br>
<p>
.grafo_busca_largura(grafo_t* G, vertice_t* s){<br>
...fila_t* Q;<br>
...inicializa todos vertices do grafo G com cor BRANCO;<br>
...Q = fila_cria();<br>
...Q = fila_insere(Q, s);   // insere a fonte no final da fila<br>
...while(fila_vazia(Q) == false){<br>
.......u = fila_remove(Q);  // remove o primeiro da fila<br>
.......for( cada vertice adjacente v de u ) {<br>
..........if(v->cor == BRANCO){<br>
..............v->cor = CINZA;  // marca como descoberto<br>
..............v->d = u->d + 1; // distancia do antecessor para este vertice<br>
..............v->ant = u;      // antecessor do vertice v<br>
..............Q = fila_insere(Q, v);<br>
..........}<br>
.......}<br>
.......u->cor = PRETO; // visitou vertices adjacentes<br>
...}<br>
.}<br>
<br></p>
Nesse algoritmo, é necessário também um tipo fila_t que implementa uma
estrutura de fila FIFO (First-in First-out), ou seja, insere no final da fila
e remove do começo (ou vice-versa).<br>
Note que o tipo vertice_t tem três novos campos: cor, distância e anterior. Um
exemplo da nova estrutura está disponível no GitHub pasta "T9".<br>
<br>
Para imprimir o caminho mais curto use o algoritmo abaixo:<br>
// recebe o grafo, o vertice de fonte 's' e destino 'v'<br>
<p>
.grafo_caminho_curto(grafo_t* G, char* fonte, char* destino){<br>
...vertice_t* s = grafo_busca_vertice(G, fonte);<br>
...vertice_t* v = grafo_busca_vertice(G, destino);<br>
...if(s == v){<br>
......printf("%s ", s->nome);<br>
......return;<br>
...}<br>
...if(v->ant == NULL){<br>
......printf("Nao existe caminho de %s a %s\n", s->nome, v->nome);<br>
...} else {<br>
......grafo_caminho_curto( G, fonte, v->ant->chave );<br>
......printf("%s ", v->nome);<br>
...}<br>
.}<br></p>
<br>
* MATERIAL DE APOIO SOBRE GRAFOS<br>
http://www2.dcc.ufmg.br/livros/algoritmos/cap7/slides/c/completo1/cap7.pdf
http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-16-greedy-algorithms-minimum-spanning-trees/lec16.pdf<br>
<br>
* ENTREGA<br>
Na data da entrega, a pasta T9 deverá estar presente no GitHub.<br>
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


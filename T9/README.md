#T9 - Caminho mais curto em grafos não-direcionados
ENTREGA: 02/07/2015 pelo GitHub (crie pasta T9 com os fontes)

* DESCRIÇÃO
Este trabalho consiste na implementação de um algoritmo que busca o caminho
mais curto entre dois vértices de um grafo não direcionado.  A partir do
trabalho anterior (T8), o algoritmo utilizará um grafo com listas de
adjacência. O cálculo do menor caminho pode ser obtido por meio da BUSCA EM
LARGURA (ver algoritmo abaixo).

O programa deve receber na linha de comando (prompt do Linux) o nome do arquivo
de entrada, o vértice de origem e o vértice de destino. Por exemplo:
$ ./principal grafo.txt POA FS

Onde:
- grafo.txt é o arquivo de entrada (argv[1])
- POA é o vértice de origem (argv[2])
- FS é o vértice de destino (argv[3])

O formato do arquivo de entrada é o mesmo do T8.  No exemplo abaixo:
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

A saída será:
Porto Alegre -> Santa Cruz -> Passo Fundo -> Faxinal do Soturno

Esta descrição e o arquivo de entrada estão no GitHub pasta "T9". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

* ALGORITMO DE BUSCA EM LARGURA
Um esboço do algoritmo de busca em largura (breadth-first search ou BFS) é
mostrado abaixo:
// recebe o grafo G e o vertice de fonte s
grafo_busca_largura(grafo_t* G, vertice_t* s){
  fila_t* Q;
  inicializa todos vertices do grafo G com cor BRANCO;
  Q = fila_cria();
  Q = fila_insere(Q, s);   // insere a fonte no final da fila
  while(fila_vazia(Q) == false){
      u = fila_remove(Q);  // remove o primeiro da fila
      for( cada vertice adjacente v de u ) {
	  if(v->cor == BRANCO){
	      v->cor = CINZA;  // marca como descoberto
	      v->d = u->d + 1; // distancia do antecessor para este vertice
	      v->ant = u;      // antecessor do vertice v
	      Q = fila_insere(Q, v);
	  }
      }
      u->cor = PRETO; // visitou vertices adjacentes
  }
}

Nesse algoritmo, é necessário também um tipo fila_t que implementa uma
estrutura de fila FIFO (First-in First-out), ou seja, insere no final da fila
e remove do começo (ou vice-versa).
Note que o tipo vertice_t tem três novos campos: cor, distância e anterior. Um
exemplo da nova estrutura está disponível no GitHub pasta "T9".

Para imprimir o caminho mais curto use o algoritmo abaixo:
// recebe o grafo, o vertice de fonte 's' e destino 'v'
grafo_caminho_curto(grafo_t* G, char* fonte, char* destino){
  vertice_t* s = grafo_busca_vertice(G, fonte);
  vertice_t* v = grafo_busca_vertice(G, destino);
  if(s == v){
    printf("%s ", s->nome);
    return;
  }
  if(v->ant == NULL){
    printf("Nao existe caminho de %s a %s\n", s->nome, v->nome);
  } else {
    grafo_caminho_curto( G, fonte, v->ant->chave );
    printf("%s ", v->nome);
  }
}

* MATERIAL DE APOIO SOBRE GRAFOS
http://www2.dcc.ufmg.br/livros/algoritmos/cap7/slides/c/completo1/cap7.pdf
http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-16-greedy-algorithms-minimum-spanning-trees/lec16.pdf

* ENTREGA
Na data da entrega, a pasta T9 deverá estar presente no GitHub.

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


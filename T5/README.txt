T5 - Editor de texto gráfico com lista duplamente encadeada
ENTREGA: 14/05/2015 pelo GitHub (crie pasta T5 com os fontes)

* DESCRIÇÃO
Faça um editor de textos gráfico com lista duplamente encadeada.
(Veja exemplo na pasta T5 do GitHub descrito abaixo)

Os comandos básicos são:
- CTRL+q: sair do editor.
- CTRL+e: entrar em modo edição.
- CTRL+s: gravar arquivo e sair do modo edição.
Outros comandos podem ser adicionados.

O texto é representado em memória por uma estrutura declarada como segue (texto.h):
typedef struct {
	char *nome;     /* nome do arquivo sendo editado */
	lista_t* linhas; /* lista de linhas do arquivo */
	int nlin;       /* numero de linhas no texto (numero de elementos atualmente em linhas) */
	int lincur;     /* linha onde esta o cursor (comeca em 0) */
	int colcur;     /* coluna onde esta o cursoe na linha acima */
	int lin1;       /* linha do texto mostrada na primeira linha da tela */
	int col1;       /* coluna do texto mostrada na primeira coluna da tela */
	
	tela_t tela;    /* tela do editor */
} texto_t;

A estrutura lista_t deverá ser uma lista duplamente encadeada com funções
definidas pelo aluno.

* FUNÇÕES A IMPLEMENTAR (NO MÍNIMO)

-> texto_t* texto_inicia(void);
-> void texto_destroi(texto_t* txt);
Essas duas funções devem ser completadas para refletir a versão final. O editor
sempre inicia em estado de não edição.

-> void texto_desenha_tela(texto_t *txt);
Desenha toda a tela. A primeira linha a ser desenhada é lin1. A primeira coluna
a ser desenhada em cada linha é col1. Deve ser completada baseada no exemplo
dado.
IMPORTANTE: cuidado com o desenho do cursor, pois caracteres tem diferentes
tamanhos em pixels.

-> void texto_atualiza_tela(texto_t *txt);
Função pronta, modificar se achar necessário.

-> bool texto_processa_comandos(texto_t* txt);
Lê comandos do teclado e executa funções de acordo. Possui exemplos
de comandos esperados. Implementar uma função por comando.

-> void texto_le_arquivo(texto_t *txt, char *nome);
Inicializa a estrutura apontada por txt com o conteúdo do arquivo chamado nome.
Deve ler cada linha do arquivo, alocar memória suficiente para essa linha (sem
o '\n' final e com um '\0'), copiar o conteúdo da linha para essa memória
alocada e adicionar a memória alocada na lista duplamente encadeada de linhas.
A função deve ainda inicializar os demais campos da estrutura apontada por txt.

-> void texto_move_esq(texto_t *txt);
-> void texto_move_dir(texto_t *txt);
-> void texto_move_baixo(texto_t *txt);
-> void texto_move_cima(texto_t *txt);
Devem ser completadas nos exemplos dados.  Move a posição do cursor na direção
indicada pelo nome da função. Para a esquerda, para cima e para baixo, não deve
sair dos limites do texto. Para a direita, não há limite. Editor pode estar em
modo edição.

-> void texto_insere_char(texto_t *txt, char c);
Insere o caractere c na posição do cursor. Deve alocar uma nova região de
memória grande o suficiente para conter a linha após a inserção, e copiar o
conteúdo da linha antiga, alterada com a inserção do caractere novo. Caso a
linha do cursor seja mais curta que a posição do cursor, devem ser inseridos
espaços no final da linha, para que o caractere inserido fique na posição
correta. A memória ocupada pela linha antiga deve ser liberada e o ponteiro da
linha na lista  alterado para apontar para a nova região de memória com a
nova versão da linha. Após a inserção, o cursor deve ser movido uma coluna à
direita (usar a função acima). Editor deve estar em modo edição.

-> void texto_remove_char(texto_t *txt);
Remove o caractere na posição do cursor no texto apontado por txt. Como na
inserção, deve alocar uma nova área de memória para conter a nova versão da
linha. Caso o cursor esteja além do final da linha, a função não deve fazer
nada. A posição do cursor não deve ser alterada. Editor deve estar em modo
edição.

-> void texto_ajeita_tela(texto_t *txt);
Se necessário, deve alterar a primeira coluna e/ou linha do texto mostrado na
tela (variáveis lin1 e col1), para garantir que a posição do cursor seja
mostrada quando a tela for desenhada (a linha do cursor não pode ser menor que
a primeira linha na tela (lin1) nem maior que a última linha na tela (lin1 +
altura da tela - 1); idem para coluna).

-> void texto_gruda_linha(texto_t *txt);
Se o cursor não estiver na última linha do texto, anexa a linha seguinte à do
cursor ao final da linha do cursor, e remove a linha abaixo do cursor da lista.
Editor não pode estar em modo edição.

-> void texto_quebra_linha(texto_t *txt);
Quebra a linha do cursor na posição do cursor. A linha com o cursor terminará
com o caractere logo antes do cursor, e a linha seguinte conterá os caracteres
a partir da posição do cursor. Se o cursor estiver além do final da linha, a
linha do cursor permanece inalterada e é inserida uma linha vazia após o
cursor. Deve ser realocada a memória para a linha do cursor (se ela mudar) e
liberada a memória antiga, alocada memória para a nova linha, inserida a nova linha
na lista de linhas. Editor não pode estar em modo edição.

IMPORTANTE: todas as alocações e liberações de memória devem usar as funções do
arquivo memo.h.

Todos os arquivos do trabalho estão no GitHub pasta "T5". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

A compilação do trabalho envolve diversos arquivos. É necessário instalar a biblioteca
allegro versão 5 para gráficos. Em um sistema Ubuntu digite:
sudo apt-get install liballegro5-dev

No Windows, procure nos seguintes sites:
https://wiki.allegro.cc/index.php?title=Windows,_Code::Blocks_and_Allegro_5
https://wiki.allegro.cc/index.php?title=Getting_Started

Quem utiliza Codeblocks, adicione ao projeto todos os arquivos. Quem utilizar
um sistema Linux pode compilar com o programa make digitando:
make

Link sobre valgrind: http://valgrind.org/docs/manual/quick-start.html
Link sobre allegro: http://alleg.sourceforge.net/

* ENTREGA
Na data da entrega, a pasta T5 deverá estar presente no GitHub.

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


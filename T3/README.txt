T3 - TAD 
ENTREGA: 31/03/2015 pelo GitHub (crie pasta T3 com os fontes)

* DESCRIÇÃO
Este trabalho consiste na implementação da estrutura de dados TAD vetor_t que
armazena cartas de um baralho.
O trabalho consiste em terminar de implementar as funções descritas no 
arquivo vetor.c, que é utilizado em principal.c. O principal.c
testa as funções da TAD vetor inserindo ou removendo cartas.
Portanto, MODIFIQUE o vetor.c e NÃO altere principal.c.
O que deve ser alterado:
- vetor.c
O que não deve ser alterado:
- o resto.

Todos os arquivos do trabalho estão no GitHub pasta "T3". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

As funções são:
vetor_t* vetor_cria(void);
void vetor_destroi(vetor_t* vet);
int vetor_numelem(vetor_t *vet);
void vetor_insere_carta(vetor_t *vet, int indice, carta c);
carta vetor_remove_carta(vetor_t *vet, int indice);
carta vetor_acessa_carta(vetor_t *vet, int indice);
bool vetor_valido(vetor_t *vet);

A descrição de cada uma das funções está em vetor.h.
Todos os arquivos .h descrevem os protótipos de funções, enquanto que 
a implementação dessas funções está nos arquivos .c.

A compilação do trabalho envolve diversos arquivos. Quem utiliza Codeblocks,
adicione ao projeto todos os arquivos. Quem utilizar um sistema Linux pode
compilar com o programa make digitando:
make

Ou na linha de comando manualmente com:
gcc -Wall -g -o principal memo.c carta.c vetor.c principal.c -lm

IMPORTANTE:
O vetor deverá utilizar alocação dinâmica por meio das funções fornecidas em
memo.h que são:
void* memo_aloca( size_t tam );
void* memo_realoca( void* ptr, size_t tam );
void memo_libera( void* ptr );

Utilize as funções da mesma forma como com malloc e free. Ao final do programa
utilize a função:
void memo_relatorio( void );

Como no arquivo principal.c, para imprimir o número de alocações e liberações
efetuadas pelo programa.

* AVALIAÇÃO
A avaliação será conforme:
- bom funcionamento do programa.
- sem acessos ilegais de memória (segmentation fault ou falha de segmentação).
- toda memória alocada deve ser liberada.

O programa valgrind será utilizado na avaliação. Ele fornece um relatório de
uso de memória.  Para ver o relatório, execute seu trabalho com:
$ valgrind ./t3

Link sobre valgrind: http://valgrind.org/docs/manual/quick-start.html

* ENTREGA
Na data da entrega, a pasta T3 deverá estar presente no GitHub.

* DICAS
- teste seu programa!
- use vetores dinâmicos.
- use o valgrind para evitar erros.
- não deverá existir limite de linhas.

* REGRAS
- Avaliação: nota de 0 até 10.
- Respeite o formato no repositório Git.
- Caso o repositório Git não tenha histórico, nota será próxima do zero.
- Atrasos tem desconto, a critério do professor.
- Plágio implica em nota zero.


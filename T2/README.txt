T2 - ALOCAÇÃO DINÂMICA
ENTREGA: 24/03/2015 pelo GitHub (crie pasta T2 com os fontes)

* DESCRIÇÃO
A lógica deste trabalho é igual ao T1. O programa fará leitura de dois
arquivos texto: alunos.txt e notas.txt. Ele busca alunos pelo nome e imprime a
média e o nome completo dos encontrados.
IMPORTANTE: a ordem das matriculas pode não ser a mesma.

Porém, neste T2, os vetores estáticos de T1 serão dinâmicos.  Ou seja, ao invés
de um vetor de matriculas de tamanho 50 como abaixo:
int matriculas[50];

O vetor deve ser alocado dinâmicamente. Um exemplo que inicia com 50 posições:
int *matriculas;
matriculas = (int*) malloc( 50 * sizeof(int) );

Ao final do programa o vetor deve ser liberado com:
free(matriculas);

IMPORTANTE: testar se o número de linhas foi maior que o alocado anteriormente.
Caso mais de 50 linhas (por exemplo) forem lidas, precisamos de mais espaço.
Isso é possível por meio da função realloc:
matriculas = (int*) realloc( matriculas, 100 * sizeof(int) );

O exemplo aumenta o vetor de 50 para 100 posições. A função realloc recebe o
vetor antigo e retorna um novo vetor maior. O conteúdo antigo é copiado para o
novo vetor.

* AVALIAÇÃO
A avaliação será conforme:
- bom funcionamento do programa.
- sem acessos ilegais de memória (segmentation fault ou falha de segmentação).
- toda memória alocada deve ser liberada.

O programa valgrind será utilizado na avaliação. Ele fornece um relatório de
uso de memória.  Para ver o relatório, execute seu trabalho com:
$ valgrind ./t2

Link sobre valgrind: http://valgrind.org/docs/manual/quick-start.html

* ENTREGA
Na data da entrega, a pasta T2 deverá estar presente no GitHub.

* DICAS
- teste seu programa!
- cuide para abrir e fechar os arquivos utilizados.
- use vetores dinâmicos.
- use o valgrind para evitar erros.
- não deverá existir limite de linhas.

* REGRAS
- Avaliação: nota de 0 até 10.
- Respeite o formato no repositório Git.
- Caso o repositório Git não tenha histórico, nota será próxima do zero.
- Atrasos tem desconto, a critério do professor.
- Plágio implica em nota zero.

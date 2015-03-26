T2 - ALOCA��O DIN�MICA
ENTREGA: 24/03/2015 pelo GitHub (crie pasta T2 com os fontes)

* DESCRI��O
A l�gica deste trabalho � igual ao T1. O programa far� leitura de dois
arquivos texto: alunos.txt e notas.txt. Ele busca alunos pelo nome e imprime a
m�dia e o nome completo dos encontrados.
IMPORTANTE: a ordem das matriculas pode n�o ser a mesma.

Por�m, neste T2, os vetores est�ticos de T1 ser�o din�micos.  Ou seja, ao inv�s
de um vetor de matriculas de tamanho 50 como abaixo:
int matriculas[50];

O vetor deve ser alocado din�micamente. Um exemplo que inicia com 50 posi��es:
int *matriculas;
matriculas = (int*) malloc( 50 * sizeof(int) );

Ao final do programa o vetor deve ser liberado com:
free(matriculas);

IMPORTANTE: testar se o n�mero de linhas foi maior que o alocado anteriormente.
Caso mais de 50 linhas (por exemplo) forem lidas, precisamos de mais espa�o.
Isso � poss�vel por meio da fun��o realloc:
matriculas = (int*) realloc( matriculas, 100 * sizeof(int) );

O exemplo aumenta o vetor de 50 para 100 posi��es. A fun��o realloc recebe o
vetor antigo e retorna um novo vetor maior. O conte�do antigo � copiado para o
novo vetor.

* AVALIA��O
A avalia��o ser� conforme:
- bom funcionamento do programa.
- sem acessos ilegais de mem�ria (segmentation fault ou falha de segmenta��o).
- toda mem�ria alocada deve ser liberada.

O programa valgrind ser� utilizado na avalia��o. Ele fornece um relat�rio de
uso de mem�ria.  Para ver o relat�rio, execute seu trabalho com:
$ valgrind ./t2

Link sobre valgrind: http://valgrind.org/docs/manual/quick-start.html

* ENTREGA
Na data da entrega, a pasta T2 dever� estar presente no GitHub.

* DICAS
- teste seu programa!
- cuide para abrir e fechar os arquivos utilizados.
- use vetores din�micos.
- use o valgrind para evitar erros.
- n�o dever� existir limite de linhas.

* REGRAS
- Avalia��o: nota de 0 at� 10.
- Respeite o formato no reposit�rio Git.
- Caso o reposit�rio Git n�o tenha hist�rico, nota ser� pr�xima do zero.
- Atrasos tem desconto, a crit�rio do professor.
- Pl�gio implica em nota zero.

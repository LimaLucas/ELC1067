T4 - Solitaire
ENTREGA: 16/04/2015 pelo GitHub (crie pasta T4 com os fontes)

* DESCRIÇÃO
Completar o jogo de cartas "solitaire" com a biblioteca ncurses.
(Veja exemplo na pasta T4 do GitHub descrito abaixo)

Inicialmente, o jogo deve conter 1 carta aberta na primeira pilha, uma fechada
e uma aberta na segunda, duas fechadas e uma aberta na terceira, etc. O
restante das cartas, fechadas, devem estar no monte. As demais pilhas
(descartes e ases) devem estar vazias.
A cada jogada, o jogador pode:
- abrir uma carta do monte sobre o descarte
- virar todas as cartas do descarte no monte vazio
- mover uma carta aberta (dos descartes ou de alguma pilha) para uma das
  pilhas ases (deve ser do mesmo naipe e com valor imediatamente superior ao
  da carta que já se encontra nessa pilha de ases, ou ser um as colocado em
  uma pilha vazia)
- mover todas as cartas abertas de uma das 7 pilhas para outra.
- mover a carta no topo dos descartes para uma das 7 pilhas.
- terminar o jogo.

Uma carta só pode ser movida sobre outra em uma das pilhas se for de naipe
diferente e valor imediatamente inferior.

IMPORTANTE: Deve existir pelo menos uma função para cada jogada possível.
Algumas jogadas precisam de argumentos, outras não.
O programa deve ter um ciclo principal onde:
1) lê comando (um comando pode ser 1, 2 ou 3 caracteres).
2) interpreta e executa comando, chamando a função correspondente.
3) redesenha a tela.

Todos os arquivos do trabalho estão no GitHub pasta "T4". Para clonar:
git clone https://github.com/joao-lima/elc1067-2015-1.git

Você deve copiar os arquivos que faltam (vetor.h e vetor.c) do T3 para o T4. 

A compilação do trabalho envolve diversos arquivos. É necessário instalar a biblioteca
ncurses para gráficos em terminal. Em um sistema Ubuntu digite:
sudo apt-get install libncurses5-dev
No Windows, procure nos seguintes sites:
Link para ncurses no Windows: http://pdcurses.sourceforge.net/
Link para ncurses com Codeblocks: http://www.cplusplus.com/forum/windows/16002/

Quem utiliza Codeblocks, adicione ao projeto todos os arquivos. Quem utilizar
um sistema Linux pode compilar com o programa make digitando:
make

Ou na linha de comando manualmente com:

gcc -o solitaire -Wall -g principal.c vetor.c carta.c memo.c fila.c pilha.c jogo.c jogo_desenha.c tela.c -lcurses

Link sobre valgrind: http://valgrind.org/docs/manual/quick-start.html
Link sobre ncurses: http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/

* ENTREGA
Na data da entrega, a pasta T4 deverá estar presente no GitHub.

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


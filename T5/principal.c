/*
 * principal.c
 * Implementação de editor de texto gráfico.
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "texto.h"
#include "memo.h"

int main(int argc, char **argv)
{
	texto_t* texto;
	texto = texto_inicia(argv[1]);
	
	/* enquanto continua execução */
	while(texto_processa_comandos(texto) == true) {
		texto_atualiza_tela(texto);
	}
	texto_destroi(texto);
	memo_relatorio();

	return 0;
}

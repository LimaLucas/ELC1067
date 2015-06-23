#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"

int main(int argc, char **argv)
{

	if(argc == 1){
 		printf("Insira o nome do arquivo!\n");
 		return 0;
 	}else if(argc > 2){
 		printf("Insira apenas o nome de um arquivo!\n");
 		return 0;
 	}

 	FILE *file = fopen(argv[1], "r");
 	if(file == NULL){
 		printf("Erro ao abrir o arquivo! Tente novamente.\n");
 		return 0;
 	}

 	int nVert, nAres, i;
 	fscanf(file, "%d %d\n", &nVert, &nAres);

 	grafo_t G;
 	G = grafo_cria();

 	for(i=0; i<nVert; i++){


 	}

 	for(i=0; i<nAres; i++){


 	}

 	grafo_destroi(G);

	memo_relatorio();
	return 0;
}

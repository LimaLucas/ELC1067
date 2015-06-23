#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"

#define TAM1 3	// Tamanho da chave/sigla do vértice
#define TAM2 60	// Tamanho do nome do vértice

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

 	char sigla[TAM1]; desc[TAM2];

 	grafo_t G;
 	G = grafo_cria();

 	vertice_t* V;

 	for(i=0; i<nVert; i++){
		if(fscanf(file, "%s %s\n", sigla, desc) != 2)		// VERIFICAR: leitura da string
			break;

		else{
 			V = (vertice_t*) memo_aloca(sizeof(vertice_t));
 			
 			V->chave = (char*) memo_aloca(sizeof(char)*TAM1);
 			V->nome = (char*) memo_aloca(sizeof(char)*TAM2);
 			V->adjacentes = NULL;

 			V->chave = sigla;
 			V->nome = desc;

 			// F: insere vertice
		}
 	}

 	for(i=0; i<nAres; i++){
 		fscanf(file, "%s %s\n", sigla, desc);				// VERIFICAR: leitura da string
 		if(!grafo_insere_aresta(G, sigla, desc))
 			break;
 	}

 	if(!feof(file))
 		printf("Arquivo com formatação incorreta!\n");
 	else
 		grafo_imprime(G);
 		

 	fclose(file);
 	grafo_destroi(G);

	memo_relatorio();
	return 0;
}

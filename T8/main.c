#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "vertice.h"
#include "lista.h"
#include "memo.h"
#include "grafo.h"

#define TAM1 4	// Tamanho da chave/sigla do vértice
#define TAM2 60	// Tamanho do nome do vértice

int main(int argc, char **argv)
{

	if(argc == 1){
 		printf("Insira o nome do arquivo!\n\a");
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

 	char sigla[TAM1], desc[TAM2], aresta[TAM1];

 	grafo_t* G;
 	G = grafo_cria();

 	for(i=0; i<nVert; i++){
		if(fscanf(file, "%s %[^\n]s\n", sigla, desc) != 2)
			break;

		else{
 			
 			vertice_t* V = vertice_cria(TAM1, TAM2);
 			strcpy(V->chave, sigla);
 			strcpy(V->nome, desc);

 			if(!grafo_insere_vertice(G, V))
 				break;
		}
 	}

 	for(i=0; i<nAres; i++){
 		
 		fscanf(file, "%s %s\n", sigla, aresta);
 		
 		if(grafo_busca_vertice(G, sigla) == NULL || grafo_busca_vertice(G, aresta) == NULL){
 			printf("Vertice %s não encontrado!\n", sigla);
 			continue;
 		}

 		if(!grafo_insere_aresta(G, sigla, aresta))
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

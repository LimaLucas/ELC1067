#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 50
#define QTD 50

void strtoupper(char *palavra){
    int i, tam;

    tam = strlen(palavra);

    for(i=0; i<tam; i++)
        palavra[i] = toupper(palavra[i]);
}

void leAlunos(int *matAlunos, char **nomes, int *n){

    int mat, i, linha;
    char c, nome[TAM];

    FILE *arq;
    arq = fopen("alunos.txt", "r");

    if(arq==NULL)
        printf("Erro ao abrir o arquivo alunos.txt. Verifique se o arquivo está com o nome correto ou se ele existe.");
    else{
        linha = 0;

        while(feof(arq)==0){

            if(fscanf(arq, "%i", &mat) != 1)
                break;

            i = 0;
            c = fgetc(arq);
            while(c==' ')
                c = fgetc(arq);

            while(c!='\n' && feof(arq)==0){
                nome[i] = c;
                i++;
                c = fgetc(arq);
            }

            nome[i] = '\0';
            matAlunos[linha] = mat;

            nomes[linha] = (char*) malloc((strlen(nome)+1)*sizeof(char));
            strcpy(nomes[linha], nome);

            linha++;

//            if(linha%QTD == 0){
//                matAlunos = (int*) realloc(matAlunos, linha*sizeof(int) + QTD*sizeof(int));
//                nomes = (char**) realloc(nomes, linha*sizeof(int) + QTD*sizeof(int));
//            }
        }
    }
    *n = linha;
    matAlunos[linha] = 0;
    fclose(arq);
}

void leNotas(int *matNotas, float *notas){
    FILE *arq;

    int i, mat;
    float a, b;
    arq = fopen("notas.txt", "r");

    if(arq==NULL)
        printf("Erro ao abrir o arquivo notas.txt. Verifique se o arquivo está com o nome correto ou se ele existe.");
    else{

        i = 0;
        while(feof(arq)==0){
            if(fscanf(arq, "%i %f %f\n", &mat, &a, &b) != 3)
                break;
            matNotas[i] = mat;
            notas[i] = (a+b)/2;
            i++;

//            if(i%QTD==0){
//                matNotas = (int*) realloc(matNotas, i*sizeof(int) + QTD*sizeof(int));
//                notas = (float*) realloc(notas, i*sizeof(float) + QTD*sizeof(float));
//            }
        }
        matNotas[i] = 0;
    }
    fclose(arq);
}

void imprimeMedia(int *matAlunos, int *matNotas, char **nomes, float *notas, char *nomeBusca){

    int i, j, flag;
    char temp[TAM];
    i = flag = 0;

    strtoupper(nomeBusca);

    while(matAlunos[i]>0){
        j = 0;

        strcpy(temp, nomes[i]);
        strtoupper(temp);

        if(strstr(temp, nomeBusca)!=NULL){
            flag++;
            while(matAlunos[i]!=matNotas[j] && matNotas[j]>0)
                j++;
            if(flag==1)
                printf("\n MEDIA ..... NOME\n");
            printf("  %.2f ..... %s\n", notas[j], nomes[i]);
        }
        i++;
    }
    if(flag==0)
        printf(" Nenhum resultado encontrado");

}

main(int argc, char **argv){

    int *matAlunos, *matNotas, n, i;
    float *notas;
    char **nomes, *nomeBusca;

    //nomeBusca = (char*) malloc(TAM*sizeof(char));

    matAlunos = (int*) malloc(QTD*sizeof(int));
    matNotas = (int*) malloc(QTD*sizeof(int));
    notas = (float*) malloc(QTD*sizeof(float));
    nomes = (char**) malloc(TAM*sizeof(char*));

    if(argc > 1){
        nomeBusca = argv[1];
	//strcpy(nomeBusca, argv[1]);
        printf(" Resultado da busca feita por: %s \n", nomeBusca);
    }else{
        printf(" Nenhum nome passado para realizar a busca. Abaixo lista completa.\n");
        strcpy(nomeBusca, " ");
    }

    leAlunos(matAlunos, nomes, &n);
    leNotas(matNotas, notas);
    imprimeMedia(matAlunos, matNotas, nomes, notas, nomeBusca);

    //free(nomeBusca);
    free(matAlunos);
    free(matNotas);
    free(notas);

    for(i=0; i<n; i++)
        free(nomes[i]);
    free(nomes);

    return 0;
}

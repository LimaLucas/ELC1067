#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leAlunos(int *matriculas, char nomes[][50], int *n){

    FILE *alunosF;

    int mat, i, linha;
    char c, nome[50];

    alunosF = fopen("alunos.txt", "r");

    linha = 0;
    while(feof(alunosF)!=0){
        if(fscanf(alunosF, "%i", &mat)==0)
            break;

        i = 0;
        c = fgetc(alunosF);
        while(c==' ')
            c = fgetc(alunosF);

        while(c != '\n'){
            nome[i] = c;
            c = fgetc(alunosF);
            i++;
        }

        nome[i] = '\0';
        matriculas[linha] = mat;
        strcpy(nome[linha], nome);
        linha++;
    }
    *n = linha;
    fclose(alunosF);

}

void leNotas(int *matNotas, float *notas){
    FILE *notasF;

    int i, mat;
    float a, b;
    notasF = fopen("notas.txt", "r");

    i = 0;
    while(feof(notasF)!=0){
        if(fscanf(notasF, "%i", &mat)==0)
            break;

        fscanf(notasF, "%i %f %f", &matNotas[i], &a, &b);
        matNotas[i] = (a+b)/2;
        i++;
    }

    fclose(notasF);
}

void buscaAluno(int *matriculas, int *matBusca, char nomes[][50], char *nomeBusca, int *n, int *m){

    int i, linha;

    linha = 0;
    for(i=0; i<*n; i++){
        if(strstr(nomes[i], nomeBusca) != NULL){
            matBusca[linha] = matriculas[i];
            linha++;
        }
    }

    *m = linha;
}

main(int argc, char **argv){

    int matriculas[50], matBusca[50], matNotas[50], n, m;
    float notas[50];
    char nomes[50][50], *nomeBusca;

    if(argc > 1){
        strcpy(nomeBusca, argv[1]);
        printf("%s \n", nomeBusca);
    }

    leAlunos(matriculas, nomes, &n);
    buscaAluno(matriculas, matBusca, nomes, nomeBusca, &n, &m);


    return 0;
}

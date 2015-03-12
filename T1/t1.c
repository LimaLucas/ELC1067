#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leAlunos(int* matriculas, char** nomes, int* n){

    FILE *alunosF, *notasF;

    int mat, i, linha;
    char c, nome[50];

    alunosF = fopen("alunos.txt", "r");
    notasF = fopen("notas.txt", "r");

    linha = 0;
    while(feof(alunosF)!=0){
        if(fscanf(alunosF, "%i", mat)==0)
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

main(int argc, char** argv){

    int matriculas[50], n;
    float notas;
    char nomes[50][50], *nome;

    if(argc > 1){
        strcpy(nome, argv[1]);
        printf("%s \n", nome);
    }

    leAlunos(matriculas, nomes, &n);

    return 0;
}

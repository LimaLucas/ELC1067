#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leAlunos(int* matricula, char** nome, int* n){
    FILE *alunosF, *notasF;

    int mat, i;
    char c, nome[50];

    alunosF = fopen("alunos.txt", "r");
    notasF = fopen("notas.txt", "r");

    while(feof(alunosF)!=0){
        fscanf(alunosF, "%i", mat);

        i = 0;
        c = fgetc(alunosF);
        while(c != '\n'){
            nome[i] = c;
            c = fgetc(alunosF);
            i++;
        }
        nome[i] = '\0';
    }

}

void main(){

    int matriculas[50], n;
    float notas;
    char nomes[50][50];

    leAlunos(matriculas, nomes, &n);

    exit(0);
}

#include <stdio.h>

void main(){
    FILE *f;
    int matricula;
    char nome[100];

    f = fopen("saida.txt", "r");
    if(f == NULL)
        printf("N�o foi possivel abrir o arquivo!");
    else
        fscanf(f, "%i %s", &matricula, &nome);
        printf("Aluno: %s \nMatricula: %i", nome, matricula);

    exit(0);
}

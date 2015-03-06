#include <stdio.h>

void main(){
    FILE *f;
    int matricula;
    char nome[100];

    f = fopen("saida.txt", "r");
    if(f == NULL)
        printf("Não foi possivel abrir o arquivo!")
    else{
        fscanf("%i %s", &matricula, &nome);
        printf("Aluno: %s \n Matricula: %i", nome, matricula);
    }

    exit(0);
}

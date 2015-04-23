#include <stdio.h>

void main(){

    FILE *f;
    int matricula;
    char nome[100];

    printf("Informe a Matricula do aluno: ");
    scanf("%i",&matricula);
    printf("Informe o nome do aluno: ");
    scanf("%s",&nome);

    f = fopen("saida.txt", "w");
    fprintf(f, "%i %s\n", matricula, nome);
    fclose(f);

}

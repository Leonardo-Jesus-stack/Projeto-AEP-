
#include <stdio.h>
#include "dados.h"

void cadastrarEstudante(struct Estudante estudantes[], int *quantidade) {
    int i, repetido;

    if (*quantidade >= 100) {
        printf("\nLimite de estudantes atingido!\n");
        return;
    }

    printf("\n=== CADASTRO DE ESTUDANTES ===\n");

    printf("Nome: ");
    scanf(" %49[^\n]", estudantes[*quantidade].nome);

    printf("Matricula: ");
    if (scanf("%d", &estudantes[*quantidade].matricula) != 1) {
        printf("Matricula invalida!\n");
        while (getchar() != '\n');
        return;
    }

    if (estudantes[*quantidade].matricula <= 0) {
        printf("Matricula invalida!\n");
        return;
    }

    repetido = 0;

    for (i = 0; i < *quantidade; i++) {
        if (estudantes[i].matricula ==
            estudantes[*quantidade].matricula) {
            repetido = 1;
        }
    }

    if (repetido == 1) {
        printf("Estudante ja cadastrado!\n");
        return;
    }

    printf("Turma: ");
    scanf(" %19[^\n]", estudantes[*quantidade].turma);

    printf("Escola: ");
    scanf(" %49[^\n]", estudantes[*quantidade].escola);

    printf("\nSituacao:\n");
    printf("1 - Pendente\n");
    printf("2 - Em acompanhamento\n");
    printf("3 - Concluido\n");
    printf("Escolha: ");

    if (scanf("%d", &estudantes[*quantidade].situacao) != 1) {
        printf("Situacao invalida!\n");
        while (getchar() != '\n');
        return;
    }

    if (estudantes[*quantidade].situacao < 1 ||
        estudantes[*quantidade].situacao > 3) {
        printf("Situacao invalida!\n");
        return;
    }

    (*quantidade)++;

    printf("\nEstudante cadastrado com sucesso!\n");
}


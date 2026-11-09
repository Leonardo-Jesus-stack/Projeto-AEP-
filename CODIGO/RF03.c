
#include <stdio.h>
#include <string.h>
#include "dados.h"

void pesquisarRegistro(struct Estudante estudantes[], int quantidade) {
    int opcao, matricula, situacao;
    int i, encontrou = 0;
    char nome[50], turma[20], escola[50];

    printf("\n=== PESQUISA DE REGISTROS ===\n");
    printf("1 - Pesquisar por matricula\n");
    printf("2 - Pesquisar por nome\n");
    printf("3 - Pesquisar por turma\n");
    printf("4 - Pesquisar por escola\n");
    printf("5 - Pesquisar por situacao\n");
    printf("Escolha: ");

    if (scanf("%d", &opcao) != 1) {
        printf("Opcao invalida!\n");
        while (getchar() != '\n');
        return;
    }

    if (opcao == 1) {
        printf("Digite a matricula: ");
        if (scanf("%d", &matricula) != 1) {
            printf("Matricula invalida!\n");
            while (getchar() != '\n');
            return;
        }
        if (matricula <= 0) {
            printf("Matricula invalida!\n");
            return;
        }
    }
    else if (opcao == 2) {
        printf("Digite o nome: ");
        scanf(" %49[^\n]", nome);
    }
    else if (opcao == 3) {
        printf("Digite a turma: ");
        scanf(" %19[^\n]", turma);
    }
    else if (opcao == 4) {
        printf("Digite a escola: ");
        scanf(" %49[^\n]", escola);
    }
    else if (opcao == 5) {
        printf("Digite a situacao:\n");
        printf("1 - Pendente\n");
        printf("2 - Em acompanhamento\n");
        printf("3 - Concluido\n");
        printf("Escolha: ");

        if (scanf("%d", &situacao) != 1) {
            printf("Situacao invalida!\n");
            while (getchar() != '\n');
            return;
        }

        if (situacao < 1 || situacao > 3) {
            printf("Situacao invalida!\n");
            return;
        }
    }
    else {
        printf("\nOpcao invalida!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        int corresponde = 0;

        if (opcao == 1 && estudantes[i].matricula == matricula) {
            corresponde = 1;
        }
        else if (opcao == 2 &&
                 strcmp(estudantes[i].nome, nome) == 0) {
            corresponde = 1;
        }
        else if (opcao == 3 &&
                 strcmp(estudantes[i].turma, turma) == 0) {
            corresponde = 1;
        }
        else if (opcao == 4 &&
                 strcmp(estudantes[i].escola, escola) == 0) {
            corresponde = 1;
        }
        else if (opcao == 5 &&
                 estudantes[i].situacao == situacao) {
            corresponde = 1;
        }

        if (corresponde == 1) {
            printf("\nAluno encontrado!\n");
            printf("Nome: %s\n", estudantes[i].nome);
            printf("Matricula: %d\n", estudantes[i].matricula);
            printf("Turma: %s\n", estudantes[i].turma);
            printf("Escola: %s\n", estudantes[i].escola);

            if (estudantes[i].situacao == 1) {
                printf("Situacao: Pendente\n");
            }
            else if (estudantes[i].situacao == 2) {
                printf("Situacao: Em acompanhamento\n");
            }
            else {
                printf("Situacao: Concluido\n");
            }

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nNenhum registro encontrado.\n");
    }
}


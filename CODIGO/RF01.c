
#include <stdio.h>
#include "dados.h"

void cadastrarUsuario(struct Usuario usuarios[], int *quantidade) {
    int i, repetido;

    if (*quantidade >= 100) {
        printf("\nLimite de usuarios atingido!\n");
        return;
    }

    printf("\n=== CADASTRO DE USUARIOS ===\n");

    printf("Nome: ");
    scanf(" %49[^\n]", usuarios[*quantidade].nome);

    printf("Identificacao: ");
    if (scanf("%d", &usuarios[*quantidade].identificacao) != 1) {
        printf("Identificacao invalida!\n");
        while (getchar() != '\n');
        return;
    }

    if (usuarios[*quantidade].identificacao <= 0) {
        printf("Identificacao invalida!\n");
        return;
    }

    repetido = 0;

    for (i = 0; i < *quantidade; i++) {
        if (usuarios[i].identificacao ==
            usuarios[*quantidade].identificacao) {
            repetido = 1;
        }
    }

    if (repetido == 1) {
        printf("Usuario ja cadastrado!\n");
        return;
    }

    printf("\nFuncao:\n");
    printf("1 - Administrador\n");
    printf("2 - Profissional de saude\n");
    printf("3 - Responsavel\n");
    printf("Escolha: ");

    if (scanf("%d", &usuarios[*quantidade].funcao) != 1) {
        printf("Funcao invalida!\n");
        while (getchar() != '\n');
        return;
    }

    if (usuarios[*quantidade].funcao < 1 ||
        usuarios[*quantidade].funcao > 3) {
        printf("Funcao invalida!\n");
        return;
    }

    usuarios[*quantidade].nivelAcesso =
        usuarios[*quantidade].funcao;

    (*quantidade)++;

    printf("\nUsuario cadastrado com sucesso!\n");
}



#include <stdio.h>
#include "dados.h"

void atualizarSituacao(struct Estudante estudantes[], int quantidade) {
    int matricula, novaSituacao;
    int encontrou = 0;
    int i;

    printf("\n=== ATUALIZAR SITUACAO ===\n");

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

    for (i = 0; i < quantidade; i++) {
        if (estudantes[i].matricula == matricula) {

            printf("\nAluno encontrado: %s\n", estudantes[i].nome);

            printf("\nEscolha a nova situacao:\n");
            printf("1 - Pendente\n");
            printf("2 - Em acompanhamento\n");
            printf("3 - Concluido\n");
            printf("Escolha: ");

            if (scanf("%d", &novaSituacao) != 1) {
                printf("\nOpcao invalida!\n");
                while (getchar() != '\n');
                return;
            }

            if (novaSituacao >= 1 && novaSituacao <= 3) {
                estudantes[i].situacao = novaSituacao;
                printf("\nSituacao atualizada com sucesso!\n");
            }
            else {
                printf("\nOpcao invalida!\n");
            }

            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("\nMatricula nao encontrada.\n");
    }
}


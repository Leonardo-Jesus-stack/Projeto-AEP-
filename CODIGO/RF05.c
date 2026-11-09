
#include <stdio.h>
#include "dados.h"

void gerarResumo(struct Estudante estudantes[], int quantidade) {
    int i;
    int pendentes = 0;
    int acompanhamento = 0;
    int concluidos = 0;

    printf("\n=== RESUMO DOS REGISTROS ===\n");

    if (quantidade == 0) {
        printf("Nenhum estudante cadastrado.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        if (estudantes[i].situacao == 1) {
            pendentes++;
        }
        else if (estudantes[i].situacao == 2) {
            acompanhamento++;
        }
        else if (estudantes[i].situacao == 3) {
            concluidos++;
        }
    }

    printf("\nTotal de estudantes: %d\n", quantidade);
    printf("Pendentes: %d\n", pendentes);
    printf("Em acompanhamento: %d\n", acompanhamento);
    printf("Concluidos: %d\n", concluidos);

    printf("\n=== LISTA DE ESTUDANTES ===\n");

    for (i = 0; i < quantidade; i++) {
        printf("\nNome: %s\n", estudantes[i].nome);
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
    }
}


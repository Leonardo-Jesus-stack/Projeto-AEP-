
#include <stdio.h>
#include "dados.h"

int controlarAcesso(struct Usuario usuarios[], int quantidade) {
    int identificacao;
    int i;

    printf("\n=== CONTROLE DE ACESSO ===\n");

    printf("Digite sua identificacao: ");

    if (scanf("%d", &identificacao) != 1) {
    	
        printf("Identificacao invalida!\n");
        while (getchar() != '\n');
        return 0;
    }

    for (i = 0; i < quantidade; i++) {
        if (usuarios[i].identificacao == identificacao) {

            printf("\nBem-vindo, %s!\n", usuarios[i].nome);

            if (usuarios[i].nivelAcesso == 1) {
                printf("Perfil: Administrador\n");
            }
            else if (usuarios[i].nivelAcesso == 2) {
                printf("Perfil: Profissional de saude\n");
            }
            else {
                printf("Perfil: Responsavel\n");
            }

            return usuarios[i].nivelAcesso;
        }
    }

    printf("\nUsuario nao encontrado!\n");
    return 0;
}


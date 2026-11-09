
#include <stdio.h>
#include "dados.h"

int main() {
    struct Usuario usuarios[100];
    struct Estudante estudantes[100];

    int quantidadeUsuarios = 1;
    int quantidadeEstudantes = 0;
    int opcao;
    int nivelAcesso = 0;

    struct Usuario administrador = {
        "Administrador", 1, 1, 1
    };

    usuarios[0] = administrador;

    // Carregar os dados salvos nos arquivos TXT
    carregarUsuarios(usuarios, &quantidadeUsuarios);
    carregarEstudantes(estudantes, &quantidadeEstudantes);

    // Criar administrador inicial se nao houver usuarios
    if (quantidadeUsuarios == 0) {
        usuarios[0] = administrador;
        quantidadeUsuarios = 1;
        salvarUsuarios(usuarios, quantidadeUsuarios);
    }

    printf("=== SISTEMA PROGRAMA SAUDE NA ESCOLA ===\n");
    printf("Acesso de teste: 1\n");

    nivelAcesso = controlarAcesso(usuarios, quantidadeUsuarios);

    while (nivelAcesso != 0) {

        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1 - RF01: Cadastrar usuario\n");
        printf("2 - RF02: Cadastrar estudante\n");
        printf("3 - RF03: Pesquisar registro\n");
        printf("4 - RF04: Atualizar situacao\n");
        printf("5 - RF05: Gerar resumo\n");
        printf("6 - RF06: Trocar usuario\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {

            case 1:
                if (nivelAcesso == 1) {
                    cadastrarUsuario(usuarios, &quantidadeUsuarios);
                    salvarUsuarios(usuarios, quantidadeUsuarios);
                }
                else {
                    printf("\nAcesso negado!\n");
                }
                break;

            case 2:
                if (nivelAcesso == 1 || nivelAcesso == 2) {
                    cadastrarEstudante(estudantes, &quantidadeEstudantes);
                    salvarEstudantes(estudantes, quantidadeEstudantes);
                }
                else {
                    printf("\nAcesso negado!\n");
                }
                break;

            case 3:
                pesquisarRegistro(estudantes, quantidadeEstudantes);
                break;

            case 4:
                if (nivelAcesso == 1 || nivelAcesso == 2) {
                    atualizarSituacao(estudantes, quantidadeEstudantes);
                    salvarEstudantes(estudantes, quantidadeEstudantes);
                }
                else {
                    printf("\nAcesso negado!\n");
                }
                break;

            case 5:
                if (nivelAcesso == 1 || nivelAcesso == 2) {
                    gerarResumo(estudantes, quantidadeEstudantes);
                }
                else {
                    printf("\nAcesso negado!\n");
                }
                break;

            case 6:
                nivelAcesso = controlarAcesso(usuarios, quantidadeUsuarios);
                break;

            case 0:
                salvarUsuarios(usuarios, quantidadeUsuarios);
                salvarEstudantes(estudantes, quantidadeEstudantes);

                printf("\nEncerrando o sistema...\n");
                nivelAcesso = 0;
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    }

    return 0;
}


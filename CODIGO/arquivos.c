
#include <stdio.h>
#include "dados.h"

// Salvar usuarios no TXT
void salvarUsuarios(struct Usuario usuarios[], int quantidade) {
    FILE *arquivo;
    int i;

    arquivo = fopen("usuarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar usuarios!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s\n", usuarios[i].nome);
        fprintf(arquivo, "%d\n", usuarios[i].identificacao);
        fprintf(arquivo, "%d\n", usuarios[i].funcao);
        fprintf(arquivo, "%d\n", usuarios[i].nivelAcesso);
    }

    fclose(arquivo);
}

// Carregar usuarios do TXT
void carregarUsuarios(struct Usuario usuarios[], int *quantidade) {
    FILE *arquivo;
    struct Usuario usuario;

    arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        *quantidade = 0;
        return;
    }

    *quantidade = 0;

    while (*quantidade < 100 &&
           fscanf(arquivo, " %49[^\n]", usuario.nome) == 1 &&
           fscanf(arquivo, "%d", &usuario.identificacao) == 1 &&
           fscanf(arquivo, "%d", &usuario.funcao) == 1 &&
           fscanf(arquivo, "%d", &usuario.nivelAcesso) == 1) {

        usuarios[*quantidade] = usuario;
        (*quantidade)++;
    }

    fclose(arquivo);
}

// Salvar estudantes no TXT
void salvarEstudantes(struct Estudante estudantes[], int quantidade) {
    FILE *arquivo;
    int i;

    arquivo = fopen("estudantes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar estudantes!\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s\n", estudantes[i].nome);
        fprintf(arquivo, "%d\n", estudantes[i].matricula);
        fprintf(arquivo, "%s\n", estudantes[i].turma);
        fprintf(arquivo, "%s\n", estudantes[i].escola);
        fprintf(arquivo, "%d\n", estudantes[i].situacao);
    }

    fclose(arquivo);
}

// Carregar estudantes do TXT
void carregarEstudantes(struct Estudante estudantes[], int *quantidade) {
    FILE *arquivo;
    struct Estudante estudante;

    arquivo = fopen("estudantes.txt", "r");

    if (arquivo == NULL) {
        *quantidade = 0;
        return;
    }

    *quantidade = 0;

    while (*quantidade < 100 &&
           fscanf(arquivo, " %49[^\n]", estudante.nome) == 1 &&
           fscanf(arquivo, "%d", &estudante.matricula) == 1 &&
           fscanf(arquivo, " %19[^\n]", estudante.turma) == 1 &&
           fscanf(arquivo, " %49[^\n]", estudante.escola) == 1 &&
           fscanf(arquivo, "%d", &estudante.situacao) == 1) {

        estudantes[*quantidade] = estudante;
        (*quantidade)++;
    }

    fclose(arquivo);
}



#ifndef DADOS_H
#define DADOS_H

// Estrutura dos usuarios
struct Usuario {
    char nome[50];
    int identificacao;
    int funcao;
    int nivelAcesso;
};

// Estrutura dos estudantes
struct Estudante {
    char nome[50];
    int matricula;
    char turma[20];
    char escola[50];
    int situacao;
};

// RF01 - Cadastro de usuarios
void cadastrarUsuario(struct Usuario usuarios[], int *quantidade);

// RF02 - Cadastro de estudantes
void cadastrarEstudante(struct Estudante estudantes[], int *quantidade);

// RF03 - Pesquisa de registros
void pesquisarRegistro(struct Estudante estudantes[], int quantidade);

// RF04 - Atualizacao da situacao
void atualizarSituacao(struct Estudante estudantes[], int quantidade);

// RF05 - Geracao de resumo
void gerarResumo(struct Estudante estudantes[], int quantidade);

// RF06 - Controle de acesso
int controlarAcesso(struct Usuario usuarios[], int quantidade);

// Salvar e carregar usuarios
void salvarUsuarios(struct Usuario usuarios[], int quantidade);
void carregarUsuarios(struct Usuario usuarios[], int *quantidade);

// Salvar e carregar estudantes
void salvarEstudantes(struct Estudante estudantes[], int quantidade);
void carregarEstudantes(struct Estudante estudantes[], int *quantidade);

#endif


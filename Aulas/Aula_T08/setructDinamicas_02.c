#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int mstricula;
    char *nome;
    char *eMail;
} Aluno;

typedef Aluno* pAluno;

struct LAluno{
    int mstricula;
    char *nome;
    char *eMail;
    struct LAluno *proximo;
};  

typedef struct LAluno TAluno;

int main(void)
{
    TAluno *turma = NULL;
    TAluno *aluno;

    TAluno *novoAluno = (TAluno *) malloc(sizeof(TAluno));
    novoAluno->mstricula = 1;
    novoAluno->nome = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->nome, "Joao");
    novoAluno->eMail = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->eMail, "joao_CIC_01@uesc.br");
    novoAluno->proximo = NULL;
    turma = novoAluno;
    aluno = turma;

    novoAluno = (TAluno *) malloc(sizeof(TAluno));
    novoAluno->mstricula = 2;
    novoAluno->nome = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->nome, "Jose");
    novoAluno->eMail = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->eMail, "jose_CIC_02@uesc.br");
    novoAluno->proximo = NULL;

    aluno->proximo = novoAluno;

    novoAluno = (TAluno *) malloc(sizeof(TAluno));
    novoAluno->mstricula = 3;
    novoAluno->nome = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->nome, "Joana");
    novoAluno->eMail = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->eMail, "joana_CIC_03@uesc.br");
    novoAluno->proximo = NULL;

    aluno = aluno->proximo;
    aluno->proximo = novoAluno;

    novoAluno = (TAluno *) malloc(sizeof(TAluno));
    novoAluno->mstricula = 4;
    novoAluno->nome = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->nome, "Maria");
    novoAluno->eMail = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->eMail, "maria_CIC_04@uesc.br");
    novoAluno->proximo = NULL;

    aluno = aluno->proximo;
    aluno->proximo = novoAluno;

    aluno = turma;
    while(aluno->proximo != NULL)
    {
        printf("Matricula: %d\n", aluno->mstricula);
        printf("Nome: %s\n", aluno->nome);
        printf("E-mail: %s\n", aluno->eMail);
        aluno = aluno->proximo;
    }







    return 0;
}
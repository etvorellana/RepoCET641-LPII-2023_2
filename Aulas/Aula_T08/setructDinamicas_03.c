#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct LAluno{
    int mstricula;
    char *nome;
    char *eMail;
    struct LAluno *proximo;
};  

typedef struct LAluno TAluno;
typedef TAluno *PAluno;

 //struct LAluno* novoAluno(char *nome, char *eMail, int matricula)
 //TAluno* novoAluno(char *nome, char *eMail, int matricula)
 PAluno outroAluno(char *nome, char *eMail, int matricula)
 {
    PAluno novoAluno = (PAluno) malloc(sizeof(TAluno));
    novoAluno->mstricula = matricula;
    novoAluno->nome = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->nome, nome);
    novoAluno->eMail = (char *) malloc(100 * sizeof(char));
    strcpy(novoAluno->eMail, eMail);
    novoAluno->proximo = NULL;
    return novoAluno;
 }

void outroAluno_(char *nome, char *eMail, int matricula, PAluno *novoAluno)
{
    *novoAluno = (PAluno) malloc(sizeof(TAluno)); 
    novoAluno->mstricula = matricula;
    novoAluno->nome = (char *) malloc(100 * sizeof(char));
    strcpy(*novoAluno->nome, nome);
    *novoAluno->eMail = (char *) malloc(100 * sizeof(char));
    strcpy(*novoAluno->eMail, eMail);
    *novoAluno->proximo = NULL;
    return;
}

 //void imprimeTurma(PAluno turma)
 void imprimeTurma(PAluno aluno)
 {
    //PAluno aluno = turma;
    while(aluno != NULL)
    {
        printf("Matricula: %d\n", aluno->mstricula);
        printf("Nome: %s\n", aluno->nome);
        printf("E-mail: %s\n", aluno->eMail);
        aluno = aluno->proximo;
    }
 }

void imprimeTurmaR(PAluno turma)
 {
    if (turma == NULL)
        return;
    printf("Matricula: %d\n", turma->mstricula);
    printf("Nome: %s\n", turma->nome);
    printf("E-mail: %s\n", turma->eMail);
    imprimeTurmaR(turma->proximo);
 }



int main(void)
{
    TAluno *turma = NULL;
    TAluno *aluno;

    TAluno *novoAluno = outroAluno("Joao", "joao_CIC_01@uesc.br", 1);
    turma = novoAluno;
    aluno = turma;

    //novoAluno = outroAluno("Jose", "jose_CIC_02@uesc.br", 2);
    outroAluno_("Jose", "jose_CIC_02@uesc.br", 2, novoAluno);
    aluno->proximo = novoAluno;

    novoAluno = outroAluno("Joana", "joana_CIC_03@uesc.br", 3);
    aluno = aluno->proximo;
    aluno->proximo = novoAluno;

    novoAluno = outroAluno("Maria", "maria_CIC_04@uesc.br", 4);
    aluno = aluno->proximo;
    aluno->proximo = novoAluno;

    imprimeTurma(turma);
    
    return 0;
}
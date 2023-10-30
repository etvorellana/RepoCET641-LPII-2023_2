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



int main(void)
{
    //Aluno *turma;
    pAluno turma;
    turma = (pAluno) malloc(5 * sizeof(Aluno));
    for(int i = 0; i < 5; i++)
    {
        char nome[100], eMail[100];
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(nome, 100, stdin);
        int sSize = strlen(nome);
        turma[i].nome = (char *) malloc(strlen(nome) * sizeof(char));
        nome[sSize - 1] = '\0';
        printf("Digite o e-mail do aluno %d: ", i+1);
        fgets(eMail, 100, stdin);
        sSize = strlen(eMail);
        turma[i].eMail = (char *) malloc(strlen(eMail) * sizeof(char));
        eMail[sSize - 1] = '\0';
        strcpy(turma[i].nome, nome);
        strcpy(turma[i].eMail, eMail);
    }

    return 0;
}
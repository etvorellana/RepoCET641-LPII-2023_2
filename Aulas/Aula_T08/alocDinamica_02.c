#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char **str;
    str = (char **) malloc(5 * sizeof(char *));
    int sSize;
    for(int i = 0; i < 5; i++)
    {
        char nome[100];
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(nome, 100, stdin);
        sSize = strlen(nome);
        nome[sSize - 1] = '\0';
        str[i] = (char *) malloc(sSize * sizeof(char));
        strcpy(str[i], nome);
    }
    for(int i = 0; i < 5; i++)
        printf("Nome: %s\n", str[i]);

    for(int i = 0; i < 5; i++)
        free(str[i]);
    free(str);
    return 0;
}

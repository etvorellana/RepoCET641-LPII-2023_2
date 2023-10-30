#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char *str, nome[100];
    printf("Digite seu nome: ");
    fgets(nome, 100, stdin);
    int sSize = strlen(nome);
    nome[sSize - 1] = '\0';
    str = (char *) malloc(sSize * sizeof(char));
    //strcpy(str, nome);
    for(int i = 0; i < sSize; i++)
        str[i] = nome[i];
    printf("Nome: %s\n", str);
    free(str);
    return 0;
}

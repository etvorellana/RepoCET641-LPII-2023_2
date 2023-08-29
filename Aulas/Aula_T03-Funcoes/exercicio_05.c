#include <stdio.h>
#include <string.h>

#include "headers_Aula03.h"

int main(void)
{
    char string[100], msg[100];
    printf("Digite uma string    : ");
    fgets(string, 100, stdin);
    ajustaFgetsString(string);
    codificaMsg(string, msg);
    printf("Mensagem oculta      : %s\n", msg);
    return 0;
}    

int ajustaFgetsString(char string[])
{
    int N = strlen(string) - 1;
    if (string[N] == '\n')
        string[N] = '\0';
    return N;
}

void codificaMsg(char string[], char msg[])
{
    int i = 0, j = 0;
    char aux;
    if (string[i] != ' ')
    {
        aux = msg[j++] = string[i++];
    }else{
        aux = string[i++];
    }
    for(;string[i] != '\0';)
    {
        if (string[i] != ' ' && aux == ' ')
        {
            aux = msg[j++] = string[i++];
        }else{
            aux = string[i++];
        }
    }
    msg[j] = '\0';
    return;
}


#include <stdio.h>
#include <string.h>

#include "headers_Aula03.h"

int main(void)
{
    char string[100];
    codificaString(string);
    return 0;
}

int ajustaFgetsString(char string[])
{
    int N = strlen(string) - 1;
    if (string[N] == '\n')
        string[N] = '\0';
    return N;
}

void codificaString(char string[])
{
    printf("Digite uma string    : ");
    fgets(string, 100, stdin);
    ajustaFgetsString(string);
    int i = 0, cont = 0;
    while(string[i] != '\0')
    {
        if(string[i] == ' ')
        {
            printf("%d-", cont);
            cont = 0;
        }else{
            cont++;
        }
        i++;
    }
    printf("%d\n", cont);
    return;
}


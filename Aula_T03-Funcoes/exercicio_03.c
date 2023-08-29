#include <stdio.h>
#include <string.h>

#include "headers_Aula03.h"

int main(void)
{
    char string[100];
    // Primeiro vamos simular o virus
    printf("Digite uma string    : ");
    fgets(string, 100, stdin);
    ajustaFgetsString(string);
    // Agora vamos embaralhar
    embaralhaString(string);
    printf("String embaralhada   : %s\n", string);
    // Agora vamos desembaralhar
    embaralhaString(string);
    printf("String desembaralhada: %s\n", string);
    return 0;
}

int ajustaFgetsString(char string[])
{
    int N = strlen(string) - 1;
    if (string[N] == '\n')
        string[N] = '\0';
    return N;
}

void embaralhaString(char string[])
{
    int N = strlen(string);
    int halfN = N / 2;
    
    for(int i = 0 ; i < halfN / 2 ; i++)
    {
        char aux = string[i];
        string[i] = string[halfN - i - 1];
        string[halfN - i - 1] = aux;
        aux = string[halfN + i];
        string[halfN + i] = string[N - i - 1];
        string[N - i - 1] = aux;
    }
    return;
}


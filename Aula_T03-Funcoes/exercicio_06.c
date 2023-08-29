#include <stdio.h>
#include <string.h>

#include "headers_Aula03.h"

int main(void)
{
    char nome1[100], nome2[100];
    char token1[4], token2[4];
    printf("Digite uma nome      : ");
    fgets(nome1, 100, stdin);
    ajustaFgetsString(nome1);
    
    printf("Digite outro nome    : ");
    fgets(nome2, 100, stdin);
    int N = ajustaFgetsString(nome2);

    N =  N < strlen(nome1) ? N : strlen(nome1);
    if (N < 3)
        printf("Nao ha tokens\n");
    else{
        int conTokens = tokensIguais(nome1, nome2, N);
        printf("Tokens comuns: %d\n", conTokens);
    }
    return 0;
}

int ajustaFgetsString(char string[])
{
    int N = strlen(string) - 1;
    if (string[N] == '\n')
        string[N] = '\0';
    return N;
}

int tokensIguais(char nome1[], char nome2[], int N)
{
    char token1[4], token2[4];
    for(int i = 0; i < 2; i++)
    {
        token1[i+1] = nome1[i];
        token2[i+1] = nome2[i];
    }
    int conTokens = 0;
    for(int i = 2; i < N; i++)
    {
        //shift
        for(int j = 0; j < 2; j++)
        {
            token1[j] = token1[j+1];
            token2[j] = token2[j+1];
        }
        token1[2] = nome1[i];
        token2[2] = nome2[i];
        if (strcmp(token1, token2) == 0)
        {
            conTokens++;
        }
    }
    return conTokens;
}
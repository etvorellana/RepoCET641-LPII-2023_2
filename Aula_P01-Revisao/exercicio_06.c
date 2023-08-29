/*
    Um hospital pretende migrar seus registros de pacientes para um novo      |
    sistema. No entanto, foi observado que a tabela clientes possui o problema| 
    registros duplicados. Ou seja, um mesmo paciente que ingressou duas vezes |
    no hospital pode estar registrado duas vezes na base de dados. Tal        |
    problema ocorre devido a presença de erros de tipografia (por exemplo:    |
    “Ketlyn da Silva” ou “Ketlin da Silva”). Uma alternativa para contornar   |
    esse problema é quebrar o texto (“string”) em unidades menores (“tokens”) |
    de um determinado tamanho e computar o número de tokens em comum. Por     |
    exemplo, os tokens de tamanho 3 para a string “Ketlyn” são: “ket”,”etl”,  |
    ”tly” e “lyn”; já para a string “Ketlin” são gerados as substrings: “ket”,| 
    “etl”, “tli”,”lin”. Note que a geração de substrings é feita a partir de  |
    uma “janela deslizante” variando em 1 caractere. Note que não há distinção| 
    entre maiúsculas e minúsculas. Por fim, é necessário contabilizar quantos |
    tokens as strings têm em comum. Implemente uma aplicação que recebe dois  |
    nomes e retorna quantos tokens de 3 letras têm em comum.                  |
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome1[100], nome2[100];
    char token1[4], token2[4];
    printf("Digite uma nome      : ");
    fgets(nome1, 100, stdin);
    int N = strlen(nome1) - 1;
    nome1[N] = '\0';
    
    printf("Digite outro nome    : ");
    fgets(nome2, 100, stdin);
    N = strlen(nome2) - 1;
    nome2[N] = '\0';
    N = N < strlen(nome1) ? N : strlen(nome1);
    if (N < 3)
    {
        printf("Nao ha tokens\n");
        return 0;
    }
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
    printf("Tokens comuns: %d\n", conTokens);
    return 0;
}
/*
Faça um programa de criptografia de dados, ou seja, um programa capaz de ler um arquivo texto,
codificar este arquivo através de alguma técnica de alteração do código ASCII (exemplo: somar 1 ao valor ASCII de cada caracter), e escrever em disco o arquivo codificado.
*/
#include <stdio.h>
#include <stdlib.h>
#define CRIPTOGRAFIA 1

int main()
{
    FILE* file;
    FILE* fileCrip;
    file=fopen("cadastro.txt", "r");
    if(!file)
    {
        printf("O arquivo nao pode ser aberto\n");
        exit(1);
    }
    fileCrip=fopen("cadastroCriptografado.txt", "w");
    if(!fileCrip)
    {
        printf("O arquivo nao pode ser aberto\n");
        exit(1);
    }
    char ch;
    ch=fgetc(file);
    while(!feof(file))
    {
        fputc(ch+CRIPTOGRAFIA, fileCrip);
        ch = fgetc(file);
    }

    int erroFechar = fclose(file);
    if (erroFechar)
    {
        printf("Arquivo incorretamente fechado!!\n");
    }
    erroFechar=fclose(fileCrip);
    if(erroFechar)
    {
        printf("Arquivo criptografado incorretamente fechado!!\n");
    }

    return 0;
}

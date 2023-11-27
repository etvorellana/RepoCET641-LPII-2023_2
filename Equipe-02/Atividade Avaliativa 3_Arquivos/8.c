/*
Crie um outro programa que descriptografe um arquivo criado pelo programa de criptografia do exercício anterior,
realizando a operação inversa: ler o arquivo do disco, descodificar e escrever o novo arquivo em disco descriptografado.
Lembre-se que para que seja possível criptografar/descriptografar um arquivo a função de codificação deve possuir uma função inversa.
*/

#include <stdio.h>
#include <stdlib.h>
#define CRIPTOGRAFIA 1

int main()
{
    FILE* fileCrip;
    FILE* fileDescrip;

    fileCrip=fopen("cadastroCriptografado.txt", "r");
    if(!fileCrip)
    {
        printf("O arquivo criptografado nao pode ser aberto\n");
        exit(1);
    }

    fileDescrip=fopen("cadastroDescriptografado.txt", "w");
    if(!fileDescrip)
    {
        printf("O arquivo descriptografado nao pode ser aberto\n");
        exit(1);
    }

    char ch;
    ch=fgetc(fileCrip);
    while(!feof(fileCrip))
    {
        fputc(ch-CRIPTOGRAFIA, fileDescrip);
        ch = fgetc(fileCrip);
    }

    int erroFechar = fclose(fileCrip);
    if (erroFechar)
    {
        printf("Arquivo criptografado incorretamente fechado!!\n");
    }
    erroFechar=fclose(fileDescrip);
    if(erroFechar)
    {
        printf("Arquivo descriptografado incorretamente fechado!!\n");
    }

    return 0;
}

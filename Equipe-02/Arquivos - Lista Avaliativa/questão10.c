/*
Crie um programa C que:
a) Crie/abra um arquivo texto de nome "novo.txt". Se o arquivo já existir deve ser substituído pelo atual;
b) Permita que o usuário entre com diversos caracteres nesse arquivo, até que o o mesmo entre com o caractere ’>’, que indicara o fim da entrada de dados;
c) Feche o arquivo e abra novamente.
d) Lendo o arquivo caractere por caractere e armazenando numa string.
e) Escreva na tela com printf todos os caracteres armazenados.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file;
    file=fopen("novo.txt", "w");
    if(!file)
    {
        printf("O arquivo nao pode ser aberto\n");
        exit(1);
    }
    char ch;
    do
    {
        ch=getchar();
        if(ch!='>')
            fputc(ch, file);
        else
            fputc('\0', file);
    }while(ch!='>');
    int erroFechar=fclose(file);
    if(erroFechar)
        printf("Erro ao fechar o arquivo\n");

    char frase[200];
    file=fopen("novo.txt", "r");
    if(!file)
    {
        printf("O arquivo nao pode ser aberto\n");
        exit(1);
    }
    int i=0;
    while(!feof(file))
    {
        frase[i]=fgetc(file);
        i++;
    }
    printf("%s", frase);

    return 0;
}

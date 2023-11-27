#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    char palavra[100];
    char linha[1000];
    int linha_encontrada = -1;
    int numero_linha = 0;

    printf("Informe a palavra que pretende procurar: ");
    scanf("%s", palavra);

    fp = fopen("arquivo.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        numero_linha++;

        if (strstr(linha, palavra) != NULL)
        {
            linha_encontrada = numero_linha;
            break;
        }
    }

    int err = fclose(fp);

    if (err)
    {
        printf("Arquivo fechado de forma incorreta!");
    }

    if (linha_encontrada != -1)
    {
        printf("A palavra '%s' foi encontrada na linha %d\n", palavra, linha_encontrada);
        printf("O conteudo da linha e: %s\n", linha);
    }
    else
    {
        printf("A palavra '%s' nao foi encontrada no arquivo\n", palavra);
    }

    return 0;
}
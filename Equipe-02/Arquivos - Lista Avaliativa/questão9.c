#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

9. Faça um programa que peça para o usuário entrar um texto que deseja procurar (uma palavra) 
e que em seguida leia um arquivo texto do disco e procure por esta palavra no arquivo.
Caso seja encontrada a palavra digitada pelo usuário em alguma das linhas do arquivo texto lido do disco, 
o programa deverá exibir na tela o número da linha do arquivo onde encontrou esta ocorrência da palavra,
bem como o conteúdo da linha onde se encontra a palavra procurada.

*/

int main(void)
{
    FILE *fp;
    char palavra[100];
    char linha[1000];
    int linha_encontrada = -1; /*Inicializa com -1 para informar que a palavra não foi encontrada no arquivo.
                                Ao encontrar a palavra, linha_encontrada, será atualizada com o numero da linha onde a palavra foi encontrada*/

    printf("Informe a palavra que pretende procurar: ");
    scanf("%s", palavra);
    
    fp = fopen("arquivo.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    /* Leitura da linha do arquivo fp e armazena na "linha". sizeof(linha) 
       indica o número máximo que podem ser lidos do arquivo.
       Enquanto não chega ao final do arquivo ou a existência de um erro
       a loop continua.
    */
    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        // Região onde a palavra é procurada na linha atual
        if (strstr(linha, palavra) != NULL)
        {
            // A palavra foi encontrada
            linha_encontrada = ftell(fp) / sizeof(linha); // FTELL retorna a linha do arquivo fp que a palavra foi encontrada
            break;
        
        }
    }


     int err = fclose(fp);

    if (err)
    {
        printf("Arquivo fechado de forma incorreta!"); // Tratamento de erro referente ao fechamento do arquivo
    }

    // Se a palavra foi encontrada, exibe a linha onde ela foi encontrada
    if (linha_encontrada != -1)
    {
        printf("A palavra '%s' foi encontrada na linha %d\n", palavra, linha_encontrada+1);
        printf("O conteudo da linha e: %s\n", linha);
        
    }
    else
    {
        printf("A palavra '%s' nao foi encontrada no arquivo", palavra);
    }

    return 0;
}

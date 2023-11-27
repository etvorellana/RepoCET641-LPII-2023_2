#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5. Faça um programa que imite um editor de textos. Inicialmente você irá ler os dados digitados pelo usuário (linhas de texto)
e criar um vetor em memória onde serão armazenados os textos fornecidos pelo usuário (texto de 1 até no máximo 50 linhas).
O usuário vai escrever o seu texto, terminando por uma linha onde ele irá escrever apenas a palavra ‘FIM’,
o que determina que ele não deseja mais digitar linhas de texto. Sendo assim, o texto final pode ter um número variável de linhas,
entre 1 e 50. Salvar o conteúdo armazenado na memória neste vetor, em um arquivo texto em disco.
Sugestão: use o comando “gets” ou “fgets” para ler as linhas de texto digitadas pelo usuário.
*/

int main()
{

    char texto[50][1000];
    int numero_linhas = 0; // Deve contar a quantidade de linhas que o usuário digitou
    char linha[1000];

    printf("Digite seu texto (FIM para encerrar): ");
    while (1)
    {
    
        fgets(linha, 1000, stdin);

        // Tratamento de erro referente ao numero limite de linhas.
        if (numero_linhas > 50)
        {
            printf("Erro. Numero de linhas permitidas: Entre 1 e 50.\n");
            return 1;
        }

        // Verifica se o primeiro caractere é nulo tornando a linha é vazia
        if (linha[0] == '\0')
        {
            break;
        }

        // Se a linha for igual a "FIM", o programa encerra a leitura
        if (strcmp(linha, "FIM\n") == 0)
        {
            break;
        }

        // Armazena a linha no vetor
        strcpy(texto[numero_linhas], linha); //O primeiro argumento da strcpy é o destino e o segundo argumento é a origem.
        numero_linhas++;                     // Copia o conteúdo de linha para texto[numero_linhas].
    }

    FILE *arquivo; 

    arquivo = fopen("arquivo.txt", "w"); 

    for (int i = 0; i < numero_linhas; i++)
    {
        fprintf(arquivo, "%s\n", texto[i]); // Escreve o conteúdo no arquivo
    }

    int err = fclose(arquivo);

    if (err)
    {
        printf("Arquivo fechado de forma incorreta!"); // Tratamento de erro referente ao fechamento do arquivo
    }

    printf("Texto salvo com sucesso no arquivo.txt\n");

    return 0;
}
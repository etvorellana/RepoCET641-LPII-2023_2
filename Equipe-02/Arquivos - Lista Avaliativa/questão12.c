#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Faça um que abra um arquivo HTML e elimine todas as “tags” do texto, 
ou seja, o programa deve gerar um novo arquivo em disco que elimine 
todas as tags Html que são caracterizadas por comandos entre “<” e “>”. 

*/
int main(void)
{
    FILE *fp1, *fp2;
    char caractere, nome_arquivo[1000];

    // Solicita o nome do arquivo HTML ao usuário
    printf("Digite o nome do arquivo HTML: ");
    scanf("%s", nome_arquivo);

    // abertura do arquivo html
    fp1 = fopen(nome_arquivo, "r");

    if (fp1 == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    // Novo arquivo para as tags
    fp2 = fopen("novo.html", "w");

    if (fp2 == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    while ((caractere = fgetc(fp1)) != EOF)
    {
        // Verificar se a tag é vazia
        if (caractere == '<')
        {
            // Lendo o próximo caractere...
            caractere = fgetc(fp1);

            // Se o próximo caractere for '>', a tag é vazia
            if (caractere == '>')
            {
                continue;
            }
        }

        // Se o caractere não for uma tag HTML, é gravado no arquivo de saída
        if (caractere != '<' && caractere != '>')
        {
            fputc(caractere, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}

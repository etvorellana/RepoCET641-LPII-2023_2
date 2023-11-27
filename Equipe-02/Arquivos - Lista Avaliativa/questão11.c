#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*Faça um programa em C que leia 5 frases de, no máximo, 50 caracteres cada uma e
armazene-as em um arquivo. Antes de gravar cada frase no arquivo, é necessário
converter todas as suas letras para maiúsculas. O nome do arquivo será fornecido,
via teclado, pelo usuário. A seguir, feche o arquivo e reabra para leitura exibindo
todas as frases convertidas na tela.*/
#define MAX_FRASES 5
#define MAX_CARACTERES 50

int main() {
    char frases[MAX_FRASES][MAX_CARACTERES];
    char nomeArquivo[100];
    FILE *arquivo;

    // Ler o nome do arquivo fornecido pelo usuário
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Limpar o buffer do teclado após o scanf
    while (getchar() != '\n');

    // Abre o arquivo para escrita
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler as frases e gravar no arquivo
    printf("Digite as frases:\n");
    for (int i = 0; i < MAX_FRASES; i++) {
        printf("Frase %d: ", i + 1);

        // Usar fgets para ler a linha inteira
        fgets(frases[i], MAX_CARACTERES, stdin);

        // Remover o caractere de nova linha, se necessário
        frases[i][strcspn(frases[i], "\n")] = '\0';

        // Converter todas as letras para maiúsculas
        for (int j = 0; frases[i][j] != '\0'; j++) {
            frases[i][j] = toupper(frases[i][j]);
        }

        // Gravar a frase no arquivo
        fprintf(arquivo, "%s\n", frases[i]);
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Reabrir o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Exibir as frases convertidas na tela
    printf("\nFrases convertidas:\n");
    for (int i = 0; i < MAX_FRASES; i++) {
        fgets(frases[i], MAX_CARACTERES, arquivo);

        // Remover o caractere de nova linha, se necessário
        frases[i][strcspn(frases[i], "\n")] = '\0';

        printf("%s\n", frases[i]);
    }

    // Fechar o arquivo novamente
    fclose(arquivo);

    return 0;
}


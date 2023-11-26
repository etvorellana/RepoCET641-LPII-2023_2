#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE *arquivo;
    char nomeArquivo[100];
    char frase[5][51];  // 5 frases de ate 50 caracteres cada
    int i, j;

    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    // Remover \n
    if (nomeArquivo[strlen(nomeArquivo) - 1] == '\n') {
        nomeArquivo[strlen(nomeArquivo) - 1] = '\0';
    }

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("Digite a frase %d (ate 50 caracteres): ", i + 1);

        // Utiliza fgets para ler a linha, garantindo que nao ultrapasse 50 caracteres
        fgets(frase[i], sizeof(frase[i]), stdin);

        // Converte todas as letras para maiusculas
        for (j = 0; frase[i][j] != '\0'; j++) {
            frase[i][j] = toupper(frase[i][j]);
        }
        fprintf(arquivo, "%s", frase[i]);
    }

    fclose(arquivo);

    // Reabre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    // Exibe as frases convertidas na tela
    printf("\nFrases convertidas:\n");
    for (i = 0; i < 5; i++) {
        fgets(frase[i], sizeof(frase[i]), arquivo);
        printf("%s", frase[i]);
    }

    fclose(arquivo);
    return 0;
}
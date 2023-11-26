#include <stdio.h>

int main(){
    FILE *entrada, *saida;
    char nomeArquivoEntrada[100], nomeArquivoSaida[100];
    char caractere;

    printf("Digite o nome do arquivo HTML de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeArquivoSaida);

    entrada = fopen(nomeArquivoEntrada, "r");

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    saida = fopen(nomeArquivoSaida, "w");

    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        fclose(entrada);
        return 1;
    }

    // Remove as tags e escreve o conteudo no arquivo de saída
    int dentroTag = 0;
    caractere = fgetc(entrada);
    while(!feof(entrada)) {
        if (caractere == '<') {
            dentroTag = 1;
        } else if (caractere == '>') {
            dentroTag = 0;
        } else if (!dentroTag) {
            fprintf(saida, "%c", caractere);
        }
      caractere = fgetc(entrada);
    } 
  
    fclose(entrada);
    fclose(saida);

    printf("Tags removidas com sucesso. O conteudo foi salvo em %s.\n", nomeArquivoSaida);

    return 0;
}
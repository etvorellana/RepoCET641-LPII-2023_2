#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** geraImagem(int lin, int col) {
    int** imagem = (int**)malloc(lin * sizeof(int*));
    srand(time(NULL));

    for (int i = 0; i < lin; i++) {
        imagem[i] = (int*)malloc(col * sizeof(int));

        for (int j = 0; j < col; j++) {
            imagem[i][j] = rand() % 256; // Valores de intensidade da cor entre 0 e 255
        }
    }

    return imagem;
}

void liberaImagem(int** imagem, int lin) {
  for (int i = 0; i < lin; i++) {
    free(imagem[i]);
  }
  free(imagem);
  return;
}

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da imagem: ");
    scanf("%d", &colunas);
    printf("\n");

    int** imagem = geraImagem(linhas, colunas);

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("%3d ", imagem[i][j]);
            }
            printf("\n");
        }

        // Libera a memoria alocada para a imagem
        liberaImagem(imagem, linhas);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* geraImagemUni(int lin, int col) {
    int* imagem = (int*)malloc(lin * col * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            imagem[col * i + j] = rand() % 256;
        }
    }

    return imagem;
}

int getColor(int* img, int lin, int col, int i, int j) {
    return img[col * i + j];
}

int* histograma(int* img, int lin, int col) {
    int* hist = (int*)calloc(256, sizeof(int));

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            hist[img[col * i + j]]++;
        }
    }

    return hist;
}

int* filtroMedia(int* img, int lin, int col) {
    int* novaImagem = (int*)malloc(lin * col * sizeof(int));

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            int soma = 0;
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < lin && nj >= 0 && nj < col) {
                        soma += img[col * ni + nj];
                        count++;
                    }
                }
            }
            novaImagem[col * i + j] = soma / count;
        }
    }

    return novaImagem;
}

int main() {
    int lin = 480;
    int col = 640;
    int* imagem = geraImagem(lin, col);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%3d ", getColor(imagem, lin, col, i, j));
        }
        printf("\n");
    }

    int* hist = histograma(imagem, lin, col);

    for (int i = 0; i < 10; i++) {
        printf("Hist[%d]: %d\n", i, hist[i]);
    }
    for (int i = 246; i < 256; i++) {
        printf("Hist[%d]: %d\n", i, hist[i]);
    }
    for (int i = 123; i < 133; i++) {
        printf("Hist[%d]: %d\n", i, hist[i]);
    }

    int* imagemFiltrada = filtroMedia(imagem, linhas, colunas);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%3d ", getColor(imagemFiltrada, linhas, colunas, i, j));
        }
        printf("\n");
    }

    free(imagem);
    free(hist);
    free(imagemFiltrada);

    return 0;
}
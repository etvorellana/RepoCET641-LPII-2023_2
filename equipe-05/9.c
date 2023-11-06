#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar a cor de um pixel
struct Pixel {
    unsigned char r, g, b;
};

// Função para gerar uma imagem como um array de pixels
struct Pixel* geraImagem(int lin, int col) {
    struct Pixel* imagem = (struct Pixel*)malloc(lin * col * sizeof(struct Pixel));

    srand(time(NULL));
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            imagem[col * i + j].r = rand() % 256;
            imagem[col * i + j].g = rand() % 256;
            imagem[col * i + j].b = rand() % 256;
        }
    }

    return imagem;
}

// Função para obter a cor de um pixel específico da imagem
struct Pixel getColor(struct Pixel* img, int lin, int col, int i, int j) {
    return img[col * i + j];
}

// Função para calcular o histograma de um canal de cor específico
int* histograma(struct Pixel* img, int lin, int col, int channel) {
    int* hist = (int*)calloc(256, sizeof(int));

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            unsigned char color;
            if (channel == 0) {
                color = img[col * i + j].r;
            } else if (channel == 1) {
                color = img[col * i + j].g;
            } else {
                color = img[col * i + j].b;
            }
            hist[color]++;
        }
    }

    return hist;
}

// Função para aplicar o filtro de média na imagem
struct Pixel* filtroMedia(struct Pixel* img, int lin, int col) {
    struct Pixel* novaImagem = (struct Pixel*)malloc(lin * col * sizeof(struct Pixel));

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            unsigned int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int ni = i + x;
                    int nj = j + y;
                    if (ni >= 0 && ni < lin && nj >= 0 && nj < col) {
                        sum_r += img[col * ni + nj].r;
                        sum_g += img[col * ni + nj].g;
                        sum_b += img[col * ni + nj].b;
                        count++;
                    }
                }
            }
            novaImagem[col * i + j].r = (unsigned char)(sum_r / count);
            novaImagem[col * i + j].g = (unsigned char)(sum_g / count);
            novaImagem[col * i + j].b = (unsigned char)(sum_b / count);
        }
    }

    return novaImagem;
}

int main() {
    int linhas = 480;
    int colunas = 640;
    struct Pixel* imagem = geraImagem(linhas, colunas);

    // Mostrar os 25 pixels do canto superior esquerdo (submatriz de 5x5)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            struct Pixel pixel = getColor(imagem, linhas, colunas, i, j);
            printf("R:%3d G:%3d B:%3d ", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }

    // Calcular o histograma de cada canal de cor da imagem
    int* histR = histograma(imagem, linhas, colunas, 0);
    int* histG = histograma(imagem, linhas, colunas, 1);
    int* histB = histograma(imagem, linhas, colunas, 2);

    // Imprimir os 10 primeiros, 10 últimos e 10 valores centrais de cada histograma
    for (int i = 0; i < 10; i++) {
        printf("HistR[%d]: %d\n", i, histR[i]);
        printf("HistG[%d]: %d\n", i, histG[i]);
        printf("HistB[%d]: %d\n", i, histB[i]);
    }
    for (int i = 246; i < 256; i++) {
        printf("HistR[%d]: %d\n", i, histR[i]);
        printf("HistG[%d]: %d\n", i, histG[i]);
        printf("HistB[%d]: %d\n", i, histB[i]);
    }
    for (int i = 123; i < 133; i++) {
        printf("HistR[%d]: %d\n", i, histR[i]);
        printf("HistG[%d]: %d\n", i, histG[i]);
        printf("HistB[%d]: %d\n", i, histB[i]);
    }

    // Aplicar o filtro de média na imagem
    struct Pixel* imagemFiltrada = filtroMedia(imagem, linhas, colunas);

    // Mostrar os 25 pixels do canto superior esquerdo da nova imagem filtrada
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            struct Pixel pixel = getColor(imagemFiltrada, linhas, colunas, i, j);
            printf("R:%3d G:%3d B:%3d ", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }

    // Liberar a memória alocada
    free(imagem);
    free(histR);
    free(histG);
    free(histB);
    free(imagemFiltrada);

    return 0;
}
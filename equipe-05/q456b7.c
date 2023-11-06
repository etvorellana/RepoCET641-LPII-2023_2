#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para questao 4
int** geraImagem(int lin, int col) {
    int** imagem = (int**)malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++) {
        imagem[i] = (int*)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            imagem[i][j] = rand() % 256;
        }
    }
    return imagem;
}
// Função para questao 5
void liberaImagem(int** img, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        free(img[i]);
    }
    free(img);
}
// Função para queatao 6
int* histograma(int** img, int lin, int col) {
    int* hist = (int*)calloc(256, sizeof(int));

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            hist[img[i][j]]++;
        }
    }

    return hist;
}
// Função para questao 7
int** filtroMedia(int** img, int lin, int col) {
    int** novaImagem = (int**)malloc(lin * sizeof(int*));

    for (int i = 0; i < lin; i++) {
        novaImagem[i] = (int*)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            if (i > 0 && i < lin - 1 && j > 0 && j < col - 1) {
                
                novaImagem[i][j] = (img[i][j] + img[i - 1][j] + img[i + 1][j] + img[i][j - 1] + img[i][j + 1]) / 5;
            } else {
                novaImagem[i][j] = img[i][j];
            }
        }
    }

    return novaImagem;
}

// Função para quetao 7
void mostraPixelsSuperioresEsquerdos(int** img, int lin, int col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int lin = 480;
    int col = 640;
    
    //gera imagem (questao 4)
    int** imagem = geraImagem(lin, col);
    
   // Calcule o histograma(questao 6a)
    int* hist = histograma(imagem, lin, col);

    printf("Os 10 primeiros valores do histograma:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, hist[i]);
    }

    printf("Os 10 últimos valores do histograma:\n");
    for (int i = 246; i < 256; i++) {
        printf("%d: %d\n", i, hist[i]);
    }

    printf("Os 10 valores centrais do histograma:\n");
    for (int i = 123; i < 133; i++) {
        printf("%d: %d\n", i, hist[i]);
    }
    
    free(hist);
    
    // Mostre os 25 pixels do canto superior esquerdo da imagem(questao 7a)
    printf("Imagem:\n");
    mostraPixelsSuperioresEsquerdos(imagem, lin, col);

    // Aplique o filtro de média na imagem(questao 7b)
    int** novaImagem = filtroMedia(imagem, lin, col);

    // Mostre os 25 pixels do canto superior esquerdo da nova imagem filtrada (questao 7b)
    printf("Nova Imagem Filtrada:\n");
    mostraPixelsSuperioresEsquerdos(novaImagem, lin, col);

    // Libere a memória alocada(questao 5)
    liberaImagem(imagem, lin, col);
    liberaImagem(novaImagem, lin, col);

    return 0;
}
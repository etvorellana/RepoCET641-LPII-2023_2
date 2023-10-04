#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void histograma(int lin, int col, int img[lin][col], int hist[]);

int main() {
    srand(time(NULL));
    int lin = 16;
    int col = 16;
    int img[16][16];
    int hist[256];
  
    for (int i = 0; i < lin; i++){
      for (int j = 0; j < col; j++){
        img[i][j] = rand()%256;
        printf("%3d ",img[i][j]);
      }
      printf("\n");
    }

    printf("\n");
  
    histograma( lin, col, img, hist);

    for (int i = 0; i < 256; i++)
    {
        printf("Valor %d: %d\n", i, hist[i]);
    }

    return 0;
}

void histograma(int lin, int col,int img[lin][col],  int hist[]) {
    for (int i = 0; i < 256; i++)   //preenche todos os espacos com 0
      hist[i] = 0;

    for (int i = 0; i < lin; i++)   //pega um numero da matriz
      for (int j = 0; j < col; j++)
        ++hist[img[i][j]];
}

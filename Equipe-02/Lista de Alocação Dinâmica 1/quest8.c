#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* geraImagem(int lin, int col){
  int* image = (int*) malloc(lin * col * sizeof(int));

  for (int i = 0; i < lin * col; i++){
    image[i] = rand() % 256;
  }
  return image;
}

int* Histograma(int *img, int lin, int col){
  int* histograma = (int*) calloc(256, sizeof(int));

  for (int i = 0; i < lin * col; i++){
    histograma[img[i]]++;
  }
  return histograma;
}

int* filtroMedia(int *img, int lin, int col){
  int* newimg = geraImagem(lin, col);

  for (int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if (i == 0 || i == lin - 1 || j == 0 || j == col - 1) {
        newimg[i * col + j] = img[i * col + j];
      } else {
        newimg[i * col + j] = (img[(i - 1) * col + j] + img[(i + 1) * col + j] + img[i * col + (j - 1)] + img[i * col + (j + 1)]) / 4;
      }
    }
  }

  return newimg;
}

int getColor(int* img, int i, int j, int col){
  return img[i * col + j];
}

void imprimeSubmatriz(int* img, int col, int lin, int submatriz_lin, int submatriz_col){
  for (int i = 0; i < submatriz_lin; i++){
    for (int j = 0; j < submatriz_col; j++){
      printf("%d ", img[i * col + j]);
    }
    printf("\n");
  }
}

int main(void) {
  srand(time(NULL));

  int lin = 640, col = 480;
  int* image = geraImagem(lin, col);

  printf("Submatriz 5x5 no canto superior esquerdo: \n");
  imprimeSubmatriz(image, col, lin, 5, 5);

  int* histograma = Histograma(image, lin, col);

  printf("\nHistograma da imagem:\n");

  printf("\n10 primeiros valores do histograma:\n");
  for (int i = 0; i < 10; i++){
    printf("%d ", histograma[i]);
  }
  
  printf("\n\n10 valores centrais do histograma:\n");
  for (int i = 123; i <= 132; i++){
    printf("%d ", histograma[i]);
  }
  
  printf("\n\n10 ultimos valores do histograma:\n");
  for (int i = 246; i <= 255; i++){
    printf("%d ", histograma[i]);
  }

  int* newimage = filtroMedia(image, lin, col);

  printf("\n\nSubmatriz 5x5 no canto superior esquerdo apos filtro de media:\n");
  imprimeSubmatriz(newimage, col, lin, 5, 5);

  free(image);
  free(histograma);
  free(newimage);
  
  return 0;
}

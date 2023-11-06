
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define H 5

int** geraImg(int lin, int col);
void freeAll (int** mat, int lin);
void printMat (int** mat, int lin, int col);
int* histogram(int** mat, int lin, int col);
int** filtroMedia(int** img, int lin, int col);

int main(void) {
  int** img;
  int* hist;

  img = geraImg(480, 640);
  printMat(img, H, H);
  printf("\n");

  hist = histogram(img, 480, 640);
  printf("\nHistograma:\n");
  for(int i = 0; i < 10; i++)
      printf("%2d -> %2d %2d -> %2d %2d -> %2d\n", i, hist[i], i + 119, hist[i + 119], i + 246, hist[i + 246]);
  printf("\n>>>>>>> Filtered Image <<<<<<<<\n\n");

  int** imgF;
  int* histF;

  imgF = filtroMedia(img, 480, 640);
  printMat(imgF, H, H);
  printf("\n");

  histF = histogram(imgF, 480, 640);
  printf("\nHistograma:\n");
  for(int i = 0; i < 10; i++)
    printf("%2d -> %2d %2d -> %2d %2d -> %2d\n", i, histF[i], i + 119, histF[i + 119], i + 246, histF[i + 246]);

  free(hist);
  free(histF);
  freeAll(img, 480);
  freeAll(imgF, 480);

  return 0;
}

int** geraImg(int lin, int col){

  srand(time(NULL));
  int** mat;
  mat = (int**) malloc(sizeof(int*) * lin);
  for(int i = 0; i < lin; i++){
    mat[i] = (int*) malloc(sizeof(int) * col);
    for (int j = 0; j < col; j++)
      mat[i][j] = rand()%256;
  }

  return mat;
}

void freeAll (int** mat, int lin){
  for (int i = 0; i < lin; i++)
    free(mat[i]);
  free(mat);
  return;
}

void printMat (int** mat, int col, int lin){
  printf("SubMatrix 5 x 5 Up-Left Corner:\n");

  for(int i = 0; i < lin; i++){
    printf("|");
    for(int j = 0; j < col; j++)
      printf("%5d ", mat[i][j]);
    printf("|\n");
  }

  return;
}

int* histogram(int** mat, int lin, int col) {

  int* hist;
  hist = (int*) malloc(sizeof(int) * 256);

  for(int i = 0; i < lin; i++)
    for(int j = 0; j < col; j++){
      hist[mat[i][j]]++;
    }

  return hist;
}

int** filtroMedia(int** img, int lin, int col){
  int** mat;
  mat = (int**) malloc(sizeof(int*) * lin);
  for(int i = 0; i < lin; i++){
    mat[i] = (int*) malloc(sizeof(int) * col);
    for (int j = 0; j < col; j++) {
      if(i > 0 && i < (lin - 1) && j > 0 && j < (col - 1))
        mat[i][j] = (img[i][j] + img[i + 1][j] + img[i - 1][j] + img[i][j + 1] + img[i][j - 1])/5;
      else 
        mat[i][j] = img[i][j];
    }
  }
  return mat;
}

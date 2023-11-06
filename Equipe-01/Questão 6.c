#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 480
#define COLUNAS 640

int** geraImagem(int lin, int col);
int* histograma(int **img, int lin, int col);
void printHist(int *hist);
void modImagem(int **img, int lin1, int col1,int lin2, int col2, int lin3, int col3);
void liberaImagem(int** img, int lin, int col);


int main(void) {
  int** imagem;
  int* hist;
  int lin = LINHAS;
  int col = COLUNAS;

  imagem = geraImagem(lin,col);
  hist = histograma(imagem, lin, col);
  printHist(hist);
  modImagem(imagem, lin, col,200,300,100,100);
  hist = histograma(imagem, lin, col);
  printf("\n\n");
  printHist(hist);
  liberaImagem(imagem,lin,col);
  free(hist);

  return 0;
}

int** geraImagem(int lin, int col){
  srand(time(NULL));
  if(lin < 1 || col < 1) return NULL;

  int** ar = (int**) malloc(sizeof(int*)*lin);

  for(int i = 0; i<lin; i++){
    ar[i] = (int*) malloc(sizeof(int)*col);
    for(int j = 0; j<col; j++)
      ar[i][j] = rand()%256;
  }

  return ar;
}

int* histograma(int **img, int lin, int col){

  int* hist = (int*) malloc(sizeof(int)*256);

  for(int i =0; i<lin; i++){
    for(int j =0; j<col; j++)
      hist[img[i][j]]++;
  }

  return hist;
}

void printHist(int *hist){

  for(int i = 0; i<10;i++)
    printf("Pixel %d: %d vezes\n",i,hist[i]);
  for(int i = 123; i<133;i++)
    printf("Pixel %d: %d vezes\n",i,hist[i]);
  for(int i = 246; i<256;i++)
    printf("Pixel %d: %d vezes\n",i,hist[i]);

  return;
}

void modImagem(int **img, int lin1, int col1,int lin2, int col2, int lin3, int col3){

  for(int i =0; i<lin1;i++){
    for(int j=0; j<col1;j++)
      img[i][j] = 255;
  }

  int posi=(lin1-lin2)/2;  
  int posj=(col1-col2)/2; 

  for(int i=posi; i< posi+lin2; i++){
    for(int j=posj; j< posj+col2; j++)
      img[i][j] = 125;
  }

  posi = posi+((lin2-lin3)/2);
  posj = posj+((col2-col3)/2);

  for(int i=posi; i< posi+lin3; i++){
    for(int j=posj; j< posj+col3; j++)
      img[i][j] = 0;
  }

  return;
}

void liberaImagem(int** img, int lin, int col){

  for(int i =0; i<lin;i++){
    free(img[i]);
  }
  free(img);

  return;
}


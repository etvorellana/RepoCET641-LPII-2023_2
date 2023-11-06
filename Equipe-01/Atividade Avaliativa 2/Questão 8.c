#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* geraImagem(int lin, int col);
int* histograma(int *img, int lin, int col);
int getColor(int* img, int col, int i, int j);
int* filtroMedia(int *img, int lin, int col);
void printaHistograma(int* histograma);
void printaMatriz(int* array,int col);


int main(void) {
  int *vetorMain, *histMain, *vetorFiltro;
  int lin = 480, col = 640, i, j, pixel;
  vetorMain = geraImagem(lin, col);
  printf("Imagem gerada!\n");
  printf("Digite a linha onde está o pixel que deseja salvar: ");
  scanf("%d", &i);
  printf("Digite a coluna onde está o pixel que deseja salvar: ");
  scanf("%d", &j);
  pixel = getColor(vetorMain,col, i, j);
  histMain = histograma(vetorMain, lin, col);
  vetorFiltro = filtroMedia(vetorMain, lin, col);
  printf("\n\n\nPixel salvo: %d.\n", pixel);
  printf("Pixel que está na linha %d e coluna %d: %d.", i, j, vetorMain[col*i+j]);
  printf("\n\n\nSub-Matriz da imagem gerada:\n\n\n");
  printaMatriz(vetorMain,col);
  printf("\n");
  printaHistograma(histMain);
  printf("\n__________________________________________\n\n\n");
  printf("Sub-Matriz após aplicação do filtro:\n\n\n");
  printaMatriz(vetorFiltro,col);
  free(vetorMain);
  free(histMain);
  free(vetorFiltro);
  return 0;
}
int* geraImagem(int lin, int col){
  int* vetor;
  vetor = (int *) malloc(sizeof(int)*lin*col);
  srand(time(NULL));
  for(int i = 0; i < lin*col; i++)
    vetor[i] = rand() % 256;
  return vetor;
}
int* histograma(int *img, int lin, int col){
  int *histograma;
  histograma = (int*) malloc(sizeof(int*) * 256);
  for(int i = 0; i < lin*col; i++)
    histograma[img[i]]++;
  return histograma;
}
int getColor(int* img, int col,int i, int j){
  return img[col*i+j];
}
int* filtroMedia(int *img, int lin, int col){
  int *imgFiltro;
  imgFiltro = (int*) malloc(sizeof(int)*lin*col);
  for(int i = 0; i < lin; i++){
    for(int j = 0; j < col; j++){
      if(i != 0 && j != 0 && i != lin - 1 && j != col - 1)
        imgFiltro[col*i + j] = (getColor(img,col, i, j) + getColor(img,col, i+1, j) + 
                                getColor(img,col, i-1, j) + getColor(img,col, i, j+1) +
                                getColor(img,col, i, j-1) ) / 5;
      else
        imgFiltro[col*i + j] = img[col*i + j];
    }
  }
  return imgFiltro;
}
void printaMatriz(int* array,int col){
  for(int i = 0; i < 5; i++){
    printf("|");
    for(int j = 0; j < 5; j++)
      printf("%8d", array[col*i+j]);
    printf("     |\n");
  }
  return;
}
void printaHistograma(int* histograma){
  for(int i = 0; i < 256; i++){
    printf("Pixel %d aparece: %d vezes.\n", i, histograma[i]);
    if(i == 9){
      i = 122;
      printf("\n");
    }  
    if(i == 132){
      i = 245;
      printf("\n");
    }  
  }
  return;
}
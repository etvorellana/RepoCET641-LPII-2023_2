#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** geraImagem(int lin, int col){

  int** image = (int**) malloc(lin * sizeof(int*)); //alocando memoria para o ponteiro de ponteiros

  for(int i=0;i<lin;i++){

    image[i] = (int*) malloc(col * sizeof(int)); //alocando memoria de cada coluna

    for(int j=0;j<col;j++) {

      image[i][j] = rand() % 256; //preenchendo a matriz com valores aleatorios entre 0 e 255
    }
  }
  return image; //retornando imagem
}

void liberaImagem(int** img, int lin, int col){

  for(int i=0;i<lin;i++)
    free(img[i]); //liberando memoria de cada coluna

  free(img); //liberando memoria do ponteiro de ponteiros
  return;
}

int* Histograma(int **img, int lin,
int col){

  int* histograma = (int*) calloc(256, sizeof(int)); //alocando memoria para o histograma

  for(int i=0;i<lin;i++){
    for(int j=0;j<col;j++) histograma[img[i][j]]++; //incrementando o histograma com a quantidade de vezes que aparece cada valor
  }
  return histograma;

}

int** filtroMedia(int
**img, int lin, int col){

  int** newimg = geraImagem(lin,col);

  for(int i=0; i<lin;i++){
    for(int j=0; j<col;j++)
      if(i==0 || i==lin-1 || j==0 || j==col-1) newimg[i][j] = img[i][j]; //se o pixel estiver na borda ele nao tem o valor alterado
      else newimg[i][j] = (img[i+1][j] + img[i-1][j] + img[i][j+1] + img[i][j-1])/4;

  }

  return newimg;

}

int main(void) {
  srand(time(NULL));

  int lin=640, col=480;
  int** image = geraImagem(lin, col);

  printf("Matriz 5x5 da matriz alocada na memoria: \n");
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++)
    printf(" %.3d ", image[i][j]); printf("\n");
  }

  int** imagenova = filtroMedia(image, lin, col);

  printf("Matriz 5x5 da matriz ""filtro"": \n");
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++)
    printf(" %.3d ", imagenova[i][j]); printf("\n");
  }


  liberaImagem(image, lin, col);
  liberaImagem(imagenova, lin, col);



  return 0;
}
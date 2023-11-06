#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **aloca(int **vet,int lin,int col);
void liberaImagem(int **vet,int lin);

int main(void){

  srand(time(NULL));
  int lin = 480;
  int col = 640;
  int **vet = NULL;
  vet = aloca(vet,lin,col);

  for(int i = 0;i<lin;i++){
    for(int j = 0;j<col;j++){
     
      vet[i][j] = 1+rand()%255;
    }
  }

  for(int i = 0;i<5;i++){
    for(int j = 0;j<5;j++){

      printf("\nO valor de vet[%d][%d]: %d\n",i,j,vet[i][j]);
    }
  }
  liberaImagem(vet,lin);
  return 0;
}

int **aloca(int **vet,int lin,int col){

  vet = (int**) malloc(lin*sizeof(int*));
 
  for(int i = 0;i<lin;i++){
    vet[i] = (int*) malloc(col*sizeof(int));
  }
  
 return vet;
}

void liberaImagem(int **vet,int lin){

  for(int i = 0;i<lin;i++){

    free(vet[i]);
  }
  free(vet);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **geraImagem(int lin,int col);
void libera(int**vet,int lin);

int main(void){

  srand(time(NULL));
  
  int lin,col;
  int **vet = NULL;
  printf("\nEntre com o número de linhas: ");
  scanf("%d",&lin);
  printf("\nEntre com o número de colunas: ");
  scanf("%d",&col);
  
  vet = geraImagem(lin,col);
  
  for(int i = 0;i<lin;i++){
    for(int j = 0;j<col;j++){
      printf("\nO valor de vet[%d][%d]: %d",i,j,vet[i][j]);
    }
  }
  
 libera(vet,lin);
  return 0;
}

int **geraImagem(int lin,int col){

  int **imagem = (int**) malloc(lin*sizeof(int*));
  for(int i = 0;i<lin;i++){
    imagem[i] = (int*) malloc(col*sizeof(int));
  }
  
  for(int i = 0;i<lin;i++){
    for(int j = 0;j<col;j++){
      imagem[i][j] = 1+rand()%255;
    }
  }
  return imagem;
}

void libera(int**vet,int lin){

  for(int i = 0;i<lin;i++){

    free(vet[i]);
  }
  free(vet);
}

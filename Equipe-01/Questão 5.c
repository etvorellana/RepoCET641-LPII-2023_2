#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** geraImagem(int lin, int col);
int** alocaMatriz(int lin, int col);
void liberaMatriz(int lin, int** matriz);
void printaMatriz(int** matriz);

int main(void) {
  int** matrizMain;
  int lin = 480, col = 640;
  matrizMain = geraImagem(lin, col);
  printaMatriz(matrizMain);
  liberaMatriz(lin, matrizMain);
  return 0;
}
int** alocaMatriz(int lin, int col){
  int** geraMatriz;
  geraMatriz = (int**) malloc(sizeof(int*) * lin);
  for(int i = 0; i < lin; i++)
    geraMatriz[i] = (int*) malloc(sizeof(int) * col);
  return geraMatriz;
}
void liberaMatriz(int lin, int** matriz){
  for(int i = 0; i < lin; i++)
    free(matriz[i]);
  free(matriz);
  return;
}
int** geraImagem(int lin, int col){
  int** matriz;
  matriz = alocaMatriz(lin, col);
  srand(time(NULL));
  for(int i = 0; i < lin; i++)
    for(int j = 0; j < col; j++)
      matriz[i][j] = rand() % 256;
  return matriz;
}
void printaMatriz(int** matriz){
  printf("Sub-matriz 5x5 da Matriz gerada: \n");
  for(int i = 0; i < 5; i++){
    printf("|");
    for(int j = 0; j < 5; j++)
      printf("%8d" , matriz[i][j]);
    printf("|\n");
  }  
  return;
}
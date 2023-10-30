#include <stdio.h>

/*
Crie uma função que recebe um array bidimensional com valores inteiros entre 0 e 255, 
dois inteiros contendo o número de linhas e colunas do array, e um array de inteiros 
(void histograma(int img[ ][ ], int lin, int col,int hist[ ])) e retorna, no array de inteiros, 
quantas vezes aparece na matriz cada uma dos 256 possíveis valores. 
*/


void histograma(int img[2][3], int lin, int col, int hist[]){
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      for (int k = 0; k < 255; k++) {
        if (img[i][j] == k)
          hist[k]++;
      }
    }
  }
}

int main(void) {
  int matz[2][3] = {{0,1,2}, {1,3,4}};
  int cont[256]= {0};
  histograma(matz, 2, 3, cont);
  
  for (int l = 0; l < 255; l++) {
    printf("Número %d: %d ", l, cont[l]);
    if ((l % 5) == 0) printf("\n");
  }

  return 0;
}
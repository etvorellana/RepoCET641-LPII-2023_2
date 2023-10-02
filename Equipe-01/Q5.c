#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int maxValue(int *lin, int *col, int img[*lin][*col]);

int main(void){
    srand(time(NULL));
    int lin, col;
    int img[N][N];
    lin = col = N;
  
    //Preenchendo os valores da matriz:
  
    for(int i = 0; i < lin; i++){
      printf("|");
        for(int j = 0; j < col; j++){
          img[i][j] = rand()%256;
          printf("%5d ", img[i][j]);
        }
      printf("|\n");
    }
  
    int max = maxValue(&lin, &col, img);
          
    printf("O valor maximo da array bidimensional é %d e se encontra na posição (%d, %d) do array bidimensional.", max, lin, col);
}

int maxValue(int *lin, int *col, int img[*lin][*col]){
    int max = img[0][0];
    int linMax = 0;
    int colMax = 0;
    for(int i = 0; i < *lin; i++){
        for(int j = 0; j < *col; j++){
            if(img[i][j] > max){
            max = img[i][j];
            linMax = i;
            colMax = j;
            }
        }
    }
    *lin = linMax;
    *col = colMax;
    return max;
}
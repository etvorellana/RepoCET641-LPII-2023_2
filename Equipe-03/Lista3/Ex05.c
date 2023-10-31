#include <stdio.h>

/*
Crie uma função que recebe um array bidimensional com valores inteiros entre 0 e 255, 
dois inteiros, passados por referência, contendo o número de linhas e colunas do array,  
(int maxValue(int img[ ][ ], int *lin, int *col), e retorna qual o valor máximo do array e 
qual a primeira posição em que ele aparece quando a matriz é percorrida em ordem crescente 
do número de linhas e colunas. A posição, qual a linha e a coluna do valor máximo na matriz, 
deve ser retornada nos parâmetros lin e col. 
*/


int maxValue(int img[20][20] , int *lin, int *col){
    int max = 0;
    int linp = 0;
    int colp = 0;
    for(int c = 0; c < *lin; c++){
        for (int d = 0; d < *col; d++){
            if (img[c][d] > max){
                max = img[c][d];
                linp = c;
                colp = d;
            }
        }
    }
    *lin = linp;
    *col = colp;
    return max;
}


int main(void){
    int array[20][20] = {{0,1,2,3,4,5,6,7,8,9,10,254,30,25,254,25,239,0,23,20}};
    int lin = 20;
    int col = 20;
    printf("\nMaior número: %d ", maxValue(array, &lin, &col));
    printf("na linha: %d e coluna: %d\n", lin, col);

    
    return 0;
}

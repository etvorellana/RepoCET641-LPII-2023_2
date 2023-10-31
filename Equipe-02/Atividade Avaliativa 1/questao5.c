/* QUESTAO 5 Crie uma função que recebe um array bidimensional
com valores inteiros entre 0 e 255, dois inteiros, passados por referência,
contendo o número de linhas e colunas do array,
(int maxValue(int img[ ][ ], int *lin, int *col),
e retorna qual o valor máximo do array e qual a primeira posição
em que ele aparece quando a matriz é percorrida em ordem crescente do número de linhas e colunas.
A posição, qual a linha e a coluna do valor máximo na matriz, deve ser retornada nos parâmetros lin e col.    
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define vlin 4
#define vcol 4

int maxValue(int img[vlin][vcol], int *lin, int *col);

int main(void){
    
    int array[vlin][vcol];
    int lin, col;

    srand(time(NULL));

    printf("\nPreenchendo a matriz [%d][%d] com valores aleatorios...", vlin, vcol);
    for (int i=0;i<vlin;i++){
        for(int j=0;j<vcol;j++) {
        array[i][j] = rand() % 255;
        printf("\nElemento [%d][%d] = %d", i, j, array[i][j]);
        }
    };

    printf("\n\nValor maximo do array: %d", maxValue(array, &lin, &col));
    printf("\nElemento que esta na linha %d e coluna %d", lin, col);


    return 0;
}

int maxValue(int img[vlin][vcol], int *lin, int *col){

int vmax=0;

    for(int i=0;i<vlin;i++){
        for(int j=0;j<vcol;j++){
            if(img[i][j]>vmax) 
            {vmax = img[i][j];
            *lin = i;
            *col = j;
            }
        }
    }
    
    return vmax;
}

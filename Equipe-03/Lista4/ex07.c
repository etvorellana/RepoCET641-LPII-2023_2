#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **aloca(int **img, int lin, int col);
void preenche(int **img, int lin, int col);
int **filtroMedia(int **img, int lin, int col);

int main(void){

    srand(time(NULL));
    int lin = 480;
    int col = 640;
    int **img = NULL;
    int **filter = NULL;

    img = aloca(img, lin, col);
    preenche(img, lin, col);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("\nO valor de img[%d][%d]: %d\n", i, j, img[i][j]);
        }
    }

    printf("\n");
    printf("\n--------------------\n");

    filter = aloca(filter, lin, col);
    filter = filtroMedia(img, lin, col);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("\nO valor de filter[%d][%d]: %d\n", i, j, filter[i][j]);
        }
    }
    return 0;
}

int **aloca(int **img, int lin, int col){

    img = (int **)malloc(lin * sizeof(int *));
    for (int i = 0; i < lin; i++){

        img[i] = (int *)malloc(col * sizeof(int));
    }

    return img;
}

void preenche(int **img, int lin, int col){

    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){

            img[i][j] = 1 + rand() % 255;
        }
    }
}

int **filtroMedia(int **img, int lin, int col){

    for (int i = 1; i < lin - 1; i++){
        for (int j = 1; j < col - 1; j++){
            img[i][j] = (img[i][j] + img[i + 1][j] + img[i - 1][j] + img[i][j + 1] + img[i][j - 1]) / 5;
        }
    }
    return img;
}
#include <stdio.h>
#include <stdlib.h>


int **aloca(int **img, int lin, int col){

    img = (int **)malloc(lin * sizeof(int *));
    for (int i = 0; i < lin; i++){

        img[i] = (int *)malloc(col * sizeof(int));
    }

    return img;
}

int *histograma(int **vet,int lin,int col){

  int* histo = (int*) malloc(256*sizeof(int));
  
  for(int i = 0;i<256;i++){
    
    histo[i] = 0;
    
  }
  
  for(int  i = 0; i<lin; i++){
    for(int j = 0; j<col; j++){
        histo[vet[i][j]]++;
    }
  }
  return histo;
}

int main (void){
    int lin = 480,col = 640;
    int **img = aloca(NULL , lin, col);
    
    int metadej = col / 2;
    int metadei = lin / 2;
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            img[i][j] = 255;
            if ((j > metadej - 300 /2) && (j <= metadej + 300 /2)){
                if ((i > metadei - 200 /2) && (i <= metadei + 200 /2)){
                    img[i][j] = 125;
                    if ((j > metadej - 100 /2) && (j <= metadej + 100 /2)){
                        if ((i > metadei - 100 /2) && (i <= metadei + 100 /2)){
                            img[i][j] = 0;
                        }
                    }
                }
            }
        }
    }

    int* histo = histograma(img, lin, col);

    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", img[i][j]);
            if (i > 0 && j % 640 == 0){
                printf("\n");
            }
        }
    }
    
    for(int j = 0;j< 256;j++){
            if (j < 10 || (j >= 123 && j <= 132 ) || (j >= 246 && j <= 255 ))
            printf("O valor de histo[%d] %d\n",j , histo[j]);
        }

    free(img);

    // ./"ex06" > img.txt
    return 0;
}
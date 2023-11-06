#include <stdio.h>
#include <stdlib.h>

int **geraImagemArray(int lin,int col){
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

int* geraImagem(int lin, int col){
    int **imagem = (int**) malloc(lin*sizeof(int*));
    for(int i = 0;i<lin;i++){
        imagem[i] = (int*) malloc(col*sizeof(int));
    }
    
    for(int i = 0;i<lin;i++){
        for(int j = 0;j<col;j++){
            imagem[i][j] = 1+rand()%255;
        }
    }
    // Considerando que seja necessário criar um bidimensional nessa função

    int *uni = (int*) malloc(col * lin * sizeof(int));
    for(int i = 0; i < lin; i++){
        for(int j = 0;j<col;j++){
            uni[col * i + j] = imagem[i][j];
        }
    }
    return uni;
}

int getColor(int* img, int i, int j){
    return img[i];
}

int* histograma(int *img, int lin, int col){

  int* histo = (int*) malloc(256*sizeof(int));

  for(int i = 0; i < 256; i++){
    histo[i] = 0;
  }
  
  for(int  i = 0;i<lin;i++){
      histo[img[i]]++;
  }
  return histo;
}

int* filtroMedia(int *img, int lin, int col){
    for (int i = 1; i < lin - 1; i++){
        img[i] = (img[i - 1] + img[i] + img[i + 1]) / 3;
    }
    return img;
}


int main (void){
    int lin,col;
    int *uni = NULL;
    int *histo = NULL;
    int *filter = NULL;
    printf("\nEntre com o número de linhas: ");
    scanf("%d",&lin);
    printf("\nEntre com o número de colunas: ");
    scanf("%d",&col);
    
    //vet = geraImagemArray(lin,col);
    uni = geraImagem(lin, col);
    
    filter = filtroMedia(uni, lin, col);
    for(int i = 0 ; i < col * lin;i++){
            for (int j = 0; j < 5; j++){
                printf("O valor de uni[%d]: %d\n",j + i,uni[j + i]);
            }
        i = i + col;
    }
    
    histo = histograma(uni, lin, col);
    for(int j = 0;j< 256;j++){
            if (j < 10 || (j >= 123 && j <= 132 ) || (j >= 246 && j <= 255 ))
            printf("O valor de histo[%d] %d\n",j , histo[j]);
        }

    for(int i = 0 ; i < col * lin;i++){
            for (int j = 0; j < 5; j++){
                printf("O valor de filter[%d]: %d\n",j + i,filter[j + i]);
            }
        i = i + col;
    }
}

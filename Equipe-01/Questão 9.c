#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define LINHAS 480
#define COLUNAS 640

struct Pixel{
  unsigned char R;
  unsigned char G;
  unsigned char B;
};

typedef struct Pixel pixel;

pixel* geraImagem(int lin, int col);
void printa5x5(pixel* img, int col);
int* histograma(pixel *img, int lin, int col, int chanel);
void printHist(int *hist, char chanel);
pixel* filtroMedia(pixel *img, int lin, int col);

int main(void) {
  pixel *imagem, *filtrada;
  int* hist;
  int lin = LINHAS;
  int col = COLUNAS;

  imagem = geraImagem(lin,col);
  printa5x5(imagem, col);
  printf("\n\n");
  hist = histograma(imagem,lin,col,'R');
  printHist(hist,'R');
  printf("\n\n");
  hist = histograma(imagem,lin,col,'G');
  printHist(hist,'G');
  printf("\n\n");
  hist = histograma(imagem,lin,col,'B');
  printHist(hist,'B');
  printf("\n\n");
  filtrada = filtroMedia(imagem,lin,col);
  printa5x5(filtrada, col);

  free(filtrada);
  free(imagem);
  free(hist);

  return 0;
}

pixel* geraImagem(int lin, int col){

  srand(time(NULL));
  int tam = lin*col;
  pixel* img = (pixel*) malloc(sizeof(pixel)*tam);

  for(int i =0; i<tam;i++){
    img[i].R = rand()%256;
    img[i].G = rand()%256;
    img[i].B = rand()%256;
  }

  return img;
}

void printa5x5(pixel* img, int col){
  for(int i = 0; i<5;i++){
    for(int j = 0;j<5;j++)
      printf("%03d / %03d / %03d\t\t"
        ,img[col*i+j].R,img[col*i+j].G,img[col*i+j].B);
    printf("\n");
  }
}

pixel getColor(pixel* img,int col, int i, int j){
  return img[col*i+j];
}

int* histograma(pixel *img, int lin, int col, int chanel){
  int* hist = (int*) malloc(sizeof(int)*256);
  int tam = lin*col;

  if(chanel == 'R' || chanel == 'r')
    for(int i =0; i<tam; i++)
        hist[img[i].R]++;

  else if(chanel == 'G' || chanel == 'g')
    for(int i =0; i<tam; i++)
        hist[img[i].G]++;

  else if (chanel == 'B' || chanel == 'b')
    for(int i =0; i<tam; i++)
        hist[img[i].B]++;

  else {
    free(hist);
    hist = NULL;
  }

  return hist;
}

void printHist(int *hist, char chanel){

  printf("\t\tHISTOGRAMA - CANAL %c\n\n",toupper(chanel));

  for(int i = 0; i<10;i++)
    printf("Pixel %d: %d vezes\n",i,hist[i]);
  for(int i = 123; i<133;i++)
    printf("Pixel %d: %d vezes\n",i,hist[i]);
  for(int i = 246; i<256;i++)
    printf("Pixel %d: %d vezes\n",i,hist[i]);

  return;
}

pixel* filtroMedia(pixel *img, int lin, int col){

  pixel* fil = (pixel*) malloc(sizeof(pixel)*lin*col);
  pixel aux[5];

  for(int i = 0;i< lin;i++){
    for(int j = 0;j< col;j++){
      if(i != 0 && j != 0 && i != (lin-1) && j!= (col-1)){

        aux[0] = getColor(img,col,i,j);
        aux[1] = getColor(img,col,i+1,j);
        aux[2] = getColor(img,col,i-1,j);
        aux[3] = getColor(img,col,i,j+1);
        aux[4] = getColor(img,col,i,j-1);

        fil[i*col+j].R = (aux[0].R + aux[1].R + aux[2].R + aux[3].R + aux[4].R)/5;
        fil[i*col+j].G = (aux[0].G + aux[1].G + aux[2].G + aux[3].G + aux[4].G)/5;
        fil[i*col+j].B = (aux[0].B + aux[1].B + aux[2].B + aux[3].B + aux[4].B)/5;

      }
      else fil[i*col+j] = img[i*col+j];

    }
  }

  return fil;
}
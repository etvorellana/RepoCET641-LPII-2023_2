#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pixel{
  unsigned char r;
  unsigned char g;
  unsigned char b;

}; typedef struct pixel Pixel;

Pixel* geraImagem(int lin, int col){

  Pixel* image = (Pixel*) malloc(lin*col * sizeof(Pixel)); 

  for(int i = 0; i < lin; i++){
    
    for(int j = 0; j < col; j++){
      
      image[i*col + j].r = rand()%256;
      image[i*col + j].g = rand()%256;
      image[i*col + j].b = rand()%256;
    }
  }
  
  return image; //retornando imagem
}

//c. Implemente uma nova versão da função do exercício 6 (int* histograma(int *img, int lin, int col)) . 

int* Histograma(Pixel *img, int lin, int col, char chanel){

  int* histograma = (int*) calloc(256, sizeof(int)); //alocando memoria para o histograma

  for(int i = 0; i < lin; i++){

    for(int j = 0; j < col; j++){

      if(chanel == 'r'){
        histograma[img[i*col + j].r]++;
      } else if(chanel == 'g'){
        histograma[img[i*col + j].g]++;
      } else if(chanel == 'b'){
        histograma[img[i*col + j].b]++;
      }
    }
  }

  return histograma;
}

// d.
Pixel* filtroMedia(Pixel *img, int lin, int col){
  Pixel* newimg = geraImagem(lin,col);

  for(int i=0; i<lin;i++){
    for(int j=0; j<col;j++){
      if(i==0 || i==lin-1 || j==0 || j==col-1) 
        newimg[i*col+j] = img[i*col+j]; //se o pixel estiver na borda ele nao tem o valor alterado
      else {
        newimg[i*col+j].r = (img[(i-1)*col+j].r + img[(i+1)*col+j].r + img[i*col+(j-1)].r + img[i*col+(j+1)].r)/4;
        newimg[i*col+j].g = (img[(i-1)*col+j].g + img[(i+1)*col+j].g + img[i*col+(j-1)].g + img[i*col+(j+1)].g)/4;
        newimg[i*col+j].b = (img[(i-1)*col+j].b + img[(i+1)*col+j].b + img[i*col+(j-1)].b + img[i*col+(j+1)].b)/4;
      }
    }
  }

  return newimg;
}



// b. Crie uma função que retorna a cor de um pixel específico de uma imagem armazenada como um array (int getColor(int* img, int i, int j)); 

Pixel getColor(Pixel* img, int i, int j, int col){
  return img[i*col+j];
}

int main(void) {
  srand(time(NULL));

  int lin=640, col=480;
  Pixel* image = geraImagem(lin, col);

  printf("Submatriz 5x5 no canto superior esquerdo: \n");
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){

    printf("(%.3d ", image[i*col+j].r);
    printf(" %.3d ", image[i*col+j].g);
    printf(" %.3d)", image[i*col+j].b);
    }
  }

  int *histoR = Histograma(image, lin, col, 'r');
  int *histoG = Histograma(image, lin, col, 'g');
  int *histoB = Histograma(image, lin, col, 'b');

  printf("\n\nHistograma RGB: \n");


printf("Primeiros 10 valores: \n");
for(int i = 0; i < 10; i++){
  printf("(%d ", i);
  printf("%d ", histoR[i]);
  printf("%d ", histoG[i]);
  printf("%d)\n", histoB[i]);
}


printf("\nUltimos 10 valores: \n");
for(int i = 256 - 10; i < 256; i++){
  printf("(%d ", i);
  printf("%d ", histoR[i]);
  printf("%d ", histoG[i]);
  printf("%d)\n", histoB[i]);
}


printf("\nOs 10 Valores centrais: \n");
for(int i = (256 - 10) / 2; i < (256 - 10) / 2 + 10; i++){
  printf("(%d ", i);
  printf("%d ", histoR[i]);
  printf("%d ", histoG[i]);
  printf("%d)\n", histoB[i]);
}
  
  Pixel *newimage = filtroMedia(image, lin, col);

  printf("Submatriz  5x5 no canto superior esquerdo, filtrada: \n");
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){

    printf("(%.3d ", newimage[i*col+j].r);
    printf(" %.3d ", newimage[i*col+j].g);
    printf(" %.3d)", newimage[i*col+j].b);
    }
  }

  
  free(image);
  free(histoR);
  free(histoG);
  free(histoB);
  free(newimage);
  
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

Pixel* geraImagem(int lin, int col){

    Pixel *imagem = (Pixel*) malloc(lin*sizeof(Pixel));
    for(int i = 0;i<lin;i++){
        imagem->r = 1+rand()%255;
        imagem->g = 1+rand()%255;
        imagem->b = 1+rand()%255;
    }

  return imagem;
}




int main(void){
    geraImagem(640, 480);


    return 0;
}
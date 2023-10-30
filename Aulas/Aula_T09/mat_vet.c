#include <stdio.h>
#include <stdlib.h>

struct pixel{
    unsigned char r, g, b;
};

typedef struct pixel Pixel;

int main(int argc, char const *argv[])
{
    
    printf("O valor de argc = %d\n", argc);
    for(int i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    unsigned char **M;
    unsigned char *Mv;

    Pixel* img;
    img = (Pixel*)malloc(480 * 640 * sizeof(Pixel));

    img[5 * 640 + 7].r = 255;
    img[5 * 640 + 7].g = 255;
    img[5 * 640 + 7].b = 255;
    
    int lin, col;
    if (argc == 1){
        lin = 480;
        col = 640;
    }else if (argc == 2){
        lin = atoi(argv[1]);
        if(lin == 0) lin = 480;
        col = 640;
    }else{
        lin = atoi(argv[1]);
        if(lin == 0) lin = 480;
        col = atoi(argv[2]);
        if(col == 0) col = 640;
    }
    printf("lin = %d, col = %d\n", lin, col);
    Mv = (unsigned char *)malloc(lin * col * sizeof(unsigned char));
    M = (unsigned char **)malloc(lin * sizeof(unsigned char *));
    for(int i =0; i < lin; i++)
        M[i] = &Mv[i * col];
    
    int i = 5, j = 7;
    M[i][j] = 255;
    Mv[i * col + j] = 255;

    free(M);
    free(Mv);
    return 0;
}

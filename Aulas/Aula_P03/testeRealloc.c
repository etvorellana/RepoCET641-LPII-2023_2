#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int *vetor; 
    
    
    
    //...
    
    vetor = (char*) malloc(40);




    float *x =  calloc(10, sizeof(float));
    float y[10];
    
    for(int i = 0; i < 5; i++)
    {
        printf("%d - %.2f\n", vetor[i], x[i]);
    }

    printf("--------------\n");
    printf("tamanho de x: %d\n", sizeof(x));
    printf("tamanho de y: %d\n", sizeof(y));
    printf("tamanho de vetor: %d\n", sizeof(vetor));
    printf("tamanho de x[0]: %d\n", sizeof(x[0]));
    printf("tamanho de vetor[0]: %d\n", sizeof(vetor[0]));
    printf("tamanho de *x: %d\n", sizeof(*x));
    printf("tamanho de *vetor: %d\n", sizeof(*vetor));
    
    
    for(int i = 0; i < 5; i++)
    {
        vetor[i] = i;
        x[i] = i/2.0;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d - %.2f\n", vetor[i], x[i]);
    }

    x = (float *) realloc(x, 10 * sizeof(float));

    for(int i = 0; i < 10; i++)
    {   
        if(i >= 5)
        {
            x[i] = i/2.0;
        }
        printf("%.2f\n", x[i]);
    }

    x = (float*) realloc(x, 5 * sizeof(float));
    printf("--------------\n");
    for(int i = 0; i < 5; i++)
    {   
        printf("%.2f\n", x[i]);
    }

    free(vetor);
    free(x);
    return 0;
}

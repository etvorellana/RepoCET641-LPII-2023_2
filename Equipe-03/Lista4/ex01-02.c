#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 5


//1- a)
double* somaVet(double* vetA, double* vetB, int dim){
    double* soma = (double*) malloc(sizeof(double) * dim);
    for (int c = 0; c < dim; c++){
        soma[c] = vetA[c] + vetB[c];
    }
    return soma;
}


//1- b
double * prodVetEscal(double* vetA, double a, int dim){
    double* prod = (double*) malloc(sizeof(double) * dim);
    for (int c = 0; c < dim; c++){
        prod[c] = vetA[c] * a;
    }
    return prod;
}

//1- c
void imprimeVet(double* vetA, int dim){
    printf("(");
    for (int c = 0; c < dim; c++){
        if (++c == dim){
            printf("%f ", *vetA);
        }else{
            printf("%f, ", *vetA);
        }
    }
    printf(")\n");
}

// 2
int main(void){
    double *one = (double*) malloc(sizeof(double) * tam);
    double *two = (double*) malloc(sizeof(double) * tam);

    srand(time(NULL));
    for (int c = 0; c < tam; c++){
        one[c] = 1.0 * rand() / RAND_MAX;
        two[c] = 1.0 * rand() / RAND_MAX;
        printf("One: %f, ", one[c]);
        printf("Two: %f, ", two[c]);
        printf("\n");
    }

    double* soma =  somaVet(one, two, tam);
    imprimeVet(soma, tam);
    soma = prodVetEscal(soma, 2, tam);
    imprimeVet(soma, tam);

    free(one);
    free(two);
    free(soma);

    
}
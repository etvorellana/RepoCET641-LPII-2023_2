#include <stdio.h>
#include <stdlib.h>

double* somaVet(double* vetA, double* vetB, int dim);
double* prodVet(double* vetA, double a, int dim);
void imprimeVet(double* vetA, int dim);


int main(int argc, char const *argv[])
{
    double *x, *y, *z, *w;

    int n = 5;
    x = (double*) malloc(n * sizeof(double));
    y = (double*) malloc(n * sizeof(double));

    for(int i = 0; i < n; i++)
    {
        x[i] = (double)rand()/RAND_MAX;
        y[i] = (double)rand()/RAND_MAX;;
    }

    z = somaVet(x, y, 5);
    imprimeVet(z, 5);
    w = prodVet(z, 3.0, 5);
    imprimeVet(w, 5);

    free(x);
    free(y);
    free(z);
    free(w);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

double* somavet(double* vetA, double* vetB, int dim);
double* prodVetEscal(double* vetA, double a, int dim);
void imprimeVet(double* vetA, int dim);
double* doubleEncheVet ( int dim);

int main(void) {
  srand(time(NULL));
  double resp;
  double* veta = (double*) malloc(sizeof(double) * N);
  double* vetb = (double*) malloc(sizeof(double) * N);
  double* vetc = (double*) malloc(sizeof(double) * N);
  double* vetd = (double*) malloc(sizeof(double) * N);
  
  veta = doubleEncheVet(N);
  vetb = doubleEncheVet(N);
  
  vetc = somavet(veta, vetb, N);

  imprimeVet(veta, N);
  imprimeVet(vetb, N);
  imprimeVet(vetc, N);
  
  printf("Digite um valor para multiplicar o vetor: ");
  scanf("%lf",&resp);
  vetd = prodVetEscal(vetc, resp, N);
  
  imprimeVet(vetd, N);
  
  free(vetc);
  free(vetd);
  
  return 0;
}
double* somavet(double* vetA, double* vetB, int dim){
  double* vetC = (double*) malloc(sizeof(double) * dim);
  for (int i = 0; i < dim; i++)
    vetC[i] = vetA[i] + vetB[i];
  return vetC;
}
double* prodVetEscal(double* vetA, double a, int dim){
  double* vetD = (double*) malloc(sizeof(double) * dim);
  for(int i = 0; i < dim; i++)
    vetD[i] = a * vetA[i];
  return vetD;
}
void imprimeVet(double* vetA, int dim){
  printf("(");
  for (int i = 0; i < dim; i++){
    char c = i < dim - 1? ',': ')';
    printf("%5.2lf%c ", vetA[i], c);
  }
  printf("\n");
  return;
}
double* doubleEncheVet (int dim){
  double* vetT = (double*) malloc(sizeof(double) * dim);
  for(int i = 0; i < dim; i++)
    vetT[i] = 100 * ((double)rand()/(double)RAND_MAX);
return vetT;
}

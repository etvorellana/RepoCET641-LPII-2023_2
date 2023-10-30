#include <stdio.h>
//#include <math.h>
#define N 3

double vpol(int n, double c[ ], double x);


int main(void) {
  int n = N; //grau do polinomio, se n = 3, x^3 + x^2 + x + 1
  double c[N + 1]; //vetor com as variaveis, a,b,c e d, junto fica ax³ + bx² + cx¹ + dxº
  double x;
  
  printf("Digite um valor inteiro para x: ");
  scanf("%lf" , &x);
  printf("\n");
  for(int i = 0; i < n+1; i++){
    printf("Coeficiente %d: ", i + 1);
    scanf("%lf" , &c[i]);
  }

  printf("\nResultado: %.2lf\n", vpol(n, c, x));
  
  
  return 0;
}


double vpol(int n, double c[ ], double x){
  if(n == 0) {
    return (c[n]);
  }
  return x * (vpol(n-1, c, x)) + c[n];
  //na primeira iteração pegaremos o "d", como ele multiplica x^0, ele pode ficar isolado, na segunda iteração, vamos retornar "c", quando ele terminar tudo, vamos ter: x(x(x(a) + b) + c) + d = ax³ + bx² + cx + d
}

/*
double vpol(int n, double c[ ], double x){
  if(n == 1)
    return c[0];
  return vpol(n-1, &c[1], x) + c[0] * pow(x, n-1);
  
}
*/


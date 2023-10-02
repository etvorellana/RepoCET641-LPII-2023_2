#include <stdio.h>
//#include <math.h>

double vpol(int n, double c[ ], double x);
double vpolalt(int n, double c[ ], double x);

int main(void) {
  int n = 3;
  double c[3];
  double x;
  
  printf("Digite um valor inteiro para x: ");
  scanf("%lf" , &x);
  printf("\n");
  for(int i = 1; i <= n; i++){
    printf("Coeficiente %d: ", i);
    scanf("%lf" , &c[i-1]);
  }

  printf("\nResultado: %.2lf\n", vpolalt(n, &c[0], x));
  
  
  return 0;
}

double vpol(int n, double c[ ], double x){
  if(n == 1){
    return c[0];
  }
  else{
    int y = x;
    for(int i = 0; i < n-2; i++)
      y *= y;
    return vpol(n-1, &c[1], x) + c[0] * y;
  }
  
}

double vpolalt(int n, double c[ ], double x){
  if(n == 1) {
    return (c[n-1]);
  }
  return x * (vpolalt(n-1, c, x)) + c[n-1];
}

/*
double vpol(int n, double c[ ], double x){
  if(n == 1)
    return c[0];
  return vpol(n-1, &c[1], x) + c[0] * pow(x, n-1);
  
}
*/


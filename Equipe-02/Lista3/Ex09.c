#include <stdio.h>

/*
Implemente uma função recursiva que, dados dois números inteiros x e n, calcula o valor de x^n.
*/

int calpotencia (int x,int n){
  if (n == 0) 
    return 1;
  else {
    return x * calpotencia (x,n-1);
  }
}

int main(void) {
  int a = 4;
  int b = 3;
  calpotencia (a,b);
  printf("Resultado: %d\n",  calpotencia (a,b));
  return 0;
}
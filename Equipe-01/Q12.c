#include <stdio.h>
#include <stdlib.h>

long int SumAlg(long int a);

int main(void) {
  long int x;
  printf("Digite um inteiro positivo: ");
  scanf("%ld",&x);
  printf("A soma dos algarismos de %ld é %ld.\n", x, SumAlg(x));
  return 0;
}

long int SumAlg(long int a){
  if(a == 0)
    return 0;
  return (a%10 + SumAlg(a/10));
}
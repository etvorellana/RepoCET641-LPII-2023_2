#include <stdio.h>

void Dec2Bin(int a);

int main(void) {
  int n;
  
  printf("Olá, seja bem-vindo ao conversor de decimal para binário.\nDigite o valor que deseja converter: ");
  scanf("%d", &n);
  printf("O seu número em binário é: ");
  Dec2Bin(n);
  printf("\n");
  
  return 0;
}

void Dec2Bin(int a){

  if(a/2) Dec2Bin(a/2);
  printf("%d",(a%2));
  
  return;
}
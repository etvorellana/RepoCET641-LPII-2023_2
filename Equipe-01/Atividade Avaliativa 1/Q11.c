#include <stdio.h>

void inverte(int n);

int main(void) {
  
  int num;
  
  printf("Digite a quantidade de números desejada.\n");
  scanf("%d", &num);

  inverte(num);
  
  printf("\n");
  
  return 0;
}

void inverte(int n){
  int a;
  if(n == 0) return;
  
  printf("Digite um número inteiro:\n");
  scanf("%d",&a);
  inverte(n-1);
  printf("%d\t",a);
  
  return;
}
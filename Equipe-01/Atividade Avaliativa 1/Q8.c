#include <stdio.h>

int restoDaDivisao(int x, int y);

int main(void) {
  int x, y;
  printf("Digite um valor inteiro para x: ");
  scanf("%d" , &x);
  printf("Digite um valor inteiro para y: ");
  scanf("%d" , &y);

  printf("O resto da divisão de %d por %d corresponde a: %d" , x, y, restoDaDivisao(x, y));
  
  return 0;
}

int restoDaDivisao(int x, int y){
  x = (x < 0) ? -x : x;
  y = (y < 0) ? -y : y;
  
  if(x < y)
    return  x;
  
  return  restoDaDivisao(x - y, y);  
}
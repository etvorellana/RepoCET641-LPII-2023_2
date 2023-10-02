#include <stdio.h>
#include <stdlib.h>

int MDC (int x, int y);

int main(void) {
  int a, b;
  printf("Digite o valor para a: ");
  scanf("%d",&a);
  printf("Digite o valor para b: ");
  scanf("%d",&b);
  if(MDC(a,b) > 0)
    printf("O MDC de %d e %d é %d\n", a, b, MDC(a, b));
  return 0;
}
int MDC (int x, int y){
  if(x - y >= x) 
    return 0;
  if (x == y)
     return x;
  if(y > x)
    return MDC(y-x,x);
  return MDC(x-y, y);
}

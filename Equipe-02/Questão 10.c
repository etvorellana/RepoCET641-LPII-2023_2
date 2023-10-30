/* Questão 10. Escrever a função double vpol(int n, double c[ ], double x), de forma recursiva, para calcular o valor do polinômio Pn(x) = c0x^n +c1x^n-1+...+cn-1x+cn para um dado x. */

#include <stdio.h>
#include <math.h> // para usar pow que calcula potências


/* Para calcular o valor do polinômio precisamos solicitar ao usuário o valor do grau (int n), os coeficientes que variam de c0 a cn (armazenados em double c[], ou seja, um array de coeficientes do polinômio) e o valor de x (double x é o valor para o qual será feito o cálculo do polinômio). */

double vpol(int n, double c[ ], double x); // cabeçalho da função

int main(void) {
    int n;
    // Explicação teórica: Se o grau de um polinômio completo for n, o número de termos deste polinômio será exatamente n+1.
    double c[n + 1];
    double x, resultado; 
   
    printf("Digite o grau do polinômio, por favor:\n");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) // para pedir e armazenar os coeficientes de acordo com o valor de n
    {   printf("Digite os coeficientes do polinômio de c0 a cn:\n");
        scanf("%lf", &c[i]);
    }

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    resultado = vpol(n, c, x); // chama a função vpol para calcular a partir dos valores fornecidos de n, c e x
    printf("O valor do polinômio P%d(%.2lf) é %.2lf\n", n, x, resultado);

  return 0;
}

/* Para a função double vpol precisaremos de um caso base e de uma parte recursiva que fará o cálculo do valor do termo atual do polinômio e chamará a função vpol reduzindo o grau em 1 (n - 1). */

double vpol(int n, double c[], double x) {
    // Caso base quando o grau for 0
    if (n == 0) 
    {
      return c[0];
    }
    // Chamada recursiva que terá seu resultado somado ao termo atual
    return c[n] * pow(x, n) + vpol(n - 1, c, x);
}
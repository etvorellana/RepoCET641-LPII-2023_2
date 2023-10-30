#include <stdlib.h>
#include <math.h>
#include "lista_02.h" 
/*
    Implemente uma função para calcular o valor médio de um conjunto 
    de valores armazenados um array de valores de tipo double. O cabeçalho 
    da função deve ser:
    double valorMedioG(double x[ ]);
	A quantidade de elementos no array é armazenada na variável global, 
    N, declarada como sendo de tipo int.

    Implemente uma função para calcular o desvio padrão de um conjunto de 
    valores armazenados um array de valores de tipo double. O cabeçalho da 
    função deve ser:
    double desvioPadraoG(double x[ ]);
	A quantidade de elementos no array é armazenada na variável global, N, 
    declarada como sendo de tipo int. Esta função deve utilizar, internamente, 
    a função definida no exercício anterior para calcular o valor médio. 
*/

int main(void)
{
    double x[50];
    double media, desvio;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &N);
    N = N > 50 ? 50:N;
    for(int i = 0; i < N; i++)
        x[i] = -1 + 2*(double)rand()/RAND_MAX;
    media = valorMedioG(x);
    desvio = desvioPadraoG(x);
    printf("Media: %lf\nDesvio Padrao: %lf\n", media, desvio);
    return 0;
}

double desvioPadraoG(double x[ ])
{   
    double soma = 0;
    double media = valorMedioG(x);
    for(int i = 0; i < N; i++){
        //soma += pow(x[i] - media, 2);
        soma += (x[i] - media)*(x[i] - media);
    }
    return sqrt(soma/(N));
}

double valorMedioG(double x[ ])
{
    double soma = 0;
    for(int i = 0; i < N; i++){
        soma += x[i];
    }
    return soma/N;
}

double valorMedio(double x[ ], int n)
{
    double soma = 0;
    for(int i = 0; i < n; i++){
        soma += x[i];
    }
    return soma/n;
}

double valorMedioR(double x[ ], int n)
{
    if(n == 1)
        return x[0];
    return (x[n-1] + valorMedioR(x, n-1)*(n-1))/n;  
}

double desvioPadrao(double x[ ], int n){
    double soma = 0;
    double media = valorMedio(x, n);
    for(int i = 0; i < n; i++){
        soma += pow(x[i] - media, 2);
    }
    return sqrt(soma/n);
}

void normaliza(double x_inout[ ], int n)
{
    double media = valorMedio(x_inout, n);
    for(int i = 0; i < n; i++){
        x_inout[i] = x_inout[i] - media;
    }
}


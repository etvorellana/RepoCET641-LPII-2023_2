#include <stdio.h>

int printTriangulo_1(int n); // imprime o triangulo 1
int printTriangulo_2(int n); // imprime o triangulo 2 
int printTriangulo_3(int n); // imprime o triangulo 3 
int printTriangulo_4(int n); // imprime o triangulo 4


int main(void)
{
    int n;
    printf("Entre com o tamanho do padrão: ");
    scanf("%d", &n);
    if(printTriangulo_1(n) == 0)    
        printf("Erro na função printTriangulo_1\n");
    if(!printTriangulo_2(n))    
        printf("Erro na função printTriangulo_2\n");
    if(!printTriangulo_3(n) || !printTriangulo_4(n))
        printf("Erro na função printTriangulo_3 ou no printTriangula_4\n");
    return 0;
}

int printTriangulo_2(int n)
{
    if(n < 1 || n > 20)
        return 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < n - i ; j++)
            printf("*");
        printf("\n");
    }
    return 1;
}

int printTriangulo_4(int n)
{
    
    return 1;
}

int printTriangulo_1(int n)
{
    if(n < 1 || n > 20)
        return 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i ; j++)
            printf("*");
        printf("\n");
    }
    return 1;
}

int printTriangulo_3(int n)
{
    return 1;
}



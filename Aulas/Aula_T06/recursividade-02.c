#include <stdio.h>

int fRecursiva(int param)
{
    int valor_base = 1; 
    if(param == valor_base) // teste base
        return valor_base;
    else
    {
        int soma = param; //instruções
        return soma + fRecursiva(param - 1); // chamada recursiva
    }
}


int main(void)
{

}
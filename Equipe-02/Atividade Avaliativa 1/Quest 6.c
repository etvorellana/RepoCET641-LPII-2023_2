#include <stdio.h>

void Dec2Bin(int a);

int main() {
    int num;

    printf("Digite um numero decimal: ");
    scanf("%d", &num);


            printf("Representacao binaria de %d: ", num);
            Dec2Bin(num);

    return 0;
}
void Dec2Bin(int a)
{
    if (a==0)
        return;
    else  {
        Dec2Bin(a / 2); // Chamada recursiva com a parte inteira da divis�o por 2
        printf("%d", a % 2); // Imprime o resto da divis�o por 2
    }
}





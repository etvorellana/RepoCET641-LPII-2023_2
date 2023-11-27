#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int mes, dias, i;
    float tempMax, tempMin;
    FILE *fp;
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Digite o numero do mes (1-12): ");
    scanf("%d", &mes);

    if(mes < 1 || mes > 12) {
        printf("Mês inválido!\n");
        return 1;
    }

    dias = diasNoMes[mes - 1];

    fp = fopen("temperaturas.dat", "w");
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    srand(time(NULL));

    for(i = 1; i <= dias; i++) {
        tempMax = (rand() % 20) + 20;  // Gera uma temperatura máxima entre 20 e 40
        tempMin = (rand() % 10) + 10;  // Gera uma temperatura mínima entre 10 e 20

        fprintf(fp, "%d, %d, %.1f, %.1f\n", mes, i, tempMax, tempMin);
    }

    fclose(fp);

    printf("Arquivo 'temperaturas.dat' gerado com sucesso.\n");

    return 0;
}
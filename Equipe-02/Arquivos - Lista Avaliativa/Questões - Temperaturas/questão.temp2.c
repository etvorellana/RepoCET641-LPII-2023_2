#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int mes, dia, cont;
    float tempMax, tempMin, somaMax, somaMin, maiorTemp, menorTemp;
    char nomeArquivo[20];

    somaMax = 0, somaMin = 0, cont = 0;

    FILE *fp, *fpRelatorio;

    fp = fopen("temperaturas.dat", "r"); // abro o arquivo anterior no modo leitura

    if(fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    
    // leio o conjunto de dados do arquivo aberto:
    while(fscanf(fp, "%d, %d, %f, %f\n", &mes, &dia, &tempMax, &tempMin) != EOF) { // enquanto os dados forem diferentes de fim de arquivo
        somaMax += tempMax;
        somaMin += tempMin;
        if(cont == 0) {
            maiorTemp = tempMax;
            menorTemp = tempMin;
        } 
        else {
            if(tempMax > maiorTemp) 
               maiorTemp = tempMax;
            if(tempMin < menorTemp) 
               menorTemp = tempMin;
        }
        cont++;
    }

    fclose(fp); // fecho o arquivo depois dos cálculos realizados no while

    sprintf(nomeArquivo, "relatorio_%d.txt", mes); // para formatar o nome do arquivo

    fpRelatorio = fopen(nomeArquivo, "w"); // abro um arquivo para escrita

    if(fpRelatorio == NULL) {
        printf("Erro ao abrir o arquivo de relatório!\n");
        exit(1);
    }

    fprintf(fpRelatorio, "Prezada comunidade,\n");
    fprintf(fpRelatorio, "Informamos que no mês de %d tivemos as seguintes temperaturas médias:\n", mes);
    fprintf(fpRelatorio, "A temperatura mínima foi, na média, de %.2f\n", somaMin/cont);
    fprintf(fpRelatorio, "A temperatura máxima foi, na média, de %.2f\n", somaMax/cont);
    fprintf(fpRelatorio, "A maior temperatura registrada foi de %.2f e a menor temperatura foi de %.2f\n", maiorTemp, menorTemp);
    fprintf(fpRelatorio, "Atenciosamente,\nCentro de Metrologia Metrologic\n");

    fclose(fpRelatorio);

    printf("Relatório gerado com sucesso no arquivo '%s'.\n", nomeArquivo);

    return 0;
}
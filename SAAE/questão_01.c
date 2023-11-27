 
#include <stdio.h>
#include <stdlib.h>

int* contNotas_V1(int notas[], int* tam){
    int min, max; 
    min = max = notas[0];
    for(int i = 1; i < *tam; i++)
    {
        if(min > notas[i])
            min = notas[i];
        else if(max < notas[i])
            max = notas[i];
    }
    int* qNotas = (int*)malloc((max - min + 1) * sizeof(int));
    for(int i = 0; i < *tam; i++)
            qNotas[i]++;
    *tam = max - min + 1;
    return qNotas;
}

int* contNotas_V2(int notas[], int* tam){
    int min, max; 
    min = max = notas[0];
    for(int i = 1; i < *tam; i++)
    {
        if(min > notas[i])
            min = notas[i];
        else if(max < notas[i])
            max = notas[i];
    }
    int* qNotas = (int*)calloc((max - min + 1), sizeof(int));
    for(int i = 0; i < *tam; i++)
            qNotas[notas[i] - min]++;
    *tam = max - min + 1;
    return qNotas;
}

int* contNotas_V3(int notas[], int* tam){
    int min, max; 
    for(int i = 0; i < tam; i++)
    {
        if(min > notas[i])
            min = notas[i];
        else if(max < notas[i])
            max = notas[i];
    }
    int* qNotas = (int*)calloc((max - min + 1), sizeof(int));
    for(int i = 0; i < tam; i++)
            qNotas[notas[i] - min]++;
    tam = max - min + 1;
    return qNotas;
}

int* contNotas_V4(int notas[], int* tam){
    int min, max; 
    for(int i = 0; i < tam; i++)
    {
        if(min > notas[i])
            min = notas[i];
        else if(max < notas[i])
            max = notas[i];
    }
    *tam = max - min + 1;
    int* qNotas = (int*)malloc(*tam * sizeof(int));
    for(int i = 0; i < *tam; i++)
            qNotas[i] = 0;
    for(int i = 0; i < *tam; i++)
            qNotas[notas[i] - min]++;
    return qNotas;
}

int* contNotas_V5(int notas[], int *tam){
    int min, max;
    min = max = notas[0];
    for(int i = 1; i < *tam; i++)
    {
        if(min > notas[i])
            min = notas[i];
        else if(max < notas[i])
            max = notas[i];
    }
    int intervalo = max - min + 1;
    int* qNotas = (int*)malloc(intervalo * sizeof(int));
    for(int i = 0; i < intervalo; i++)
            qNotas[i] = 0;
    for(int i = 0; i < *tam; i++)
            qNotas[notas[i] - min]++;
    *tam = intervalo;
    return qNotas;
}

int* contNotas_V6(int notas[], int* tam){
    int min, max; 
    min = max = notas[0];
    for(int i = 1; i < tam; i++)
    {
        if(min > notas[i])
            min = notas[i];
        else if(max < notas[i])
            max = notas[i];
    }
    int* qNotas = (int*)calloc((max - min + 1), sizeof(int));
    for(int i = 0; i < tam; i++)
            qNotas[i]++;
    tam = max - min + 1;
    return qNotas;
}

int* contNotas(int notas[], int* tam);

int main(int argc, char const *argv[])
{
    int pontuacao[300];
    //Apenas para testar
    for(int i = 0; i < 300; i++)
        pontuacao[i] = 45 + rand() % 150;
    int tam = 300;
    int* qNotas = contNotas(pontuacao, &tam);
    for(int i = 0; i < tam; i++)
        printf("%d \n", qNotas[i]);
    return 0;
}


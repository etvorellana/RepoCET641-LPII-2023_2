#include <stdio.h>

double calcArrayA(double x[], int n, double max, double min);
double calcArrayB(double x[], int n, double *max, double *min);
void calcArrayC(double x[], int n, double *max, double *min, double *media);


int main(void)
{
    double x[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double max = 123.0, min = 321.0, media = -123456;
    printf("Testando a função calcArrayA\n");
    media = calcArrayA(x, 5, max, min);
    printf("max = %lf, min = %lf, media = %lf\n", max, min, media);
    media = -123456;
    printf("Testando a função calcArrayB\n");
    media = calcArrayB(x, 5, &max, &min);
    printf("max = %lf, min = %lf, media = %lf\n", max, min, media);
    return 0;
}

double calcArrayA(double x[], int n, double max, double min)
{
    int i;
    max = x[0];
    min = x[0];
    double media = x[0];
    for (i = 1; i < n; i++)
    {
        media += x[i];
        if (x[i] > max)
            max = x[i];
        else if (x[i] < min)
            min = x[i];
    }
    media /= n;
    //Para debugar o códig. Comente o printf após testar
    printf("Testando na função calcArrayA.\nResultados: ");
    printf("max = %lf, min = %lf, media = %lf\n", max, min, media);
    return media;
}

double calcArrayB(double x[], int n, double *max, double *min)
{
    int i;
    *max = x[0];
    *min = x[0];
    double media = x[0];
    for (i = 1; i < n; i++)
    {
        media += x[i];
        if (x[i] > *max)
            *max = x[i];
        else if (x[i] < *min)
            *min = x[i];
    }
    media /= n;
    //Para debugar o códig. Comente o printf após testar
    printf("Testando na função calcArrayB.\nResultados: ");
    printf("max = %lf, min = %lf, media = %lf\n", *max, *min, media);
    return media;
}


double calcArrayA_(double x[], int n, double max, double min)
{
    int i;
    max = x[0];
    min = x[0];
    double media = x[0];
    for (i = 1; i < n; i++)
    {
        media += x[i];
        if (x[i] > max)
            max = x[i];
        else if (x[i] < min)
            min = x[i];
    }
    media /= n;
    return media;
}

double calcArrayB(double x[], int n, double *max, double *min)
{
    int i;
    *max = x[0];
    *min = x[0];
    double media = x[0];
    for (i = 1; i < n; i++)
    {
        media += x[i];
        if (x[i] > *max)
            *max = x[i];
        else if (x[i] < *min)
            *min = x[i];
    }
    media /= n;
    return media;
}



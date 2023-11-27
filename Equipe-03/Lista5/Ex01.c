#include <stdio.h>
#include <stdlib.h>

/*

*/

int main(void){
    FILE * fp = fopen("dados.txt", "w");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    for(int c = 1; c <= 100; c++){
        char num[10];
        sprintf(num, "%d\n", c);
        fputs(num, fp);
    }


    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}


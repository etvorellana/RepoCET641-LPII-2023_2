#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/

int main(void){
    FILE * fp = fopen("dados.bin", "wb");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }
    
    for(int c = 1; c <= 100; c++){
        char num[10] = {0};
        sprintf(num, "%d\n", c);
        printf("%s", num);
        fwrite(num, sizeof(char), strlen(num), fp);
        //fprintf(fp, "%d\n", c);
    }


    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){

    FILE* fp;
    char ch;
    int tam = 0, i=0;

    fp = fopen("novo.txt","w");

    if(fp == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }

    while(1){
        ch = getchar();
        if(ch == '>') break;
        fputc(ch,fp);
    }
    

    if (fclose(fp)){
        printf("ERRO NO FECHAMENTO DO ARQUIVO!\n");
        exit(1);
    }

    fp = fopen("Arquivos/InputQ10.txt","r");
    if(fp == NULL){
        printf("ERRO NA REABERTURA DO ARQUIVO!\n");
        exit(1);
    }

    while(!feof(fp)){
        fgetc(fp);
        tam++;
    }

    char* str = (char*) malloc(tam);
    rewind(fp);

    while(!feof(fp)){
        str[i++] = fgetc(fp);
    }
    str[i-1] = '\0';

    printf("A sua string gerada:\n%s",str);

    if (fclose(fp)){
        printf("ERRO NO FECHAMENTO DO ARQUIVO!\n");
        exit(1);
    }

    return 0;
}
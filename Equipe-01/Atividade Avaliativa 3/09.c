#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contem(char* palavra, char* frase);
int main (void){

    FILE* fp;
    char palavra[100], aux[500] = {},*vef;
    int linha = 0, status = 0;

    fp = fopen("arquivo.txt","r");

    if(fp == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO!\n");
        exit(1);
    }

    printf("Digite a palavra que deseja buscar no arquivo.\n");
    fgets(palavra, 100, stdin);
    palavra[strlen(palavra)-1] = '\0';

    while(!feof(fp)){
        linha++;
        vef = fgets(aux,500,fp);
        if(contem(palavra, aux) && vef != NULL){
            printf("\nPalavra encontrada! Na linha %i com a seguinte frase:\n%s\n",linha,aux);
            status++;
        }
    }

    if(status) printf("Numero de ocorrencias da palavra: %i", status);
    else printf("\nPalavra nao encontrada!\n");

    if(fclose(fp)) printf("ERRO NO FECHAMENTO DO ARQUIVO!\n");

    return 0;
}

int contem(char* palavra, char* frase){
    int tamPalavra = strlen(palavra);
    int tamFrase = strlen(frase);
    int cont;

    for(int i = 0; i< tamFrase;i++){
        if(frase[i] == palavra[0]){
            if((i == 0 || frase[i-1] == ' ') && (frase[i+tamPalavra] == '\n' || frase[i+tamPalavra] == ' ' || frase[i+tamPalavra] == '\0')){
                cont = 1;
                for(int j = 1; j<tamPalavra; j++){
                    if(palavra[j] == frase[i+j]) cont++;
                } 
                if(cont == tamPalavra) return 1;
            }
        }
    }
    return 0;
}
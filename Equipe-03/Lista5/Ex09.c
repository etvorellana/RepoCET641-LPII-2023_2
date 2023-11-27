#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

*/

int main(void){
    FILE * fp = fopen("alunos.txt", "r");

    // Verifica se ocorreu um erro na hora de abrir e encerra o programa se ocorreu
    if (fp == NULL){
        printf("Arquivo não foi aberto");
        return 0;
    }

    char palavra[100];
    printf("Digite a palavra que deseja buscar: ");
    fgets(palavra, 100, stdin); 
    palavra[strlen(palavra) - 1] = '\0';
    int tam = strlen(palavra);

    int linha = 1;
    while(!feof(fp)){
        char busca[200];
        fgets(busca, 200, fp);
        
        int c = 0;
        for (int d = 0; busca[d] != '\n'; d++){
            if (busca[d] == palavra[c]){
                c++;   
            } else if(c + 1 == tam){
                printf("\nPalavra encontrada na linha %d:\n",linha);
                printf("%s", busca); 
                break;
            } else if(busca[d] == palavra[0]){
                c = 0;
            } else{
                c = 0;
            }
        }

        
        linha++;
    }


    // Fecha e avisa se deu algum problema na hora de fechar o arquivo
    if(fclose(fp)) printf("Arquivo não pode ser fechado\n");

    
    return 0;
}


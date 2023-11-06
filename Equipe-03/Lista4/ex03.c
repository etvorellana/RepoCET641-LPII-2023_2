#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//3- a

char* geraPalavra(int tam){
    char* palavra = (char*) malloc(sizeof(char) * tam);
    tam =  2 + rand() % tam;
    /*if (tam < 2){
        printf("A palavra não pode ter menos que duas letras");
        return NULL;
    }*/

    char vogais[] = {'a','e','i','o','u'};
    char consoantes[] = {'b','c','d','f','g','h','j','k','l','m',
                        'n','p','q','r','s','t','v','w','x','y','z'};

    for (int c = 0; c < tam; c++){
        if (c % 2 == 0){
            palavra[c] = vogais[rand() % 5];
        }
        else{
            palavra[c] = consoantes[rand() % 21];
        }
    }

    palavra[tam] = '\0';
    return palavra;
}


//3- b
char* geraFrase(int tam){
    char* frase = (char*) malloc(sizeof(char) * tam * tam);
    //char frase[500];
    int pos = 0;

    for (int c = 0; c < tam; c++){
        char* palavra = geraPalavra(tam);
        
        if (c == 0){
            palavra[c] = palavra[c] - ('a' - 'A');
            
            for (unsigned int d = 0; d <= strlen(palavra) ; d++){
                if (d == strlen(palavra)){
                    frase[pos] = ' ';
                    
                } else{
                    frase[pos] = palavra[d];
                }
                pos++;
            }
        }else{
            for (unsigned int d = 0; d <= strlen(palavra); d++){
                if (d == strlen(palavra)){
                    frase[pos] = ' ';
                    
                } else{
                    frase[pos] = palavra[d];
                }
                pos++;
            }
        }
        free(palavra);
    }
    
    return frase;
}


int main(void){
    srand(time(NULL));

    //char frase[100];
    char *frase;
    char user[100];

    printf("Linux quer conversar com você!!\n");
    printf("Digite uma frase:");
    fgets(user, 100, stdin);
    printf("Palavra: %s\n", geraPalavra(10));
    frase = geraFrase(4);
    printf("Frase do computador: %s\n", frase);
    

}
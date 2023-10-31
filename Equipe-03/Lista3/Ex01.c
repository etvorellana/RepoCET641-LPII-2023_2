#include <stdio.h>

/*
Crie uma função que recebe uma string e um caractere 
(void apagaCaractere(char ch, char str[])), e apague todas as ocorrências 
desse caractere na string.
*/


void apagaCaractere(char ch, char str[]){
    for (int c = 0; str[c] != '\0'; c++){
        if (ch == str[c]){
            for (int d = c; str[d] != '\0'; d++){
                str[d] = str[d + 1];
            }
            c--;
        }
    }
}


int main(void){
    char str[] = "Hello word Im linux";
    char ch;
    printf("String: %s\n\n", str);
    printf("Digite um caractere: ");
    scanf("%c", &ch);
    apagaCaractere(ch, str);
    printf("\nString: %s\n", str);


    
    return 0;
}



#include <stdio.h>

/*
Crie uma função que recebe uma string e dois caracteres
(void trocaCaracteres(char ch1, char ch2, char str[])), 
e substitua todas as ocorrências na string do caractere ch1 pelo caractere ch2.
*/


void trocaCaracteres(char ch1, char ch2, char str[]){
    for (int c = 0; str[c] != '\0'; c++){
        if (ch1 == str[c]){
            str[c] = ch2;
        }
    }
}


int main(void){
    char str[] = "Hello word Im linux";
    char ch1, ch2;
    printf("String: %s\n\n", str);
    printf("Digite o caractere que deseja substituir: ");
    scanf("%c", &ch1);
    //scanf("%c");
    getchar();
    printf("Digite o caractere que deseja colocar no lugar: ");
    scanf("%c", &ch2);
    trocaCaracteres(ch1, ch2, str);
    printf("\nString: %s\n", str);
    
    return 0;
}



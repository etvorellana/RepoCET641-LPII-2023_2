#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* geraPalavra(int tam);
char* geraFrase(int tam);

int main(void){
  char str[100];
  char* pont;

  printf("Seja bem-vindo ao nosso rôbo.\nDigite o que quiser e veja as respostas, quando quiser encerrar digite 'pare'.\nDigite sua frase: ");
  
  while(1){
    
  fgets(str,100,stdin);
  str[strlen(str)-1]='\0';
    
  if(strcmp("pare",str)== 0) return 0;
  pont = geraFrase(20+rand()%31);
  printf("%s\n\nDigite sua frase: ",pont);
  free(pont);
  }
  
  
  return 0;
}

char* geraPalavra(int tam){

  if(tam < 2) 
    return NULL;
  
  srand(time(NULL));
  int limite = tam - 1;
  limite = 2 + (rand()%limite);
  char* palavra = (char*) malloc(sizeof(char) * (limite+1));
  
  
  for(int i = 0; i < limite; i++){
    if(i%2 == 1){
      switch(rand()%5+1){
        case 1:
        palavra[i] = 'a';
        case 2:
        palavra[i] = 'e';
        case 3:
        palavra[i] = 'i';
        case 4:
        palavra[i] = 'o';
        case 5:
        palavra[i] = 'u';
      }
    }
    else{
      
      do{
        palavra[i] = 'b' + rand()%25;
      } while(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u');
      
    }
  }
  palavra[limite] = '\0';

  return palavra;
    
}

char* geraFrase(int tam){
  
  srand(time(NULL));
  char* palavra = (char*) malloc(sizeof(char) * (tam+1));
  int rest = tam, cont=0, limite;

  while(rest!= 0){

    do{
      limite = 1+ (rand()%10);
    } while(limite>rest);
    
    for(int i = 0; i < limite; i++){
      
      if((i%2==0 && limite != 1)){
        
        do{
          palavra[cont] = 'b' + rand()%25;
        } while(palavra[cont] == 'e' || palavra[cont] == 'i' || palavra[cont] == 'o' || palavra[cont] == 'u');
        
      }
        
      else {
        switch(rand()%5+1){
          case 1:
          palavra[cont] = 'a';
          break;
          case 2:
          palavra[cont] = 'e';
          break;
          case 3:
          palavra[cont] = 'i';
          break;
          case 4:
          palavra[cont] = 'o';
          break;
          case 5:
          palavra[cont] = 'u';
          break;
        }
      }

      cont++;
    }
    
    rest -= limite;
    
    if(rest > 0) {
      palavra[cont++] = ' ';
      rest--;
    }
    
  }
  palavra[0] -= 'a' - 'A';
  palavra[tam] = '\0';

  return palavra;

}


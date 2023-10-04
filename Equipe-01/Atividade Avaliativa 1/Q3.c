#include <stdio.h>
#include <string.h>

void contaCaracteres(char str[], int con[]);

int main()
{
    char str[100];
    int con[26];

    printf("Digite a sua string:\n");
    fgets(str,100,stdin);

    str[strlen(str)-1] = '\0';
  
    contaCaracteres(str, con);
  
    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d\n", 'a' + i, con[i]);
    }

    return 0;
}

void contaCaracteres(char str[], int con[])
{
    int i;
    
    for (i = 0; i < 26; i++)
      con[i] = 0;
    
    
    for (i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
          con[c - 'a']++;
        else if (c >= 'A' && c <= 'Z')
          con[c - 'A']++;
    }
}
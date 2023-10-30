#!/bin/bash

echo Criando arquivos

for (( c = 1; c <= 12; c++ ))
    do
    if [ $c -lt 10 ]; then
	    echo Ex0$c.c
	    echo "#include <stdio.h>

/*

*/

int main(void){



    
    return 0;
}
" >> Ex0$c.c
    else
        echo Ex$c.c
	    echo "#include <stdio.h>

/*

*/

int main(void){



    
    return 0;
}
" >> Ex$c.c
    fi
done

echo Finalizado!


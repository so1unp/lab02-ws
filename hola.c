/*
 * Imprime un saludo por la salida estándar.
 */


#include <stdio.h>
#include <stdlib.h>     // exit()

#include <stdlib.h>
#include <unistd.h>



int main(int argc,char* arg[])
{
    if(argc > 1 ){
        printf("hola %s \n",arg[1]);

    }
  
  
    exit(EXIT_SUCCESS);
}

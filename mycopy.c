/*
 * Copia un archivo en otro.
 */

#include <stdio.h>
#include <stdlib.h>     // exit()
#include <unistd.h>

int main(int argc, char *argv[])
{
    ssize_t bytes_leidos;
    char caracter_leido;
    char buffer[1];

    FILE* archivo_origen;
    archivo_origen = fopen(argv[1], "r");
    if (archivo_origen == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    FILE* archivo_destino = fopen(argv[2], "wx");
 
    if (archivo_destino ==NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
   

  
    while (fread(buffer, sizeof(char), 1, archivo_origen) == 1) {
        fwrite(buffer,sizeof(char),1, archivo_destino);

    }
    fclose(archivo_destino);
    fclose(archivo_origen);

  
    exit(EXIT_SUCCESS);
}

/*
 * Copia un archivo en otro.
 */

#include <stdio.h>
#include <stdlib.h> // exit()
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  char buffer[1];

  FILE *archivo_origen;
  FILE *archivo_destino;

  switch (tolower(argv[1][0])) {
    //-----------------------------caso f para usar funciones de la biblioteca estandar
  case 'f':
    if (argc < 4) {
        perror("Parametros invalidos"); // esto no se si es necesario
        exit(EXIT_FAILURE);
    }

    archivo_origen = fopen(argv[2], "r");
    if (archivo_origen == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    archivo_destino = fopen(argv[3], "wx");
    if (archivo_destino == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fread(buffer, sizeof(char), 1, archivo_origen) == 1) {
      fwrite(buffer, sizeof(char), 1, archivo_destino);
    }
    fclose(archivo_destino);
    fclose(archivo_origen);
  break ;
  //------------------------------caso s para usar funciones del sistema operativo
   case 's':
    if (argc < 4) {
        perror("Parametros invalidos"); // esto no se si es necesario
        exit(EXIT_FAILURE);
    }

    archivo_origen = open(argv[2], O_RDONLY); // solo lectura
    if (archivo_origen == -1) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    // abre el archivo en escritura, lo crea si no existe y falla si ya existe, con permisos rw-r--r--
    archivo_destino = open(argv[3], O_WRONLY | O_CREAT | O_EXCL, 0644); 
    if (archivo_destino == -1) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read(archivo_origen, buffer, sizeof(char)) == 1) {
      write(archivo_destino, buffer, sizeof(char));
    }
    close(archivo_destino);
    close(archivo_origen);
    break;
    //---------------------------------caso default
    default :
     perror("primer parametro  invalido");
     remove(argv[3]);
    exit(EXIT_FAILURE);
    break;
  }

  exit(EXIT_SUCCESS);
}

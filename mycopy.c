/*
 * Copia un archivo en otro.
 */

#include <stdio.h>
#include <stdlib.h> // exit()
#include <time.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
  char buffer[1];

  FILE *archivo_origen;
  FILE *archivo_destino;

  if (argc < 4) {

    fprintf(stderr, "Parametros invalidos\n");
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

  switch (tolower(argv[1][0])) {
  case 'r':
    while (fread(buffer, sizeof(char), 1, archivo_origen) == 1) {
      fwrite(buffer, sizeof(char), 1, archivo_destino);
    }
  break ;
   case 's':

   //aca implementen la parte s
    break;
    default :
     perror("primer parametro  invalido");
     remove(argv[3]);
    exit(EXIT_FAILURE);
    break;
  }
  fclose(archivo_destino);
  fclose(archivo_origen);

  exit(EXIT_SUCCESS);
}

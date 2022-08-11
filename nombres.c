#include <stdio.h>
#include <stdlib.h>
#define LINESIZE 400

int main(int argc, char *argv[]) {
  FILE *fp;
  char line[LINESIZE];
  fp = fopen("nombres.csv", "r");
  printf("-20s\t%-10s\tAño\n", "Nombre", "Cantidad");
  printf("------------------------------\n");
  int read_n_lines = atoi(argv[1]);
  char *nombre = argv[2];
  int search_year = atoi(argv[3]);
  int k = 0;
  while (fgets(line, LINESIZE, fp) != NULL) {

    if (k == read_n_lines && k != 0) {
      break;
    }
    k++;

    char name[60] = "";
    char count_char[10] = "";
    char year_char[10] = "";
    int i = 0;
    int j = 0;
    while (line[i] != ',' && line[i] != '\n') {
      name[i] = line[i];
      i++
    }
    name[i++] = 0; // terminar el string
    while (line[i] != ',') {
      count_char[j] = line[i];
      i++;
      j++;
    }
    count_char[j] = 0; // terminar el string
    j = 0;
    i++;
    while (line[i] != '\n') {
      year_char[j] = line[i];
      i++;
      j++;
    }
    year_char[j] = 0; // terminar el string
    int count = atoi(count_char);
    int year = atoi(year_char);
    if (search_year == year && !strcmp(name, nombre)){
      printf("%-20s\t%-10d\t%d\n", name, count, year);
    }
  }
  fclose(fp);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#define LINESIZE 1000

int main(int argc, char const *argv[]) {
  char *filename = argv[1];
  int shift_amount = atoi(argv[2]);
  FILE *fp;
  char line[LINESIZE];
  fp = fopen(filename, "r");
  while (fgets(line, LINESIZE, fp) != NULL) {
    int i = 0;
    while (line[i] != '\n') {
      if (line[i] >= 'a' && line[i] <= 'z' ||
          line[i] >= 'A' && line[i] <= 'Z') {

      line[i] = ((line[i] - 'a') + shift_amount %26) + 'a';
      }
      i++;
    }
    printf("%s", line);
  }
  fclose(fp);
  return 0;
}

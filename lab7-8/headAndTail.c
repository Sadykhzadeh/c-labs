#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define elif else if

int main(int argc, char * argv[]) {
  FILE * inputFile = fopen(argv[1], "r");
  char ht = argv[2][0];
  int num = atoi(argv[3]);
  char content[300];
  int temp = 0;
  
  if (argc < 4 || !inputFile || !ht || !num) return -1;

  if (ht == 'h') {
    while (fgets(content, 300, inputFile) && temp++ != num)
      printf("%s", content);
  } elif(ht == 't') {
    fseek(inputFile, 0, SEEK_END);
    int pos = ftell(inputFile);
    while (pos) {
      fseek(inputFile, --pos, SEEK_SET);
      if (fgetc(inputFile) == '\n')
        if (temp++ == num - 1) break;
    }
    while (fgets(content, sizeof(content), inputFile) != NULL)
      printf("%s", content);
  } else return -1;

  fclose(inputFile);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define elif else if

int addStudent(char* path, char* firstName) {
  FILE * inputFile = fopen(path, "w");
  if (!inputFile) return -1;
  fprintf(inputFile, "%s\n", firstName);
  fclose(inputFile);
}

// 0 —— success, 1 —— not found, -1 —— error
int findStudent(char* path, char firstName) {
  char content[300];
  FILE * inputFile = fopen(path, "r");
  if (!inputFile) return -1;
  while (fgets(content, 300, inputFile)) if (content == firstName) {fclose(inputFile); return 0;}
  fclose(inputFile);
  return 1;
}
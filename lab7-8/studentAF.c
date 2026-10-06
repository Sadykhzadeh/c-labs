#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define elif else if

// 0 —— success, -1 —— error
int addStudent(const char* path, const char* firstName) {
  /* Opening with "w" truncated the file, so adding a student threw away every
     student added before. */
  FILE * inputFile = fopen(path, "a");
  if (!inputFile) return -1;
  fprintf(inputFile, "%s\n", firstName);
  /* There was no return on this path at all, so the caller read whatever the
     return register happened to hold. */
  return fclose(inputFile) ? -1 : 0;
}

// 0 —— success, 1 —— not found, -1 —— error
int findStudent(const char* path, const char* firstName) {
  char content[300];
  FILE * inputFile = fopen(path, "r");
  if (!inputFile) return -1;
  while (fgets(content, sizeof content, inputFile)) {
    /* fgets keeps the newline, so a stored name never matched the one asked
       for even once the comparison worked. */
    content[strcspn(content, "\r\n")] = '\0';
    /* firstName was declared `char` and compared as `content == firstName`:
       an array address against a character code, which is never equal - the
       function could not find anybody. */
    if (!strcmp(content, firstName)) {
      fclose(inputFile);
      return 0;
    }
  }
  fclose(inputFile);
  return 1;
}

#define swap(a, b) \
  {                \
    int temp = a;  \
    a = b;         \
    b = temp;      \
  }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sortString(char* a) {
  char* pointer;
  int len = strlen(a);
  char* result = (char*)malloc(len + 1);

  pointer = a;
  int d = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    for (int c = 0; c < len; c++) {
      if (*pointer == ch) {
        *(result + d) = *pointer;
        d++;
      }
      pointer++;
    }
    pointer = a;
  }
  *(result + d) = '\0';

  strcpy(a, result);
  free(result);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define end     \
  printf("\n"); \
  return 0

char* askForString(void) {
  char data[99];
  printf("enter a string: ");
  /* scanf("%s") carried no field width, so any input longer than 98
     characters ran off the end of data. */
  if (scanf("%98s", data) != 1) return NULL;
  /* strdup is POSIX, not C11: under -std=c11 it was not declared, so it was
     assumed to return int and the pointer was truncated to 32 bits. malloc
     and memcpy need no feature macro. */
  size_t size = strlen(data) + 1;
  char* ans = malloc(size);
  if (ans) memcpy(ans, data, size);
  return ans;
}

int main(void) {
  char* hello = askForString();
  if (!hello) return 1;
  /* strlen sat in the loop condition, so it was recounted on every pass. */
  for (size_t i = 0, length = strlen(hello); i < length; i++) {
    printf("%c", hello[i]);
  }
  free(hello);
  end;
}

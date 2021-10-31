#include <stdio.h>
#include <string.h>

#define end     \
  printf("\n"); \
  return 0

char* askForString() {
  char data[99];
  printf("enter a string: ");
  scanf("%s", data);
  char* ans = strdup(data);
  return ans;
};

int main() {
  char* hello = askForString();
  for (int i = 0; i < strlen(hello); i++) printf("%c", hello[i]);
  end;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortChar_bubbleSort.h"

int main(int n, char *argv[]) {
  if (n != 2) {
    printf(
        "Data is insuffient! Please insert proper input at command line. \n");
    return 0;
  }
  char *str = argv[1];
  sortString(str);
  return printf("%s\n", str), 0;
}
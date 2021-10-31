#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int n, char** argv) {
  if (n < 2) {
    printf(
        "Data is insuffient! Please insert proper input at command line. \n");
    return 0;
  }

  int array[n - 1];

  for (int i = 0; i < n - 1; i++) {
    array[i] = atoi(argv[i + 1]);
  }

  bubbleSort(array);

  for (int i = 0; i < n - 1; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}

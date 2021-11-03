#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main() {
  Array *one = arrayConstructor(50);
  Array* two = arrayConstructor(30);
  Array* sum = append(one, two);
  printf("%d\n", sum->size); // 80
  Array* mergingArrays = merge(one, two);
  printf("%d\n", mergingArrays->size); // 80
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array* append(Array* arr1, Array* arr2) {
  int ansSize = arr1->size + arr2->size;
  Array* ansArray = arrayConstructor(ansSize);
  for(int i = 0; i < ansSize; i++) {
    if (i < arr1->size) ansArray->data[i] = arr1->data[i];
    else ansArray->data[i] = arr2->data[i - arr1->size];
  }
  return ansArray;
};

Array* merge(Array* arr1, Array* arr2) {
  int i = 0, y = 0;
  int ansSize = arr1->size + arr2->size;
  Array* ansArray = arrayConstructor(ansSize);
  for(int q = 0; q < ansSize; q++) {
    if(i == arr1->size - 1) {
      ansArray->data[q] = arr2->data[y];
      y++;
      continue;
    }
    if(y == arr2-> size - 1) {
      ansArray->data[q] = arr1->data[i];
      i++;
      continue;
    }
    if(arr1->data[i] > arr2->data[y]) {
      ansArray->data[q] = arr2->data[y];
      y++;
    } else if(arr1->data[i] > arr2->data[y]) {
      ansArray->data[q] = arr1->data[i];
      i++;
    } else {
      ansArray->data[q] = arr2->data[y];
      y++;
      ansArray->data[q] = arr1->data[i];
      i++;
    }
  }
  return ansArray;
};

Array* arrayConstructor(int size) {
  Array* newArray;
  newArray = (struct Array*)malloc(sizeof(struct Array));
  newArray->size = size;
  newArray->data = (int*)calloc(size, sizeof(int*));
  return newArray;
};
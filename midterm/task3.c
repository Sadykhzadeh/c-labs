#include <stdio.h>
#include <stdlib.h>
#define consoleInt(x) printf("%d ", x)
#define newLineAndEnd puts(""); return 0
#define line puts("")

int* arrayFactory(int arrSize, int num) {
  int* ansArray = (int*)calloc(arrSize, sizeof(int));
  for(int i = 0; i < arrSize; i++) ansArray[i] = num;
  return ansArray;
}

void incrementArray(int *arr, int arrSize, int inc) {
  for(int i = 0; i < arrSize; i++) arr[i]+=inc;
}

void printArr(int *arr, int arrSize) {
  for(int i = 0; i < arrSize; i++) consoleInt(arr[i]);
  line;
}

const int sizeOfArr = 20;

int main() {
  //initialize array
  int* myArray = arrayFactory(sizeOfArr, 1);
  
  //print all the items
  printArr(myArray, sizeOfArr);

  //increase items by 10
  incrementArray(myArray, sizeOfArr, 10);
  
  //print all the items (again ^_^)
  printArr(myArray, sizeOfArr);

  newLineAndEnd;
}
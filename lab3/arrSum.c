// by Azer Sadykhzadeh
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// my defines
#define elif else if
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define cout(a) printf("%d ", a)
#define end     \
  printf("\n"); \
  return 0

// main func
void sum(int* arrOne, int* arrTwo, int sizeOne, int sizeTwo) {
  int maxSize = max(sizeOne, sizeTwo),
      *answerArray = (int *)calloc(maxSize + 1, sizeof(int)),
      tempArray[maxSize];
  for (int i = 0; i < maxSize; i++) {
    int temp = min(sizeOne, sizeTwo);
    if (i < temp) tempArray[i] = arrOne[i] + arrTwo[i];
    elif(temp == sizeTwo) tempArray[i] = arrOne[i];
    elif(temp == sizeOne) tempArray[i] = arrTwo[i];
  }
  answerArray = tempArray;
  for (int i = 0; i < maxSize; i++) cout(answerArray[i]);
}

int main() {
  int firstArray[] = {5, 3, 4, 5, 1, 2, 6}, secondArray[] = {4, 2, 3, 1, 52432};
  sum(firstArray, secondArray, 7, 5);
  end;
}
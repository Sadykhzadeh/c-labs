#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {int temp = a; a = b; b = temp;}
#define consoleInt(x) printf("%d ", x)
#define newLineAndEnd puts(""); return 0
#define line puts("")
// #define max(a, b) (a > b ? a : b)
// #define min(a, b) (a > b ? b : a)

void bubbleSort(int *arr, int arrSize) {
  for(int i = 0; i < arrSize - 1; i++) 
    for(int j = i + 1; j < arrSize; j++) 
      if(arr[i] > arr[j]) 
        swap(arr[i], arr[j]);
}

void printArr(int *arr, int arrSize) {
  for(int i = 0; i < arrSize; i++) consoleInt(arr[i]);
  line;
}

int main(int n, char** arg) {
    int arr[1000], ln = 1;
    while(arg[ln]) {
      arr[ln-1] += atoi(arg[ln]);
      ++ln;
    }
    --ln;

    bubbleSort(arr, ln);
    
    printArr(arr, ln);
    newLineAndEnd;
}
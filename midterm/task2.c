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

int main(int argc, char** argv) {
    int arr[1000], ln = 0;
    /* `arr[ln-1] += ...` added into memory that was never initialised, so
       `9 1 21 5 3 7 4` printed `1 5 10 11 25 41 2157468`. argc was ignored -
       the parameter was even named n and never read - and the loop walked
       argv until NULL with no bound, so more arguments than arr can hold
       wrote past the end of it. */
    const int capacity = (int)(sizeof arr / sizeof *arr);
    for (int i = 1; i < argc && ln < capacity; i++) arr[ln++] = atoi(argv[i]);

    bubbleSort(arr, ln);
    
    printArr(arr, ln);
    newLineAndEnd;
}
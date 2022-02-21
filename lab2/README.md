# Lab-02 | Implementing a bubble/selection sort in C

## Implementing a bubble/selection sort in c

Visualizing selection sort

![image](https://user-images.githubusercontent.com/51178055/154908494-23c1dea6-e884-4842-a176-359db915fd3e.png)

[VisuAlgo - Sorting (Bubble, Selection, Insertion, Merge, Quick, Counting, Radix)](https://visualgo.net/en/sorting)

```c
arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64
```

## Swap two numbers using pointers

```c
void swap(int *first,int *second)
{
    int temp = *first;
    *first = *second;
    *second =  temp;
}

void swap(int arr[], int firstIndex,int secondIndex)
{
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] =  temp;
}
```

## Main program

./sort 32 12 1 4 5 1 -1  

./sort zhga  → aghz

```c
#include <stdio.h> // for printf 
#include <stdlib.h> // for atoi
#include "sorting.h"

int main(int n, char** argv){ // ["./sort", "32", "12", "1", "4", "5","1", "-1"]

 if (n < 2) {
      printf("Data is insuffient! Please insert proper input at command line. \n");
			return 0;
 }

	int array[n-1];

	for (int i = 0; i < n-1; i++){ // argv[1] = "32"
	   array[i] = atoi(argv[i+1]); // array[0] = atoi("32")
  }
  
  sort(array, n-1);

  for (int i = 0; i < n-1; i++){
	   printf("%d ", array[i]);
  }  

  return 0;

}
```

```c
void sort(int* arr, int size);
//void sort(char* arr);
```

## Your submission

You must provide all the files that you modified including `bubble_sort.c` with implementation of selection sort algorithm.

To compile: 

```bash
gcc main.c bubble_sort.c -o sort
```

## Feedback
Great job! I expected that you will implement other functions as well :) 

Note that yoour `sortChar_bubbleSort.c` doesn't return a value (you free it before returning. This is a potential bug. 

In `bubble_sort.c` I recommend to use brackets for both loops as it will save you from some bugs :) 

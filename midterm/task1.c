#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}
#define consoleFloat(x) printf("%.3f\n", x)
#define consoleInt(x)   printf("%lld ", x)
#define newLineAndEnd   puts(""); return 0
#define line            puts("")

typedef struct Report {
  float sumOfBalances;
  float averageOfBalances;
  float maxBalance;
  float minBalance;
} Report;

// taken from task2 bubbleSort xD
void bubbleSort(float *arr, int arrSize) {
  for(int i = 0; i < arrSize - 1; i++) 
    for(int j = i + 1; j < arrSize; j++) 
      if(arr[i] > arr[j]) 
        swap(arr[i], arr[j]);
}

Report getReport(float* arr, int sizeOfArr) {
  // for easy finding maxBalance and minBalance :hehehe:
  bubbleSort(arr, sizeOfArr);

  //function to get the sum of all float elements
  float sumOfBal(float* arr, int sizeOfArr) {
    float ans = 0;
    for(int i = 0; i < sizeOfArr; i++) ans += arr[i];
    return ans;
  }

  Report *ansReport;
  ansReport = (Report*)malloc(sizeof(Report));

  ansReport->sumOfBalances = sumOfBal(arr, sizeOfArr);
  ansReport->averageOfBalances = sumOfBal(arr, sizeOfArr) / sizeOfArr;
  ansReport->maxBalance = arr[sizeOfArr-1];
  ansReport->minBalance = arr[0];

  return *ansReport;
}

void printReport(Report ans) {
  printf("%s\n", "Report of account balances!");
  printf("%s \t", "Sum of Balances: "); consoleFloat(ans.sumOfBalances);
  printf("%s \t", "Average of Balances: "); consoleFloat(ans.averageOfBalances);
  printf("%s \t", "Maximum of Balances: "); consoleFloat(ans.maxBalance);
  printf("%s \t", "Minimum of Balances: "); consoleFloat(ans.minBalance);
  printf("%s\n", "Goodbye! ;)");
}

//initialize "balances" array
const int sizeOfBalArr = 20;
float balances[20] = {432.42, 252.35, 512.6, 73.4, 1.65, 
  2984, 182.3, 3463.6, 12.3, 23.54,
  253, 8885.48, 354, 275, 753,
  734, 23, 635.6, 7346, 64};

int main() {
  //passing array to getReport function
  Report ans = getReport(balances, sizeOfBalArr);

  // printint fields of Report structure
  printReport(ans);

  newLineAndEnd;
}
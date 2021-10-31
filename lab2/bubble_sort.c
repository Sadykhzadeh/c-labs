#define swap(a, b) \
  {                \
    int temp = a;  \
    a = b;         \
    b = temp;      \
  }

void bubbleSort(int* arr) {
  int n = sizeof(*arr);
  for (int i = n - 1; i > 0; i--)
    for (int q = 0; q < i; q++)
      if (arr[q] > arr[q + 1]) swap(arr[q], arr[q + 1]);
}

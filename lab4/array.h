typedef struct Array {
    int *data;
    int size;
} Array;
Array* arrayConstructor(int size);
Array* append(Array* arr1, Array* arr2);
Array* merge(Array* arr1, Array* arr2);
# Lab-04 | Recursive structure & Array manipulations

## Ex.1: Recursive structure

![image](https://user-images.githubusercontent.com/51178055/154907969-6f6d8509-40e5-48ec-a552-a19c2be0d585.png)

```c
//recursive struct
typedef struct Node {
    int data;
    Node *next = NULL;
} Node;

//constructs a single node
Node* nodeConstructor(int value);

//appends to the end of the recursive structure a new node
//returns a node that was inserted 
Node* append(Node* head, int newValue);

//prints all structure from head to tail
void traverse(Node* head);

// Node* head; [ data = 1, next = Node{ data = 2, next = NULL} ]
// traverse(head) -> print (1) 

//for additional practice
void nodeDestructor(Node* head);
```

## Ex.2: Array manipulations

```c
typedef struct Array {
    int *data;
    int size;
} Array;

//constructor that initializes array **on the heap** with zeros
Array* arrayConstructor(int size);

//creates a new array that contains all elements of arr1 followed by all elements of arr2
// [1,2] [3,4,5] -> [1,2,3,4,5]
Array* append(Array* arr1, Array* arr2);

//given that arr1 and arr2 sorted, merge them in sorted order and return a new array

//    ex. arr1 = [1,4,9]  arr2 = [2,3,8,9]
//    result = [1,2,3,4,8,9,9]
Array* merge(Array* arr1, Array* arr2);

```

## Ex.3: Extending Node and Array with function pointers

Now let's try extend node with function pointers:

```c
//recursive struct
struct Node {
    int data;
    struct Node *next;
    struct Node* (*append)(struct Node* self, int newValue);
};

typedef struct Node Node;

```

Do the same for array: 

```c
typedef struct Array {
    int *data;
    int size;
		Array* (*append)(Array* self, Array* toAppend);
		Array* (*merge)(Array* self, Array* toMerge);
		
		//returns sum of array elements
   	int (*sum)(Array* self);

    //returns average of array elements
   	double (*average)(Array* self);
		
		// prints array in the following format: [0,1 ... N]
		void (*print)(Array* self);
		

} Array;

Array* append(Array* arr1, Array* arr2);

Array* arrayConstructor(int size){
	Array* arr1 = (Array*) malloc(sizeof(Array));
  arr1->data = (int*) calloc(size, sizeof(int));
  arr1->size = size;
  arr1->append = append;
  // init all other function pointers here...
  // ... 
  return arr1; 
}

//for additional practice
void arrayDestructor(Array* arr);

//usage: 
int main(){
	Array* arr1 = arrayConstructor(10); // array of size 10 initialized with zeros
  Array* arr2 = arrayConstructor(5); // array of size 5 initialized with zeros

  //fill up both arrays with some values; 
  // ...
  
	arr1->print(arr1);
	arr2->print(arr2);
  
  Array* merged = arr1->merge(arr1, arr2);
  Array* appended = arr1->append(arr1, arr2);
  
  merged->print(merged);

  appended->print(appended);
}
```

## Feedback
Great job :)

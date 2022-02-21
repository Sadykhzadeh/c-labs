# Lab-03 | Memory exercises in C

## Memory exercises

### Ex1. Allocating string on the heap

Write a function that asks a user to enter a string (char[]) and then copies input value into the variable stored on the heap. Your function must return a pointer to the memory allocated on the heap. You can use `strcopy` function to copy value of input into the dynamically allocated memory. 

```c
char* askForString();
```

### **Ex2. Array summation**

Write a function that takes two pointers to integer arrays and returns a new array representing a sum of the two vectors. Your new array must be allocated on the heap and your function must return a pointer to the dynamically allocated memory. If the sizes of arrays differ, assume that the missing elements are zero: 

[1,3,4] + [2,5,6] = [3,8,10] 

[-1,4] + [2,5,6] = [1,9,6] 

[1,2]+[] = [1,2]

9-

```c
int* sum(int* arr1, int* arr2, int size1, int size2); 
```

### Ex3. Caesar Cipher

**What is Caesar Cipher?**

It is one of the simplest encryption technique in which each character in plain text is replaced by a character some fixed number of positions down to it.

For example, if key is 3 then we have to replace character by another character that is 3 position down to it. Like A will be replaced by D, C will be replaced by F and so on.

For decryption just follow the reverse of encryption process.

![image](https://user-images.githubusercontent.com/51178055/154908235-68fa5eb1-7f4d-4d02-a98b-3a6260f22690.png)

Encrypt `"abc", 1` → `"bcd"`     Decrypt `"bcd",1` → `"abc"` 

Encrypt `"abc", 2` → `"cde"`     Decrypt `"cde",2` → `"abc"` 

Encrypt `"xyz", 3` → `"abc"`     Decrypt `"abc",3` → `"xyz"` 

Write a functions that gets a string, its length and rotation number and returns a pointer to new string allocated dynamically. You can assume that all input will be in lowercase. 

```c
char* caesarEncrypt(char* str, int stringLength, int rotationNumber);

char* caesarDecrypt(char* str, int stringLength, int rotationNumber);
```

## Feedback
Excellent job using macros :) I love these: 

```c
#define elif else if
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define cout(a) printf("%d ", a)
#define end printf("\n");return 0
```

[have look here as well](https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/)

Great piece of work! Thumbs up!

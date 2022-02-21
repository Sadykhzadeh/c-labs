# Lab-01 | Implementing own library
## Lab 01

In this laboratory you are going to build your own first library that can be used in other projects. Additionally you will extend a driver program that allows user to work with your library. Below is the header file that you need to implement. For some of this problems you can make recursive and iterative implementations and then compile them into different versions of your library. Then you can use different implementations of your library inside your driver program. 

```c
//must return decimal representation of binary number
long binaryToDecimal(long binary);

//must return binary representation of decimal
long decimalToBinary(long decimal);

//converts miles to km. Should print error on invalid input
double milesToKilometers(double miles);

//converts km to miles. Should print error on invalid input
double kilometersToMiles(double kilometers);

//checks whether the number is prime and prints "Prime" or "Not Prime"
void primeCheck(long number);

//checks whether the number is palindrome and prints "Palindrome" or "Not Palindrome"
void palindromeCheck(long number);

//returns a reverse of a number (12345 -> 54321)
long reverse(long number);

//returns random number in range [min,max]
int randomInRange(int min, int max);

//returns GCD(Greatest Common Divisor) of two nums
int gcd(int num1, int num2);

//returns LCM of two nums
int lcm(int num1, int num2);
```

The driver program that will utilize your library is given below. Note that it uses arguments in `main()` function. This allows to run a program with custom arguments and provide input to it through command line. Your task is to extend this driver so that user is able to choose any function from your library and provide input via commandline. Ideally your user should be able to run your program in the following way: 

```bash
./driver 1 1010101
```

Here `1` stands for command (binary to decimal) and `1010101` is the input to the function. 

Note that some of your functions need more than 1 argument. So for example 

```bash
./driver 3 0 100
```

Might stand for generating random numbers in the range [0,100]. You are free to choose the ordering of your functions. Alternatively, you can use `char` for getting the command or even string (but this is a topic for research). 

```c
#include <stdio.h>
#include <stdlib.h>
#include "first_library.h"

#define BINARY_TO_DECIMAL 1 // this is called macros. Compiler will replace all 
#define DECIMAL_TO_BINARY 2 // occurances of this definitions in code with 
														// corresponding values

int main(int argNum, char **args) {

    if (argNum - 1) {
        printf("You provided %d arguments\n", argNum - 1);
    } else {
        printf("You didn't provide any arguments\n");
        return -1;
    }

    int operation = atoi(args[1]); // atoi converts string (char[] | char*) to int
		int input1 = atoi(args[2]);
    int input2 = atoi(args[3]);

    switch (operation) {
        case BINARY_TO_DECIMAL: {
            printf("%ld", binaryToDecimal(input));
            break;
        }
        case DECIMAL_TO_BINARY: {
            printf("%ld", decimalToBinary(12));
            break;
        }
    }
    return 0;
}
```

[atoi](https://www.cplusplus.com/reference/cstdlib/atoi/)

### Note about command line arguments

Command-line arguments are given after the name of the program in command-line shell of Operating Systems.

To pass command line arguments, we typically define `main()` with two arguments : first argument is the number of command line arguments and second is list of command-line arguments. 

```c
int main(int argc, char *argv[]) { /* ... */ }
```

or

```c
int main(int argc, char **argv) { /* ... */ }
```

- **`argc` (ARGument Count)** is int and stores number of command-line arguments passed by the user including the name of the program. So if we pass a value to a program, value of `argc` would be 2 (one for argument and one for program name)
- The value of `argc` should be non negative.
- **`argv`(ARGument Vector)** is array of character pointers listing all the arguments.
- If `argc` is greater than zero, the array elements from `argv[0]` to `argv[argc-1]` will contain pointers to strings.
- `argv[0]` is the name of the program. After that till `argv[argc-1]` every element is a command line argument.

## Makefile example

```makefile
default:
	gcc -O *.c -o driver.o # will compile all .c files in directory into single driver.o file
library:
	gcc -c first_library.c -o first_library.so # will compile first_library.c into first_library.so 

# once you compiled your library you can compile driver together with 
# implementation of your library: 
# gcc driver.c first_library.so -o driver.o
```

## Feedback
Great job in the implementations! 👏 

However, you used a single .h file and added all implementations there. It's not a good practice to put implementation into header file. Also we loose the whole point of organization of project and capability of separating definition of library from its implementation. 

Next time try to keep your header and implementations in sepaarate .h and .c files

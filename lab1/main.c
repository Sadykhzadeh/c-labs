#include <stdio.h>

#include <stdlib.h>

#include "my-first-lib.h"

#define BINARY_TO_DECIMAL 1
#define DECIMAL_TO_BINARY 2
#define MILES_TO_KILOMETERS 3
#define KILOMETERS_TO_MILES 4
#define PRIME_CHECK 5
#define REVERSE 6
#define PALINDROME_CHECK 7
#define RANDOM_IN_RANGE 8
#define GCD 9
#define LCM 10

int main(int argNum, char** args) {
  if (argNum - 1)
    printf("You provided %d arguments\n", argNum - 1);
  else {
    printf("You didn't provide any arguments\n");
    return -1;
  }

  switch (atoi(args[1])) {
    case BINARY_TO_DECIMAL: {
      printf("%ld\n", binaryToDecimal(atoi(args[2])));
      break;
    }
    case DECIMAL_TO_BINARY: {
      printf("%ld\n", decimalToBinary(atoi(args[2])));
      break;
    }
    case MILES_TO_KILOMETERS: {
      printf("%g\n", milesToKilometers(atoi(args[2])));
      break;
    }
    case KILOMETERS_TO_MILES: {
      printf("%g\n", kilometersToMiles(atoi(args[2])));
      break;
    }
    case PRIME_CHECK: {
      primeCheck(atoi(args[2]));
      break;
    }
    case REVERSE: {
      printf("%ld\n", reverse(atoi(args[2])));
      break;
    }
    case PALINDROME_CHECK: {
      palindromeCheck(atoi(args[2]));
      break;
    }
    case RANDOM_IN_RANGE: {
      printf("%d\n", randomInRange(atoi(args[2]), atoi(args[3])));
      break;
    }
    case GCD: {
      printf("%d\n", gcd(atoi(args[2]), atoi(args[3])));
      break;
    }
    case LCM: {
      printf("%d\n", lcm(atoi(args[2]), atoi(args[3])));
      break;
    }
  }
  return 0;
}
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

// Every branch below reads args[2], and three of them read args[3], so this
// says how many each command needs. Reading past argNum handed atoi() a null
// pointer, so `./prog 5` with no value crashed instead of complaining.
static int needsArgs(int command) {
  switch (command) {
    case RANDOM_IN_RANGE:
    case GCD:
    case LCM:
      return 3;
    default:
      return 2;
  }
}

int main(int argNum, char** args) {
  if (argNum - 1)
    printf("You provided %d arguments\n", argNum - 1);
  else {
    printf("You didn't provide any arguments\n");
    return -1;
  }

  const int command = atoi(args[1]);
  if (argNum - 1 < needsArgs(command)) {
    printf("Command %d needs %d arguments\n", command, needsArgs(command));
    return -1;
  }

  switch (command) {
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
      // lcm returns long now that it no longer overflows an int.
      printf("%ld\n", lcm(atoi(args[2]), atoi(args[3])));
      break;
    }
    default: {
      // An unrecognised command used to fall out of the switch and exit 0.
      printf("Unknown command %d\n", command);
      return -1;
    }
  }
  return 0;
}
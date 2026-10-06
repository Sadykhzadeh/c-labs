#ifndef MY_FIRST_LIB_H
#define MY_FIRST_LIB_H

/* printf and rand were used here while only math.h was included, so this
   header only compiled when whatever included it had already pulled in stdio
   and stdlib - including it first failed with an implicit declaration. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// must return decimal representation of binary number
long binaryToDecimal(long binary) {
  /* pow() returns a double, so every digit went through floating point for
     what is an exact integer calculation. */
  long ans = 0, place = 1;
  while (binary) {
    long temp = binary % 10;
    binary /= 10;
    ans += temp * place;
    place *= 2;
  }
  return ans;
}
// must return binary representation of decimal
long decimalToBinary(long decimal) {
  long ans = 0;
  long i = 1;

  while (decimal) {
    long temp = decimal % 2;
    decimal /= 2;
    ans += (temp * i);
    i *= 10;
  }
  return ans;
}
// converts miles to km. Should print error on invalid input
double milesToKilometers(double miles) { return miles * 1.609344; }
// converts km to miles. Should print error on invalid input
double kilometersToMiles(double kilometers) { return kilometers / 1.609344; }
// checks whether the number is prime and prints "Prime" or "Not Prime"
void primeCheck(long number) {
  /* This started at `number % 2 == 0`, which called 2 not prime, and then let
     1, 0 and every negative through to the loop, which does not run for them
     - so they were all reported prime. */
  if (number < 2) {
    printf("Not Prime\n");
    return;
  }
  if (number % 2 == 0) {
    printf(number == 2 ? "Prime\n" : "Not Prime\n");
    return;
  }
  /* i * i <= number rather than i <= sqrt(number) + 1: no call to sqrt on
     every iteration, and no reliance on the rounding of its result. */
  for (long i = 3; i * i <= number; i += 2)
    if (number % i == 0) {
      printf("Not Prime\n");
      return;
    }
  printf("Prime\n");
  return;
}
// returns a reverse of a number (12345 -> 54321)
long reverse(long number) {
  long reverseNumber = 0, temp = number;
  while (temp) {
    reverseNumber *= 10;
    reverseNumber += temp % 10;
    temp /= 10;
  }
  return reverseNumber;
}
// checks whether the number is palindrome and prints "Palindrome" or "Not
// Palindrome"
void palindromeCheck(long number) {
  if (number == reverse(number))
    printf("Palindrome\n");
  else
    printf("Not Palindrome\n");
  return;
}
// returns random number in range [min,max]
int randomInRange(int mi, int ma) { return (rand() % (ma - mi + 1)) + mi; }
// returns GCD(Greatest Common Divisor) of two nums
int gcd(int num1, int num2) {
  if (!num2) return num1;
  return gcd(num2, num1 % num2);
}
// returns LCM(Least Common Multiple) of two nums
long lcm(int num1, int num2) {
  /* num1 * num2 / gcd overflowed before it divided: lcm(100000, 99999) came
     out as 1409965408 instead of 9999900000. Dividing first keeps the
     intermediate value down, and the result needs more than an int. */
  int divisor = gcd(num1, num2);
  if (!divisor) return 0;
  return (long)(num1 / divisor) * num2;
}

#endif

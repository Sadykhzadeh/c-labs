#include <math.h>

// must return decimal representation of binary number
long binaryToDecimal(long binary) {
  long ans = 0, i = 0;
  while (binary) {
    long temp = binary % 10;
    binary /= 10;
    ans += (temp * pow(2, i));
    i++;
  }
  return ans;
};
// must return binary representation of decimal
long decimalToBinary(long decimal) {
  long long ans = 0;
  int i = 1;

  while (decimal) {
    long temp = decimal % 2;
    decimal /= 2;
    ans += (temp * i);
    i *= 10;
  }
  return ans;
};
// converts miles to km. Should print error on invalid input
double milesToKilometers(double miles) { return miles * 1.609344; };
// converts km to miles. Should print error on invalid input
double kilometersToMiles(double kilometers) { return kilometers / 1.609344; };
// checks whether the number is prime and prints "Prime" or "Not Prime"
void primeCheck(long number) {
  if (number % 2 == 0) {
    printf("Not Prime\n");
    return;
  }
  for (int i = 3; i <= sqrt(number) + 1; i += 2)
    if (number % i == 0) {
      printf("Not Prime\n");
      return;
    }
  printf("Prime\n");
  return;
};
// returns a reverse of a number (12345 -> 54321)
long reverse(long number) {
  long reverseNumber = 0, temp = number;
  while (temp) {
    reverseNumber *= 10;
    reverseNumber += temp % 10;
    temp /= 10;
  }
  return reverseNumber;
};
// checks whether the number is palindrome and prints "Palindrome" or "Not
// Palindrome"
void palindromeCheck(long number) {
  if (number == reverse(number))
    printf("Palindrome\n");
  else
    printf("Not Palindrome\n");
  return;
};
// returns random number in range [min,max]
int randomInRange(int mi, int ma) { return (rand() % (ma - mi + 1)) + mi; };
// returns GCD(Greatest Common Divisor) of two nums
int gcd(int num1, int num2) {
  if (!num2) return num1;
  return gcd(num2, num1 % num2);
};
// returns HCF(Highest Common Factor) of two nums
int lcm(int num1, int num2) { return (num1 * num2) / gcd(num1, num2); };
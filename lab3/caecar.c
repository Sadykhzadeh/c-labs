#include <stdio.h>
#define elif else if
#define end     \
  printf("\n"); \
  return 0

void caesarEncrypt(char* plainText, int len, int rotationNumber) {
  char* answerArray[len];
  for (int i = 0; i < len; ++i) {
    char ch = plainText[i];
    if (ch >= 'a' && ch <= 'z') {
      ch += rotationNumber;
      if (ch > 'z') ch -= 'z' + 'a' - 1;
    }
    elif(ch >= 'A' && ch <= 'Z') {
      ch += rotationNumber;
      if (ch > 'Z') ch -= 'Z' + 'A' - 1;
    }
    answerArray[i] = ch;
  }
  for (int i = 0; i < len; i++) printf("%c", answerArray[i]);
}

void caesarDecrypt(char* plainText, int len, int rotationNumber) {
  char* answerArray[len];
  for (int i = 0; i < len; ++i) {
    char ch = plainText[i];
    if (ch >= 'a' && ch <= 'z') {
      ch -= rotationNumber;
      if (ch < 'a') {
        ch += 'z' - 'a' + 1;
      }
    }
    elif(ch >= 'A' && ch <= 'Z') {
      ch -= rotationNumber;
      if (ch < 'A') {
        ch += 'Z' - 'A' + 1;
      }
    }
    answerArray[i] = ch;
  }
  for (int i = 0; i < len; i++) printf("%c", answerArray[i]);
}

int main() {
  char* text = "hello world";
  int len = 11, key = 2;
  caesarEncrypt(text, len, key);
  printf("\n");
  text = "jgnnq yqtnf";
  caesarDecrypt(text, len, key);
  end;
}

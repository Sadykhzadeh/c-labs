#include <stdio.h>
#define elif else if
#define end     \
  printf("\n"); \
  return 0

/* The alphabet wrapped by subtracting 'z' + 'a' - 1, which is 218, rather
   than the 26 letters between them - so anything that ran past 'z' came back
   as a control character. Working modulo 26 also copes with a rotation of
   more than 26, or a negative one. */
void caesarEncrypt(const char* plainText, int len, int rotationNumber) {
  /* answerArray was declared char*[], an array of pointers, and then assigned
     a char - which gcc 14 rejects outright, and printf("%c", ...) was handed
     a pointer. */
  char answerArray[len];
  int shift = ((rotationNumber % 26) + 26) % 26;
  for (int i = 0; i < len; ++i) {
    char ch = plainText[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = (char)('a' + (ch - 'a' + shift) % 26);
    }
    elif(ch >= 'A' && ch <= 'Z') {
      ch = (char)('A' + (ch - 'A' + shift) % 26);
    }
    answerArray[i] = ch;
  }
  for (int i = 0; i < len; i++) printf("%c", answerArray[i]);
}

void caesarDecrypt(const char* plainText, int len, int rotationNumber) {
  char answerArray[len];
  int shift = ((rotationNumber % 26) + 26) % 26;
  for (int i = 0; i < len; ++i) {
    char ch = plainText[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = (char)('a' + (ch - 'a' - shift + 26) % 26);
    }
    elif(ch >= 'A' && ch <= 'Z') {
      ch = (char)('A' + (ch - 'A' - shift + 26) % 26);
    }
    answerArray[i] = ch;
  }
  for (int i = 0; i < len; i++) printf("%c", answerArray[i]);
}

int main(void) {
  const char* text = "hello world";
  int len = 11, key = 2;
  caesarEncrypt(text, len, key);
  printf("\n");
  text = "jgnnq yqtnf";
  caesarDecrypt(text, len, key);
  end;
}

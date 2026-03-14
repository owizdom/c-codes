// Challenge: Reverse a String
// Goal: Reverse the characters of a string and print it
#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello World";
  int len = strlen(str);
  char reversed[50];

  for (int i = 0; i < len; i++) {
    reversed[i] = str[len - 1 - i];
  }
  reversed[len] = '\0';

  printf("Original: %s\n", str);
  printf("Reversed: %s\n", reversed);

  return 0;
}

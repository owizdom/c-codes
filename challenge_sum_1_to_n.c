// Challenge: Sum from 1 to N
// Goal: Calculate and print the sum of all integers from 1 to N
#include <stdio.h>

int main() {
  int n = 10;
  int sum = 0;

  for (int i = 1; i <= n; i++) {
    sum += i;
  }

  printf("Sum of 1 to %d = %d\n", n, sum);
  return 0;
}

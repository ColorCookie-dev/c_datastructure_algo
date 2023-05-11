#include <stdio.h>

int fib(int n) {
  if (n == 1) return 1;
  if (n == 2) return 1;
  return fib(n - 1) + fib(n - 2);
}

void fibn(int n) {
  int i;
  for (i = 1; i <= n; i++)
    printf("%d\n", fib(i));
}

int main() {
  fibn(5);
  fibn(10);
  fibn(15);

  return 0;
}

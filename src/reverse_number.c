#include <stdio.h>

int main() {
  int n, m = 0;

  printf("Enter a number: ");
  scanf("%d", &n);

  while (n != 0) {
	m = m * 10 + (n % 10);
	n /= 10;
  }

  printf("reverse: %d\n", m);
}

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

_Bool isprime(uint64_t i) {
  for (uint64_t j = 2; j <= sqrt(i); j++) {
    if (i % j == 0)
      return false;
  }

  return true;
}

uint64_t get_u64_input(char *prompt) {
  uint64_t n;
  printf("%s", prompt);
  scanf("%" PRIu64, &n);
  return n;
}

int main() {
  uint64_t n = get_u64_input("Enter a number: ");

  for (uint64_t i = 2; i <= n; i++) {
    if (isprime(i))
      printf("%" PRIu64 "\n", i);
  }

  return 0;
}

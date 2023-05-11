#include <inttypes.h>
#include <math.h>
#include <stdio.h>

uint64_t fact(uint64_t n) {
  uint64_t m;
  for (m = 1; n > 1; n--) {
    m *= n;
  }
  return m;
}

uint64_t fact_rec(uint64_t n) {
  if (n == 0)
    return 1;
  return n * fact_rec(n - 1);
}

uint64_t get_u64_input(char *prompt) {
  uint64_t n;
  printf("%s", prompt);
  // PRIu64 is format specifier for uint64_t
  scanf("%" PRIu64, &n);
  return n;
}

int main() {
  uint64_t n = get_u64_input("Enter a number: ");

  printf("(recursive) %" PRIu64 "! = %" PRIu64 "\n", n, fact_rec(n));
  printf("%" PRIu64 "! = %" PRIu64 "\n", n, fact(n));

  return 0;
}

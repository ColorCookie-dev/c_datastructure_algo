#include <inttypes.h>
#include <stdio.h>

uint64_t gcd(uint64_t a, uint64_t b) {
  uint64_t g = (a < b) ? a : b;
  for (; g > 0; g--)
    if ((a % g == 0) && (b % g == 0))
      break;
  return g;
}

uint64_t gcd_rec_impl(uint64_t a, uint64_t b, uint64_t g) {
  if ((a % g == 0) && (b % g == 0))
    return g;
  return gcd_rec_impl(a, b, g - 1);
}

uint64_t gcd_rec(uint64_t a, uint64_t b) {
  return gcd_rec_impl(a, b, (a < b) ? a : b);
}

int main() {
  uint64_t a, b;
  printf("Enter 2 number with space: ");
  scanf("%" PRIu64 " %" PRIu64, &a, &b);
  printf("(recursive) GCD is %" PRIu64 "\n", gcd_rec(a, b));
  printf("GCD is %" PRIu64 "\n", gcd(a, b));
  return 0;
}

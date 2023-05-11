#include <stdbool.h>
#include <stdio.h>

_Bool leap_year(int y) {
  if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) {
    return true;
  } else {
    return false;
  }
}

_Bool leap_year_conditional(int y) {
  return (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) ? true : false;
}

#define assert(x)                                                              \
  if (x) {                                                                     \
    puts("Passed!");                                                         \
  } else {                                                                     \
    puts("Failed");                                                          \
    return;                                                                    \
  }

void test_leap_year() {
  assert(!leap_year(100));
  assert(!leap_year(1000));
  assert(leap_year(2000));
  assert(leap_year(2000));
  assert(leap_year(2012));
  assert(!leap_year(2015));
}

int main() {
  int y;

  printf("Tests\n");
  test_leap_year();
  printf("Testing End\n");

  printf("> ");
  scanf("%d", &y);

  if (leap_year(y)) {
    printf("Leap year");
  } else {
    printf("Not a leap year");
  }

  return 0;
}

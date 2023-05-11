#include <stdio.h>

int main() {
  double sum, a;
  int i;
  
  for (i = 0; i < 5; i++) {
	printf("Enter sub %%: ");
	scanf("%lf", &a);

	sum += a;
  }

  sum /= 5;

  if (sum >= 60.0) {
	puts("1");
  } else if (sum >= 50.0 && sum <= 59.0) {
	puts("2");
  } else if (sum >= 40.0 && sum <= 49.0) {
	puts("3");
  } else {
	puts("F");
  }

  return 0;
}

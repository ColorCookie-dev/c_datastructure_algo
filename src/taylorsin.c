#include <math.h>
#include <stdio.h>

int fact(int n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}

double taylorsin(double x, int n) {
  double current_term;

  if (n == 0) return x;

  current_term = pow(-x, 2 * n + 1) / fact(2 * n + 1);
  return taylorsin(x, n - 1) + current_term;
}

int main() {
  double x;
  int n;

  printf("Enter x, n: ");
  scanf("%lf %d", &x, &n);
  printf("%lf\n", taylorsin(x, n - 1));

  return 0;
}

#include <stdio.h>
#include <math.h>

int solutions(double a, double b, double c, double *x, double *y)
{
  double d = pow(b, 2) - 4*a*c;

  if (d < 0)
	return 0; // Signifies no real solutions

  *x = ((-1*b) + sqrt(d))/2/a;
  *y = ((-1*b) - sqrt(d))/2/a;

  return 1; // Signifies success
}

int main()
{
  double a, b, c, x, y;

  printf("Enter a, b, c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  if (!solutions(a, b, c, &x, &y))
	puts("No real solutions.");
  else
	printf("The solutions are: %lf, %lf\n", x, y);

  return 0;
}

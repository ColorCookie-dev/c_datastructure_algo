#include <stdio.h>

void printline(char ch, int len);
int value(float p, float r, int t);

int main() {
  float p, r, a;
  int t;

  printf("Enter principal, interest, rate and period\n");
  scanf("%f %f %d", &p, &r, &t);

  printline('*', 52);
  a = value(p, r, t);

  printf("\n%f\t%f\t%d\t%f\n", p, r, t, a);
  printline('=', 52);

  return 0;
}

void printline(char ch, int len) {
  int i;
  for (i = 1; i <= len; i++)
    printf("%c", ch);
  printf("\n");
}

int value(float p, float r, int t) {
  int year;
  float sum;
  sum = p;
  year = 1;

  while (year <= t) {
    sum *= (1 + r);
    year++;
  }

  return sum;
}

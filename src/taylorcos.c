#include <stdio.h>

int main() {
    double x, u = 1, s = 1;
    int i;
    printf("Enter an angle: ");
    scanf("%lf", &x);

    for (i = 2; i <= 10; i += 2) {
        u *= -1*(x*x)/i/(i-1);
        s += u;
    }

    printf("Taylor approx of cos(%lf) = %lf\n", x, s);
    return 0;
}

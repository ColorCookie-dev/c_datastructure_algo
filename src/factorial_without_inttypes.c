#include <stdio.h>
#include <math.h>

unsigned long long fact(unsigned long long n) {
    unsigned long long m;
    for (m = 1; n > 1; n--) {
        m *= n;
    }
    return m;
}

unsigned long long fact_rec(unsigned long long n) {
    if (n == 0)
        return 1;
    return n*fact_rec(n-1);
}

int main() {
    unsigned long long n;
    printf("Enter a number: ");
    scanf("%llu", &n);
    printf("(recursive) %llu! = %llu\n", n, fact_rec(n));
    printf("%llu! = %llu\n", n, fact(n));
    return 0;
}

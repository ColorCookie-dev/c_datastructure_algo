#include <stdio.h>

int main() {
    int n, s = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n != 0) {
        s += n % 10;
        n /= 10; // Integer division (floor div)
    }

    printf("The sum of the digits: %d\n", s);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int a[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            a[i][j] = j;

    printf("%d\n", *(*(a+2)+5));
    return 0;
}

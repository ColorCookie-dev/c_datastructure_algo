#include <stdio.h>

int main() {
    int x = 1;
    int y;

    //y = (x = x + 1, x*5);
    y = (x = x + 5, x*5);
    printf("x:%d y:%d\n", x, y);

    return 0;
}

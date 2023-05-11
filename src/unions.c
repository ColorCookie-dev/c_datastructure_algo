#include <stdio.h>

union u {
    int x;
    int y;
};

struct s {
    union u u1;
    int z;
};

int main() {
    struct s s1 = {10, 30};
    printf("%lu", sizeof(s1));
    printf(" %d %d %d\n", s1.u1.x, s1.u1.y, s1.z);
    return 0;
}

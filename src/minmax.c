#include <stdio.h>

int min(int l[], size_t len) {
    int m, i;

    if (len < 1)
        return 0;

    m = l[0];
    for (i = 1; i < len; i++) {
        if (m > l[i])
            m = l[i];
    }

    return m;
}

int max(int l[], size_t len) {
    int m, i;
    if (len < 1)
        return 0;

    m = l[0];
    for (i = 1; i < len; i++) {
        if (m < l[i])
            m = l[i];
    }

    return m;
}

int main() {
    int i, l[5];

    for (i = 0; i < 5; i++) {
        printf("Enter a number in list: ");
        scanf("%d", &l[i]);
    }

    printf("Min: %d\nMax: %d\n", min(l, 5), max(l, 5));
    return 0;
}

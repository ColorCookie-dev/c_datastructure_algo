#include <stdio.h>
#include <inttypes.h>

#define LEN 5

inline void swap(int64_t *p, int64_t *q) {
    int t = *p;
    *p = *q;
    *q = t;
}

void bubble_sort(int64_t l[], size_t len) {
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (l[j] > l[j + 1]) {
                swap(&l[j], &l[j + 1]);
            }
        }
    }
}

int main() {
    int64_t l[LEN];
    size_t i;

    for (i = 0; i < LEN; i++) {
        printf("Enter a number in list: ");
        scanf("%" PRId64, &l[i]);
    }

    bubble_sort(l, LEN);

    for (i = 0; i < LEN; i++) {
        printf("%" PRId64 " ", l[i]);
    }

    puts("");

    return 0;
}

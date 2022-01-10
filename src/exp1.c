#include <stdio.h>

int main() {
    char line[100];
    int i;
START:
    printf("Enter a number: ");
    if (fgets(line, sizeof(line), stdin)) {
        if (1 == sscanf(line, "%d", &i)) {
            printf("%d\n", i);
        } else {
            printf("Enter a valid number!\n");
            goto START;
        }
    }
    return 0;
}

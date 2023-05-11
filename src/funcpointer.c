#include <stdio.h>

void hello(char *str) {
    printf("Hello %s\n", str);
}

typedef void (*F_PTR)(char*);

void call(F_PTR func) {
    func("World");
}

int main() {
    call(&hello);
    return 0;
}

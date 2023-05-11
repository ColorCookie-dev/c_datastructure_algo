#include <stdio.h>

void upper(char *str) {
	while (*str != 0) {
		if (*str >= 'a' && *str <= 'z') *str -= 32;
		str++;
	}
}

int main() {
	char str[] = "Hello";
	upper(str);
	puts(str);

	return 0;
}

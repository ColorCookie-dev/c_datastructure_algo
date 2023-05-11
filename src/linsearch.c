#include <stdio.h>

void linsearch(int l, int list[l], int to) {
	while (l--) {
		if (list[l] == to) {
			printf("Found %d at location %d\n", to, l + 1);
			return;
		}
	}
	printf("%d not found\n", to);
}

int binsearch(int *l, int low, int high, int data) {
	int mid = (high + low) / 2;
	if (low > high) return -1;
	if (l[mid] == data) return mid;
	else if (l[mid] > data) return binsearch(l, low, mid - 1, data);
	else return binsearch(l, mid + 1, high, data);
}

int main() {
	int l[] = {10, 20, 50, 60, 80, 100, 2000, 4000};
	int i;
	linsearch(sizeof(l)/sizeof(int), l, 30);
	linsearch(sizeof(l)/sizeof(int), l, 40);
	linsearch(sizeof(l)/sizeof(int), l, 50);

	i = binsearch(l, 0, sizeof(l)/sizeof(int) - 1, 50);
	if (i == -1) {
		puts("50 not found");
	} else {
		printf("50 found at %d\n", i + 1);
	}

	i = binsearch(l, 0, sizeof(l)/sizeof(int) - 1, 4000);
	if (i == -1) {
		puts("4000 not found");
	} else {
		printf("4000 found at %d\n", i + 1);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

void show_arr(int *arr, int size) {
	int i;
	puts("Array:");
	for (i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	puts("\nEND");
}

void merge(int *A, int l, int q, int h) {
	int s1 = q - l + 1;
	int s2 = h - q;
	int *L = malloc(s1 * sizeof(int));
	int *R = malloc(s2 * sizeof(int));
	int i, j, k;

	for (i = 0; i < s1; i++) {
		L[i] = A[l + i];
	}

	for (i = 0; i < s2; i++) {
		R[i] = A[q + 1 + i];
	}

	i = 0;
	j = 0;
	k = 0;
	while (j < s1 && k < s2) {
		if (L[j] < R[k]) {
			A[i++] = L[j++];
		} else {
			A[i++] = R[k++];
		}
	}

	while (j < s1) {
		A[i++] = L[j++];
	}

	while (k < s2) {
		A[i++] = R[k++];
	}
}

void mergesort(int *arr, int l, int h) {
	int q;
	if (l < h) {
		q = (l + h) / 2;
		mergesort(arr, l, q);
		mergesort(arr, q + 1, h);
		merge(arr, l, q, h);
	}
}

int main() {
	int arr[10] = {9, 8, 7, 6, 5, 4, 1, 2, 3, 0};
	mergesort(arr, 0, 10 - 1);
	show_arr(arr, 10);
}

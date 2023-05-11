#include <stdio.h>

void show_arr(int *arr, int size) {
	int i;
	puts("Array:");
	for (i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	puts("\nEND");
}

int partition(int *arr, int l, int h) {
	int pivot = arr[h];
	int i = l - 1, j, temp;

	for (j = l; j <= h - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[h];
	arr[h] = temp;
	return i + 1;
}

void quicksort(int *arr, int l, int h) {
	int q;
	if (l < h) {
		q = partition(arr, l, h);
		quicksort(arr, l, q - 1);
		quicksort(arr, q + 1, h);
	}
}

int main() {
	int arr[10] = {9, 3, 5, 2, 8, 6, 4, 1, 7, 0};
	quicksort(arr, 0, 10 - 1);
	show_arr(arr, 10);
}

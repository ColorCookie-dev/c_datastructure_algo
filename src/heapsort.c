#include <stdio.h>

void print_arr(int arr[], int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		printf("%d, ", arr[i]);
	printf("%d\n", arr[i]);
}

void heapify(int *arr, int n, int p)
{
	int big = p, r, l, temp;
	l = 2*p + 1;
	r = l + 1;
	if ((l < n) && (arr[l] > arr[big]))
		big = l;

	if ((r < n) && (arr[r] > arr[big]))
		big = r;

	if (big != p)
	{
		temp = arr[big];
		arr[big] = arr[p];
		arr[p] = temp;
		heapify(arr, n, big);
	}
}

void build_max_heap(int *arr, int n)
{
	int i;
	for (i = n - 1; i > 0; i -= 2)
	{
		int p = (i - 1)/2;
		heapify(arr, n, p);
	}

}

void heapsort(int *arr, int n)
{
	int i, temp;
	for (i = n; i > 0; i--)
	{
		build_max_heap(arr, i);
		temp = arr[i - 1];
		arr[i - 1] = arr[0];
		arr[0] = temp;
	}
}

int main()
{
	int arr[] = {4, 5, 2, 1, 10, 9, 3, 7, 6, 8};
	print_arr(arr, sizeof(arr)/sizeof(arr[0]));
	heapsort(arr, sizeof(arr)/sizeof(arr[0]));
	print_arr(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}

#include <inttypes.h>
#include <stdio.h>

#define N 5

void print_arr(int *arr, int n)
{
  int i;

  for (i = n - 1; i >= 0; i--)
    printf("%d ", arr[i]);
}

int main()
{
  int i, arr[N];

  for (i = 0; i < N; i++)
  {
    printf("Enter the element: ");
    scanf("%d", &arr[i]);
  }

  print_arr(arr, N);

  return 0;
}

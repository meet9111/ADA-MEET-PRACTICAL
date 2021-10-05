#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeap(int arr[], int n, int i)
{

    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max])
        max = left;

    if (right < n && arr[right] > arr[max])
        max = right;

    if (max != i)
    {
        swap(&arr[i], &arr[max]);
        maxHeap(arr, n, max);
    }
}

void HeapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeap(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeap(arr, i, 0);
    }
}

void Array(int arr[], int n)
{

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {90,75,61,12,31};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort(arr, n);

    printf("Sorted array is \n");
    Array(arr, n);
}

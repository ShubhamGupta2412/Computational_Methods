#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;     // Left child
    int right = 2 * i + 1; // Right child

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify(arr, n, i);

    for (int i = n; i > 1; i--) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        heapify(arr, i - 1, 1);
    }
}

void printArray(int arr[], int size) {
    for (int i = 1; i <= size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {0, 12, 11, 13, 5, 6, 7}; // 0 is a placeholder for 1-based indexing
    int n = sizeof(arr) / sizeof(arr[0]) - 1;

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}


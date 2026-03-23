#include <stdio.h>

void swap(int* a, int* b);

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for(j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {   
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i;

    //Input size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];   

    // Input elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Display unsorted array
    printf("\nUnsorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Sort
    quickSort(arr, 0, n - 1);

    //Display sorted array
    printf("\nSorted array in Descending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
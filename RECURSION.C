#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    int mid;

    if (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;             
        else if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);  
        else
            return binarySearch(arr, mid + 1, high, key);
    }

    return -1; 
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 50;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

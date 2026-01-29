#include <stdio.h>
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {5, 3, 7, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = linearSearch(arr, n, tar

#include <stdio.h>

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int a[100], n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition

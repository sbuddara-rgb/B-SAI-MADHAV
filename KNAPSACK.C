#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(struct Item arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i].ratio < arr[j].ratio) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

float fractionalKnapsack(int capacity, struct Item arr[], int n) {
    float totalValue = 0.0;

    for(int i = 0; i < n; i++) {
    
        if(capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        }
      
        else {
            totalValue += arr[i].ratio * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    sortItems(arr, n);

    float maxValue = fractionalKnapsack(capacity, arr, n);

    printf("Maximum value = %.2f\n", maxValue);

    return 0;
}

#include <stdio.h>
#define MAX 10
#define INF 9999

int n;
int cost[MAX][MAX];
int visited[MAX];

int tsp(int pos, int count, int costSoFar) {
    if (count == n && cost[pos][0] != 0) {
        return costSoFar + cost[pos][0]; // return to start
    }

    int minCost = INF;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[pos][i] != 0) {
            visited[i] = 1;
            int newCost = tsp(i, count + 1, costSoFar + cost[pos][i]);
            if (newCost < minCost)
                minCost = newCost;
            visited[i] = 0;
        }
    }

    return minCost;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1; // start from city 0

    int minCost = tsp(0, 1, 0);

    printf("Minimum travelling cost: %d\n", minCost);

    return 0;
}

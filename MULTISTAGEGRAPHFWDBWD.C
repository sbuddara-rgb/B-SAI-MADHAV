#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
    int n = 8;

    int cost[MAX][MAX] = {
        {0,1,2,5,0,0,0,0},
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0}
    };

    int distF[MAX], distB[MAX], path[MAX];

    for (int i = 0; i < n; i++)
        distF[i] = INF;

    distF[0] = 0; // source

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0 && distF[i] + cost[i][j] < distF[j]) {
                distF[j] = distF[i] + cost[i][j];
            }
        }
    }


    for (int i = 0; i < n; i++)
        distB[i] = INF;

    distB[n - 1] = 0; 

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] + distB[j] < distB[i]) {
                distB[i] = cost[i][j] + distB[j];
                path[i] = j;
            }
        }
    }


    printf("Forward Method Minimum Cost: %d\n", distF[n - 1]);

    printf("Backward Method Minimum Cost: %d\n", distB[0]);

    printf("Path (Backward): ");
    int i = 0;
    while (i != n - 1) {
        printf("%d -> ", i);
        i = path[i];
    }
    printf("%d\n", n - 1);

    return 0;
}

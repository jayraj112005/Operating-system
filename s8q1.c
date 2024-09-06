#include <stdio.h>

int main() {
    int n, m;

    // Accept the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int max[n][m], allocation[n][m], need[n][m];

    // Accept the Max matrix
    printf("Enter the Max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Max[%d][%d]: ", i, j);
            scanf("%d", &max[i][j]);
        }
    }

    // Accept the Allocation matrix
    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Allocation[%d][%d]: ", i, j);
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculate the Need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Display the Need matrix
    printf("The Need matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}

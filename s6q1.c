#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Record the start time
    start = clock();

    // Code block for which the execution time is measured
    printf("Performing some tasks...\n");

    // Example: Simple task - a loop
    for (long long i = 0; i < 1000000000; i++) {
        // Simulate some work
    }

    // Record the end time
    end = clock();

    // Calculate the CPU time used in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}

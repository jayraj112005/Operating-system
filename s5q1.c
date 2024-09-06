#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t pid;

    // Create a child process using fork()
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // Inside the child process
        printf("Child process (before nice): PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Set a higher priority by decreasing the nice value (negative value increases priority)
        int ret = nice(-10);
        if (ret == -1 && errno != 0) {
            perror("nice failed");
            exit(EXIT_FAILURE);
        }

        printf("Child process (after nice): New nice value = %d\n", ret);

        // Simulate work in the child process
        for (int i = 0; i < 5; i++) {
            printf("Child process working... (iteration %d)\n", i+1);
            sleep(1);
        }

        exit(EXIT_SUCCESS);
    } 
    else {
        // Inside the parent process
        printf("Parent process: PID = %d\n", getpid());

        // Wait for the child process to complete
        wait(NULL);

        printf("Parent process: Child process finished.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Make the child process sleep for 5 seconds
        // During this time, the parent process will terminate
        sleep(5);

        // After the sleep, the child becomes an orphan and is adopted by init/systemd
        printf("Child process (Orphan): PID = %d, New Parent PID = %d\n", getpid(), getppid());

        // Continue execution
        printf("Child process (Orphan) is still running...\n");

        exit(EXIT_SUCCESS);
    } 
    else {
        // Inside the parent process
        printf("Parent process: PID = %d\n", getpid());

        // Parent process terminates immediately, making the child an orphan
        printf("Parent process is terminating...\n");
        exit(0);
    }

    return 0;
}

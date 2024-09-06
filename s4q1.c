#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    
    // Create a child process
    pid = fork();
    
    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // Inside child process
        // Make the child sleep so that the parent can terminate before the child
        sleep(5);
        printf("Child process (Orphan) PID: %d, Parent PID: %d\n", getpid(), getppid());
        
        // Child continues executing and terminates
        printf("Child process (Orphan) is still running after parent has terminated.\n");
    } 
    else {
        // Inside parent process
        printf("Parent process PID: %d\n", getpid());
        
        // Parent process terminates immediately
        printf("Parent process is terminating...\n");
        exit(0);
    }
    
    return 0;
}

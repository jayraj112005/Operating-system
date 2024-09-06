#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

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
        printf("Child process before nice(), PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));

        // Increase priority by decreasing nice value (setting it to a more negative value)
        int ret = nice(-5); // Higher priority
        if (ret == -1 && errno != 0) {
            perror("nice");
            exit(EXIT_FAILURE);
        }
        
        printf("Child process after nice(), PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));
        
        // Simulate work in the child process
        for (int i = 0; i < 5; i++) {
            printf("Child process working...\n");
            sleep(1);
        }
        
        exit(EXIT_SUCCESS);
    } 
    else {
        // Inside parent process
        printf("Parent process, PID: %d, Priority: %d\n", getpid(), getpriority(PRIO_PROCESS, 0));
        
        // Wait for the child process to complete
        wait(NULL);
        
        printf("Child process finished. Parent process exiting.\n");
    }
    
    return 0;
}

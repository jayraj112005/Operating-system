#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        printf("Child process (PID = %d) executing 'ls' command...\n", getpid());
        
        // Use execl() to replace the current process image with "ls"
        execl("/bin/ls", "ls", NULL);
        
        // If execl() fails, this line will be executed
        perror("execl failed");
        exit(EXIT_FAILURE);
    } 
    else {
        // Inside the parent process
        printf("Parent process (PID = %d) is going to sleep...\n", getpid());
        
        // Make the parent process sleep for 10 seconds
        sleep(10);
        
        printf("Parent process woke up.\n");
        
        // Optionally wait for the child process to complete
        wait(NULL);

        printf("Parent process: Child process has finished.\n");
    }

    return 0;
}

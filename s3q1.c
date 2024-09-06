#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        printf("Child process started with PID: %d\n", getpid());
        
        // Replace the current process image with a new one using exec()
        // execl() runs the "ls" command (list directory contents)
        execl("/bin/ls", "ls", NULL);
        
        // If execl() fails, the following line will be executed
        perror("execl failed");
        exit(EXIT_FAILURE);
    } 
    else {
        // Inside parent process
        printf("Parent process PID: %d\n", getpid());
        
        // Wait for the child process to complete
        wait(NULL);
        
        printf("Child process terminated. Control returned to parent process.\n");
    }
    
    return 0;
}

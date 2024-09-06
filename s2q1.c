#include <stdio.h>
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
        return 1;
    } 
    else if (pid == 0) {
        // Inside child process
        printf("Child process: Hello World!\n");
        printf("Child process ID: %d\n", getpid());
    } 
    else {
        // Inside parent process
        printf("Parent process: Hi!\n");
        printf("Parent process ID: %d\n", getpid());
        
        // Wait for the child process to complete
        wait(NULL);
    }
    
    return 0;
}

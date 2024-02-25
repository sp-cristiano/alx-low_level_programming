#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char *prompt = "$ ";
    char *command = NULL;
    size_t command_len = 0;

    while (1) {
        write(STDOUT_FILENO, prompt, strlen(prompt));

        // Read user input using getline
        ssize_t read = getline(&command, &command_len, stdin);
        if (read == -1) {
            break; // Exit loop on EOF or error
        }

        // Remove newline character from the end
        if (command[read - 1] == '\n') {
            command[read - 1] = '\0';
        }

        // Tokenize the input to separate command and arguments
        char *token = strtok(command, " ");
        if (token == NULL) {
            // No command entered, prompt again
            continue;
        }

        // Fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            // Execute the command
            if (execlp(token, token, NULL) == -1) {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            // Wait for the child to exit
            int status;
            waitpid(pid, &status, 0);
            
            // Check if child process exited normally
            if (WIFEXITED(status)) {
                char msg[50];
                int len = snprintf(msg, sizeof(msg), "Child process exited with status %d\n", WEXITSTATUS(status));
                write(STDOUT_FILENO, msg, len);
            } else {
                write(STDOUT_FILENO, "Child process terminated abnormally\n", 35);
            }
        }
    }

    // Free memory allocated by getline
    free(command);

    return 0;
}


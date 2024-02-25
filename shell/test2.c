#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

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
        char *args[MAX_COMMAND_LENGTH];
        int arg_count = 0;
        char *token = strtok(command, " ");
        while (token != NULL && arg_count < MAX_COMMAND_LENGTH - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;  // Null-terminate the argument list

        // Fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            // Execute the command
            if (execve(args[0], args, NULL) == -1) {
                perror("execve");
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


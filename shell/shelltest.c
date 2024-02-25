#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_CMD_LEN 100
int main()
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	char *name = "#cisfun$ ";
	ssize_t read_cmd;
	char *token;
	int status;
	pid_t c_pid;
	char *args[MAX_CMD_LEN];
	int arg_count = 0;




	while(1){
		write(STDOUT_FILENO, name, strlen(name));

		//Read user input using getline
		read_cmd = getline(&cmd, &cmd_len, stdin);
		if(read_cmd == -1){
			//exit loop on EOF or error
			break;
		}
		
		// Remove newline character from the end
		if (cmd[read_cmd -1] == '\n'){
			cmd[read_cmd - 1] = '\0';
		}

		// Tokenize the input to separate command and arguments.

		while (token != NULL && arg_count < MAX_CMD_LEN - 1){
			args[arg_count++] = token;
			token = strtok(NULL, "");
		}
		args[arg_count] = NULL; // NULL-terminate the argument list

		// Fork a child process
		c_pid = fork();
		if (c_pid < 0){
			perror("Fork Error");
			exit(EXIT_FAILURE);
		}else if(c_pid == 0){
			//the child process will execute the command
			if(execve(args[0], args, NULL) == -1){
				perror("Execve Error");
				exit(EXIT_FAILURE);
			}
		}else{
			// Parent process
			// wait for the child to exit
			waitpid(c_pid, &status, 0);

			// Check if child process exited normally
			if(WIFEXITED(status)){
				char msg[80];
				int len = snprintf(msg, sizeof(msg),"Child process exited with status %d\n", WEXITSTATUS(status));
				write(STDOUT_FILENO, msg, len);
			}else{
				write(STDOUT_FILENO, "Child process terminated abnormally\n", 35);
			}
		}
	}
	// Free allocated memory
	free(cmd);
	//free(array);
	return (0);
}

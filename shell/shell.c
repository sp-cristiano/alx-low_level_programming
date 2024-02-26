#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	char *name = "#cisfun$ ";
	ssize_t read_cmd;
	char ** array;
	char *token;
	int i = 0;
	pid_t c_pid;


	while(1){
		write(STDOUT_FILENO, name, strlen(name));

		//Read user input using getline
		read_cmd = getline(&cmd, &cmd_len, stdin);
		token = strtok(cmd,"\t\n");
		array = malloc(sizeof(char *)* 1024);
		if (read_cmd == -1){
			break;
			//printf("\n%s\n",cmd);
		}
		else{
			//break;
			if (token == NULL){
				//if no command entered, prompt again.
				continue;
			}
			while(token != NULL){
				array[i] = token;
				token = strtok(NULL, "\t\n");
				i++;
			}

			array[i] = NULL;

			//Fork for child process
			c_pid = fork();

			if(c_pid < 0){
				perror("Error");
				return (1);
			}
			else if (c_pid == 0)
			{
				//child prrocess
				if(execve(array[0], array, NULL) == -1){
					perror("Error with the Execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				//parent process
				int status;
				waitpid(c_pid, &status, 0);

				//Check for wait error
				if (WIFEXITED(status)){
					printf("\nChild process %d exited with status %d\n", c_pid, WEXITSTATUS(status));
				} else{
					printf("Child process %d terminated abnormally \n",c_pid);
				}
			}
		
			i = 0;
			free(array);
		}
	}

	return (0);
}

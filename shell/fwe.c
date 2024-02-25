#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	pid_t c_pid;
	int i;
	pid_t p_pid;

	for (i=0; i<5; i++){
		c_pid = fork();

		//check for error
		if (c_pid < 0){
			perror("Error");
			return (1);
		}
		//child process
		else if (c_pid == 0) {
			char *args[] = {"ls", "-l", "/tmp", NULL};
			if(execvp("ls",args) == -1){
				perror("execvp error");
				exit(EXIT_FAILURE);
			}
		}
		else{
			// wait for the child to exit
			int status;
			waitpid(c_pid, &status, 0);

			//Check for wait error
			if (WIFEXITED(status)){
				printf("Child process %d exited with status %d\n", c_pid, WEXITSTATUS(status));
			} else{
				printf("Child process %d terminated abnormally \n",c_pid);
			}
		}
	}
	return (0);
}

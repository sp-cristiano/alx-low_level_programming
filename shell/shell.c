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

	while(1){
		write(STDOUT_FILENO, name, strlen(name));

		//Read user input using getline
		read_cmd = getline(&cmd, &cmd_len, stdin);
		if (read_cmd != -1){
			printf("%s",cmd);
		}

	}
	// Free allocated memory
	free(cmd);
	return (0);
}

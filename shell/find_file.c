#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void check_cmd(char *_cmd){
	if(access(_cmd, F_OK) == 0){
		printf("%s: FOUND THE FILE\n", _cmd);
	}else{
		printf("%s: FILE DOESN'T EXIST\n", _cmd);
	}

}

int main(void){
	char *cmd = NULL;
	size_t cmd_len = 0;
	char *name = "#cisfun$ ";
	ssize_t read_cmd;
	char *token;
	char *msg = "COMMAND DOESN'T EXIST \n";

	while(1){
		write(STDOUT_FILENO, name, strlen(name));

		//Read user input using getline function.
		read_cmd = getline(&cmd, &cmd_len, stdin);
		token = strtok(cmd, " \t\n");
		if (strcmp(token, "which") == 0){
			token = strtok(NULL, " \t\n");
			while(token){
				check_cmd(token);
				token = strtok(NULL, " \t\n");
			}
			
		}else{
			//print command doesnt exist only when the command is not "which"
			if (strcmp(token, "which") != 0){
				write(STDOUT_FILENO, msg,strlen(msg));
			}
		}
	}
	return (0);

}

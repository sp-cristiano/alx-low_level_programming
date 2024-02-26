#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

void check_cmd(char *cmd){
	if(access(cmd, F_OK) == 0){
		printf("%s: FOUND THE FILE", cmd);
	}else{
		printf("%s: FILE DOESN'T EXIST");
	}

}

int main(void){
	char *cmd = NULL;
	size_t cmd_len = 0;
	char *name = "#cisfun$ ";
	ssize_t read_cmd;
	char *token;

}

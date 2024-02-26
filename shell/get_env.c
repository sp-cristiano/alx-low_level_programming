#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void){
	char *homevalue = getenv("HOME");
	char *msg = "Environment variable not found \n";

	//Check if thee HOME environment variable exists
	if (homevalue != NULL){
		write(STDOUT_FILENO, homevalue, strlen(homevalue));
		write(STDOUT_FILENO, "\n", 2);
	}else{
		write(STDOUT_FILENO, msg, strlen(msg));
	}
	return (0);
}

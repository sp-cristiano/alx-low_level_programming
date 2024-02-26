#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Extern declaration of the global variable environ
extern char **environ;

int main(){
	// Iterate over each environment variable
	for (char **env = environ; *env != NULL; env++){
		//Calculate the lenght of the environment variable string
		int len = 0;
		while ((*env)[len] != '\0'){
			len++;
		}
		
		// Write the environment variable string to standard output
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

// External declaration of the global varibale environ.
extern char **environ;

char *_getenv(const char *name){
	char **env;
	char *env_name;
	const char *env_value;

	for(env = environ; *env != NULL; env++){
		//check if the current environment variable matches the specified name
		env_name = *env;
		env_value = *env;
		while (*env_value != '=' && *env_value != '\0'){
			env_value++;
		}

		if(*env_value == '\0'){
			continue; //Skip if the environmenet variable doesnot have e vlue
		}

		//compare the names of the environmenet variables
		if (strncmp(env_name, name, env_value - env_name) == 0 && name[env_value - env_name] == '\0'){
			// Return a pointer to the value of the environment variable
			return ((char *)(env_value + 1));
		}
	}
	// Return NULL if the environment variable is not found
	return (NULL);
}

int main(void){
	char *homevalue = _getenv("HOME");
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

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
extern char **environ;

int main(int ac, char *av[], char *env){
	char *add_env = "Address of env (main's third parameter): ";
	char *add_environ = "Address of environ (global variable): ";
	
	// Allocate memory to store the address string
	char *addr_env = malloc(sizeof(char) * 40);
	char *addr_environ = malloc(sizeof(char) * 40);

	// Check if memory allocation was successful
	if (addr_env == NULL || addr_environ == NULL) {
		perror("Momory allocation failed");
		return 1;
	}

	// Convert addresses to string representation
	sprintf(addr_env, "%p", (void *)&env);
	sprintf(addr_environ, "%p", (void *)&environ);

	write(STDOUT_FILENO, add_env, strlen(add_env));
	write(STDOUT_FILENO, addr_env, strlen(addr_env));
	write(STDOUT_FILENO, "\n", 1);
	
	write(STDOUT_FILENO, add_environ, strlen(add_environ));
	write(STDOUT_FILENO, addr_environ, strlen(addr_environ));
	write(STDOUT_FILENO, "\n", 1);

	//Free dynamically allocated memory
	free(addr_env);
	free(addr_environ);

	return (0);
}

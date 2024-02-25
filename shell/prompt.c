#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char *line = NULL;
	size_t length = 0;
	ssize_t read_input;

	printf("$ ");

	// This will read user input per line until it reaches end of file 
	while ((read_input = getline(&line, &length, stdin)) != -1){
			printf("%s", line);
			printf("$ ");
	}

	free(line);

	if(ferror(stdin)){
		perror("Error reading input");
		return -1;
	}

	printf("\n");

	return 0;

}

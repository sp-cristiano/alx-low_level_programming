#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[] = "This is an array of characters";
	char delim[] = " ";
	char *words;
	words = strtok(str,delim);

	while (words != NULL){
		printf("%s\n", words);
		words = strtok(NULL,delim);
	}

	return (0);
}

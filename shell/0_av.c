#include <stdio.h>
#include <stdlib.h>

int i;

int main(int ac, char **av)
{
	printf("\n\nThis program prints all arguments without using Argument Count [ac]\n\n");

	while(*av != NULL){
		printf("Argument Vector av[%d] =  %s\n",i, *av);
		av++;
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i = 1, j =1, sum, prev, next, k, init_sum, new_sum;

	printf("\nArgument Count [ac] is: %d\n\n", ac);

	while(i < ac){
		while(j < ac){
			printf("Argument Vector av[%d] is: %s\n", j, av[j]);
			j++;
		}
		printf("\n");
		if(i == 1){
			printf("The first numeric argument vector (av[1]) is %s\n\n",av[i]);
		}
		else{
			while(i < ac){
				prev = i - 1;
				next = prev + 1;
				if(prev == 1){
					init_sum = atoi(av[prev]) + atoi(av[next]);
					k = init_sum;
					printf("Sum of %s + %s = %d\n",av[prev], av[next], k);
				}
				else{
					new_sum = k;
					k += atoi(av[next]);
					printf("Sum of %d + %s = %d\n", new_sum, av[next], k );
				}
				printf("\n");
				i++;
			}
		}
		i++;
	}
	return (0);
}

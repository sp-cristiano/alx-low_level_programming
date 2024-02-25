#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */

int main(void){
	pid_t p_pid;

	p_pid = getppid();

	printf("Current Parent Process ID(PPID) is: %u\n", p_pid);

	return (0);
}

#include "main.h"

/**
 * set_bit - this will set the value of a bit
 * to 1 at a given index position.
 * @n: this variable holds the number to set
 * @index: this tells us the index at which
 * to set bit
 *
 * Return: this function will return 1 if success,
 * or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int setbit;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	setbit = 1 << index;
	*n = *n | setbit;
	return (1);
}

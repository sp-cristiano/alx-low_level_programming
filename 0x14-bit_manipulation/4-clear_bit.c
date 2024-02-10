#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - This function will set the value
 * of a bit to 0 at a given index
 * @n:this is the variable that holds the
 * value of the  parameter
 * @index: this will hold the index
 * Return: this function will return 1 if success,
 * or -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}


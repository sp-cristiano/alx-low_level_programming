#include "main.h"

/**
 * binary_to_uint - this function will convert a binary
 *  number to an unsigned int.
 * @b: the pointer will point to a string containing a
 * binary numbers
 *
 * Return: the return value will b an unsigned int
 * with decimal value of binary number, or will
 * return 0 if error occurs
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int num;

	num = 0;
	if (!b)
		return (0);
	for (a = 0; b[a] != '\0'; a++)
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
	}
	for (a = 0; b[a] != '\0'; a++)
	{
		num <<= 1;
		if (b[a] == '1')
			num += 1;
	}
	return (num);
}

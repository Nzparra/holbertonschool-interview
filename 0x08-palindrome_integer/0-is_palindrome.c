#include "palindrome.h"
/**
 * is_palindrome - check if a input is palindrome
 * @n: input Number
 * Return: 1 if OK else 0
 **/
int is_palindrome(unsigned long n)
{
	unsigned long i = n, j = 0;

	while (i != 0)
	{
		j = j * 10;
		j = j + (i % 10);
		i = j / 10;
	}
	if (j == n)
		return (1);
	else
		return (0);
}

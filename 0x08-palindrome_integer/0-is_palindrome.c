#include "palindrome.h"
/**
 * is_palindrome - check if a input is palindrome
 * @n: input Number
 * Return: 1 if OK else 0
 **/
int is_palindrome(unsigned long n)
{
	unsigned long temp = n, len = 1, aux;

	while (temp / 10)
	{
		temp /= 10;
		len *= 10;
	}
	aux = 0;
	temp = n;
	while (len / 10)
	{
		aux = (aux * 10) + (temp % 10);
		if (aux != (n / len))
			return (0);
		len /= 10;
		temp /= 10;
	}
	return (1);
}

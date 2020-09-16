#include "palindrome.h"
/**
 * is_palindrome - check if a input is palindrome
 * @n: input Number
 * Return: 1 if OK else 0
 **/
int is_palindrome(unsigned long n)
{
	unsigned long unit = 1, start, end, temp = n, i = 0;

	if (n < 10)
		return (1);
	while (temp > 9)
	{
		unit = unit * 10;
		temp /= 10;
		i++;
	}
	temp = 0;
	while (i > temp)
	{
		start = n / unit;
		end = n % 10;
		if (start != end)
			return (0);
		i--;
		temp++;
		n = (n % unit) / 10;
		unit /= 10;
	}
	return (1);
}

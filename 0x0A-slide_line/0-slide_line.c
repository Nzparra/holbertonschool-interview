#include "slide_line.h"
/**
 * moves - move the numbers to the specified direction
 * @line: array to order
 * @size: size
 * @direction: direction
 * Return: null
 */
void moves(int *line, size_t size, int direction)
{
	int i, j;


	if (direction == 3)
	{
		for (i = 0; i < (int)size; i++)
		{
			if (line[i] != 0 && i != 0)
			{
				for (j = i; j > 0; j--)
				{
					if (line[j] != 0 && line[j - 1] == 0)
					{
						line[j - 1] = line[j];
						line[j] = 0;
					}
				}
			}
		}
	}
	else if (direction == 5)
	{
		for (i = ((int)size - 1); i >= 0; i--)
		{
			if (line[i] != 0 && i != ((int)size - 1))
			{
				for (j = i; j < (int)size - 1; j++)
				{
					if (line[j] != 0 && line[j + 1] == 0)
					{
						line[j + 1] = line[j];
						line[j] = 0;
					}
				}
			}
		}
	}
}

/**
 * same - is a function that add
 * @line: array
 * @size: size
 * @direction: direction
 * Return: null
 */
void same(int *line, size_t size, int direction)
{
	int i;


	if (direction == 3)
	{
		for (i = 0; i < (int)size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] += line[i + 1];
				line[i + 1] = 0;
			}
		}
	}
	else if (direction == 5)
	{
		for (i = ((int)size - 1); i > 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] += line[i - 1];
				line[i - 1] = 0;
			}
		}
	}
}
/**
 * slide_line - 2048 Game
 * @line: array
 * @size: size
 * @direction: direction
 * Return: 1 succes otherwise 0
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	moves(line, size, direction);
	same(line, size, direction);
	moves(line, size, direction);
	return (1);
}

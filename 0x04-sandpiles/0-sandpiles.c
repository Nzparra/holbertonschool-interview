#include "sandpiles.h"


/**
 * grid_print - print the sum of sandpiles
 * @grid: grids
 * Return: None
 */
static void grid_print(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_sum - sum two sandpiles
 * @grid1: sandpile
 * @grid2: sandpile
 * Return: None
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}

/**
 * new_grid - sum grid
 * @grid1: grid
 * Return: None
 */
void new_grid(int grid1[3][3])
{
	int i, j, new[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			new[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
				{
					new[i - 1][j] += 1;
				}
				if ((j - 1 >= 0) && (j - 1 < 3))
				{
					new[i][j - 1] += 1;
				}
				if ((i + 1 >= 0) && (i + 1 < 3))
				{
					new[i + 1][j] += 1;
				}
				if ((j + 1 >= 0) && (j + 1 < 3))
				{
					new[i][j + 1] += 1;
				}
			}
		}
	}
	grid_sum(grid1, new);
}

/**
 * check - check grid
 * @grid1: grid
 * Return: Status
 */
int check(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: grid
 * @grid2: grid
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);
	while (!check(grid1))
	{
		grid_print(grid1);
		new_grid(grid1);
	}
}

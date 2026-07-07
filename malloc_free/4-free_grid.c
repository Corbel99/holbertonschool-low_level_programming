#include "main.h"
#include <stdlib.h>
/**
 * free_grid - Frees a 2D grid of integers
 * @grid: Pointer to the 2D grid
 * @height: Number of rows
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
{
	free(grid[i]);
}

free(grid);
}

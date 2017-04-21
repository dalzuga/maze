#include "demo.h"

/**
 *
 *
 */
void draw_game()
{
	draw_map();
}

/**
 *
 *
 */
void draw_map()
{
	/* declarations */
	int **map;
	int rows, cols;
	/* end declarations */

	/* inits */
	map = NULL;
	rows = 4;
	cols = 4;
	/* end inits */

	map = make_map(rows, cols);
	if (map == NULL)
	{
		return;
	}

	map[1][1] = 1;
	map[1][2] = 1;
	map[2][2] = 1;

	_print_map(map, rows, cols);

	free(map);
}

/**
 * make_map - creates a map on the heap
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: pointer to map. On error, returns NULL.
 */
int **make_map(int rows, int cols)
{
	/* declarations */
	int **map;
	int i, j;
	/* end declarations */

	/* inits */
	map = NULL;
	/* end inits */

	map = malloc(sizeof(int *) * rows);
	if (map == NULL)
	{
		perror("malloc");
		return NULL;
	}

	for (i = 0; i < rows; i++)
	{
		map[i] = malloc(sizeof(int) * cols);
		if (map[i] == NULL)
		{
			perror("malloc");
			return NULL;
		}
	}

	/* initialize map */
	init_map(map, rows, cols);

	return map;
}

/**
 * init_map - initializes a map
 *
 * @map - map to initialize
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: Nothing.
 */
void init_map(int **map, int rows, int cols)
{
	int i;
	int j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			map[i][j] = 0;
		}
	}
}

/**
 * _print_map - calls print_map if debugging is on.
 * @map - map to print
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: Nothing.
 */
void _print_map(int **map, int rows, int cols)
{
	if (DEBUG)
	{
		return print_map(map, rows, cols);
	}
}


/**
 * print_map - prints a map
 * @map - map to print
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: Nothing.
 */
void print_map(int **map, int rows, int cols)
{
	int i;
	int j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}

#include "../headers/demo.h"

/**
 * make_map - creates a map on the heap
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: pointer to map. On error, returns NULL.
 */
GameMap *make_map(int rows, int cols)
{
	/* declarations */
	GameMap *map;
	int i;
	/* end declarations */

	/* inits */
	map = NULL;
	/* end inits */

	map = malloc(sizeof(GameMap));
	if (map == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	map->rows = rows;
	map->cols = cols;

	map->array = malloc(sizeof(int *) * rows);
	if (map->array == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	for (i = 0; i < rows; i++)
	{
		map->array[i] = malloc(sizeof(int) * cols);
		if (map->array[i] == NULL)
		{
			perror("malloc");
			return (NULL);
		}
	}

	/* initialize map */
	init_map(map);

	return (map);
}

/**
 * init_map - initializes a map with borders made of blocks, and free space
 * inside. '1' represents a block, '0' represents free space.
 *
 * @map - map to initialize
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: Nothing.
 */
void init_map(GameMap *map)
{
	int i;
	int j;

	for (i = 0; i < map->rows; i++)
	{
		for (j = 0; j < map->cols; j++)
		{
			/* default to 0 */
			map->array[i][j] = 0;
			/* border - left || right */
			if (j == 0 || j == map->cols - 1)
			{
				map->array[i][j] = 1;
			}
			/* border - top || bottom */
			if (i == 0 || i == map->rows - 1)
			{
				map->array[i][j] = 1;
			}
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
void _print_map(GameMap *map, GamePlayer *p)
{
	if (DEBUG)
	{
		print_map(map, p);
	}
}

/**
 * print_map - prints a map
 * @array - map array to print
 * @rows - number of rows
 * @cols - number of columns
 *
 * Return: Nothing.
 */
void print_map(GameMap *map, GamePlayer *p)
{
	int j, i;
	int Px = p->px, Py = p->py;

	for (j = 0; j < map->rows; j++)
	{
		for (i = 0; i < map->cols; i++)
		{
			if (i == Px / BLOCK_UNITS && j == Py / BLOCK_UNITS)
			{
				cprintf(31, 43, "%s", "P");
			}
			else
			{
				printf("%d", map->array[j][i]);
			}
		}
		printf("\n");
	}
}

/**
 * rcprint_map - prints a map with ray hitting wall
 * @array - map array to print
 * @rows - number of rows
 * @cols - number of columns
 * @x - x-coordinate of where ray hits
 * @y - y-coordinate of where ray hits
 *
 * Return: Nothing.
 */
void rcprint_map(GameMap *map, GamePlayer *p, int x, int y)
{
	int i, j;
	int Px = p->px, Py = p->py;

	for (i = 0; i < map->rows; i++)
	{
		for (j = 0; j < map->cols; j++)
		{
			if (i == Py / BLOCK_UNITS && j == Px / BLOCK_UNITS)
			{
				cprintf(31, 42, "%s", "P");
			}
			else if (i == x && j == y)
			{
				cprintf(31, 43, "%s", "X");
			}
			else
			{
				printf("%d", map->array[i][j]);
			}
		}
		printf("\n");
	}
}

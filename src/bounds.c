#include "../headers/demo.h"

/**
 * check_blocks - checks if (i,j) is free space or a block
 *
 * @maze: pointer to the maze struct
 * @i: horizontal coordinate
 * @j: vertical coordinate
 *
 * Return: 1 if free space, 0 otherwise.
 */
int check_blocks(MazeStruct *maze, int i, int j)
{
	if (check_map_bounds(maze, i, j))
		return (0);

	if (check_wall(maze, i, j))
	{
		return (1);
	}

	return (0);
}

/**
 * check_map_bounds - checks if (i,j) is inside the map
 *
 * @maze: pointer to the maze struct
 * @i: horizontal coordinate
 * @j: vertical coordinate
 *
 * Return: 1 if we're inside the map, 0 otherwise.
 */
int check_map_bounds(MazeStruct *maze, int i, int j)
{
	if (i <= BLOCK_UNITS || j <= BLOCK_UNITS ||
	    i+1 >= maze->map->cols * BLOCK_UNITS ||
	    j+1 >= maze->map->rows * BLOCK_UNITS)
	{
		return (1);
	}

	return (0);
}

/**
 * check_wall - checks if (i,j) is inside a wall
 *
 * @maze: pointer to the maze struct
 * @i: horizontal coordinate
 * @j: vertical coordinate
 *
 * Return: 1 if free space, 0 if there's a wall.
 */
int check_wall(MazeStruct *maze, int i, int j)
{
	/* check for a wall */
	if (maze->map->array[j/BLOCK_UNITS][i/BLOCK_UNITS] == 1
	    || maze->map->array[(j-1)/BLOCK_UNITS][i/BLOCK_UNITS] == 1
	    || maze->map->array[j/BLOCK_UNITS][(i-1)/BLOCK_UNITS] == 1
	    || maze->map->array[(j-1)/BLOCK_UNITS][(i-1)/BLOCK_UNITS] == 1)
	{
		return (0);
	}

	return (1);
}

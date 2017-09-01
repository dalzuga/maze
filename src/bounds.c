#include "../headers/demo.h"

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

int check_map_bounds(MazeStruct *maze, int i, int j)
{
	if (i <= 64 || j <= 64 ||
	    i+1 >= maze->map->cols * 64 ||
	    j+1 >= maze->map->rows * 64)
	{
		return (1);
	}

	return (0);
}

int check_wall(MazeStruct *maze, int i, int j)
{
	/* check for a wall */
	if (maze->map->array[j/64][i/64] == 1
	    || maze->map->array[(j-1)/64][i/64] == 1
	    || maze->map->array[j/64][(i-1)/64] == 1
	    || maze->map->array[(j-1)/64][(i-1)/64] == 1)
	{
		return (0);
	}

	return (1);
}

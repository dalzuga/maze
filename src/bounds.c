#include "../headers/demo.h"

int check_blocks(MazeStruct *maze, int i, int j)
{
	if (check_map_bounds(maze, i, j))
		return (0);

	/* check for a wall */
	if (maze->map->array[j/64][i/64] == 0)
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

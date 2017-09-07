#include "../headers/demo.h"

/**
 * check_hardcoded_values - check game parameters before running
 *
 * Return: 0 on success, 1 on failure.
 */
int check_hardcoded_values(void)
{
	int coord[2] = {START_X, START_Y};
	int i;

	if (X_RES <= 0 || Y_RES <= 0)
	{
		printf("Wrong resolution.\n");
		return (1);
	}

	if (FOV_ANGLE <= 0 || BLOCK_UNITS <= 0 || WALL_HEIGHT <= 0)
	{
		printf("Undefined game parameters.\n");
		return (1);
	}

	if (MAP_ROWS < 3 || MAP_COLS < 3)
	{
		printf("Insufficient map size.\n");
		return (1);
	}

	for (i = 0; i < 2; i++)
	{
		if (coord[i] < BLOCK_UNITS)
		{
			printf("Player inside border wall.\n");
			return (1);
		}
	}

	if (START_X >= BLOCK_UNITS * (MAP_COLS - 1))
	{
			printf("Player inside border wall.\n");
			return (1);
	}

	if (START_Y >= BLOCK_UNITS * (MAP_ROWS - 1))
	{
			printf("Player inside border wall.\n");
			return (1);
	}

	return (0);
}

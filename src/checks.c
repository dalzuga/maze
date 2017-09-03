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

/**
 * game_init_params - allocates and initializes a map and player. Both must be
 * freed by the user of this function.
 *
 * @map: address of map
 * @p: address of player
 *
 * Return: Nothing.
 */
void game_init_params(GameMap **map, GamePlayer **p)
{
	*map = make_map(MAP_ROWS, MAP_COLS);

	*p = malloc(sizeof(GamePlayer));
	if (*p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	(*p)->px = START_X;
	(*p)->py = START_Y;
	(*p)->theta = START_THETA % 360;

	(*p)->x = (*p)->px / BLOCK_UNITS;
	(*p)->y = (*p)->py / BLOCK_UNITS;

	/* set distance to projector plane */
	(*p)->dpp = X_RES / 2 / tan((FOV_ANGLE / 2) * M_PI / 180);
}

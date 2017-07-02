#include "../headers/demo.h"

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
	(*map)->array[1][1] = 0;
	(*map)->array[1][2] = 0;
	(*map)->array[2][2] = 0;

	*p = malloc(sizeof(GamePlayer));
	if (*p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	(*p)->px = START_X;
	(*p)->py = START_Y;
	(*p)->theta = START_THETA;

	(*p)->x = (*p)->px / BLOCK_UNITS;
	(*p)->y = (*p)->py / BLOCK_UNITS;
}

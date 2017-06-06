#include "../headers/demo.h"

/**
 * game_start - entry point for the game engine
 *
 * @instance: SDL window and renderer instance
 *
 * Return: Nothing.
 */
void game_start(SDL_Instance instance)
{
	/* declarations */
	GameMap *map;
	GamePlayer *p;
	/* end declarations */

	/* inits */
	map = NULL;
	p = NULL;
	/* end inits */

	start_position(&map, &p);
	_print_map(map, p);

	p->dpp = X_RES / 2 / tan((FOV_ANGLE / 2) * M_PI / 180);

	game_func01(instance, map, p);

	/*
	 * TODO - need to code free_map() to free the map here
	 */

	free(p);		/* frees the player */
}

/**
 * start_position - allocates a map and player. Both must be freed by the user
 * of this function.
 *
 * @map: address of map
 * @p: address of player
 *
 * Return: Nothing.
 */
void start_position(GameMap **map, GamePlayer **p)
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

	(*p)->px = 198;
	(*p)->py = 198;
	(*p)->theta = 91;

	(*p)->x = (*p)->px / BLOCK_UNITS;
	(*p)->y = (*p)->py / BLOCK_UNITS;
}

int poll_events(void)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			key = event.key;
			/* If 'ESCAPE' is pressed */
			if (key.keysym.scancode == 0x29)
				return (1);
			break;
		}
	}

	return (0);
}

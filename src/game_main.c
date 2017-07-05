#include "../headers/demo.h"

/**
 * game_main - entry point for the game engine
 *
 * @instance: SDL window and renderer instance
 *
 * Return: Nothing.
 */
void game_main(SDL_Instance instance)
{
	/* declarations */
	GameMap *map;
	GamePlayer *p;
	/* end declarations */

	/* inits */
	map = NULL;
	p = NULL;
	/* end inits */

	game_init_params(&map, &p);
	_print_map(map, p);

	game_func01(instance, map, p);

	/*
	 * TODO - need to code free_map() to free the map here
	 */

	free(p);		/* frees the player */
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

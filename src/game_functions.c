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
	int **map;
	GamePlayer *p;
	/* end declarations */

	/* inits */
	map = NULL;
	p = NULL;
	/* end inits */
	start_position(&map, &p);
	_print_map(map, 4, 4);

	while(1)
	{
		/* sleep(1); 	/\* one second *\/ */
		usleep(50000); /* 50ms */
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break; 	/* press ESC twice to exit a.out */
		/* draw_stuff(instance); */
		paint_environment(instance, map, p);
		fflush(stdout);
		SDL_RenderPresent(instance.renderer);
		(p->theta) += 5;
	}

	/*
	 * TODO - need to code free_map() to free the map here
	 */

	free(p);		/* frees the player */
}

/**
 *
 *
 */
void draw_game(SDL_Instance instance, int **map, GamePlayer *p)
{
	paint_environment(instance, map, p);
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
void start_position(int ***map, GamePlayer **p)
{
	*map = make_map(4, 4);
	(*map)[1][1] = 0;
	(*map)[1][2] = 0;
	(*map)[2][2] = 0;

	*p = malloc(sizeof(GamePlayer));
	if (*p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	(*p)->x = 2;
	(*p)->y = 1;
	(*p)->theta = 0;
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

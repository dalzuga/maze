#include "../headers/demo.h"

/**
 * game_engine - entry point for the game engine
 *
 * @instance: SDL window and renderer instance
 * @map: the current map
 * @p: the player struct
 *
 * Return: Nothing.
 */
void game_engine(MazeStruct *maze)
{
	while(1)
	{
		SDL_SetRenderDrawColor(maze->instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(maze->instance.renderer);
		if (poll_events(maze) == 1)
			break;

		/* draw_stuff(instance); */
		game_frame(maze);

		fflush(stdout);

		SDL_RenderPresent(maze->instance.renderer);
	}
}

int poll_events(MazeStruct *maze)
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

			if (keypress(maze, key) == 1)
			{
				return (1);
			}
			break;
		}
	}

	step_rwd(maze);
	keystates(maze);
	/* print_map_p(maze->map, maze->p); */
	usleep(10000);

	return (0);
}

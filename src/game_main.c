#include "../headers/demo.h"

/**
 * game_main - entry point for the game engine
 *
 * @maze: pointer to the maze struct
 *
 * Return: Nothing.
 */
void game_main(MazeStruct *maze)
{
	game_init_params(&(maze->map), &(maze->p));
	_print_map(maze->map, maze->p);

	game_engine(maze->instance, maze->map, maze->p);

	/*
	 * TODO - need to code free_map() to free the map here
	 */

	free(maze->p);		/* frees the player */
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

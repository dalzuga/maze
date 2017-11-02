#include "../headers/demo.h"

/**
 * game_engine - entry point for the game engine
 *
 * @maze: pointer to the MazeStruct
 *
 * Return: Nothing.
 */
void game_engine(MazeStruct *maze)
{
	int counter;
	struct timespec start, end, time_used;

	clock_gettime(CLOCK_MONOTONIC, &start);

	counter = 0;
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

		/*
                 * DON'T USE THIS
		 * usleep(10000);
                 */

		counter++;
		/* printf("counter: %d\n", counter); */

		clock_gettime(CLOCK_MONOTONIC, &end);
		timespec_subtract(&time_used, &start, &end);
		if (time_used.tv_sec >= 1)
		{
			printf("-----------FPS-----------\n");
			printf("fps: %.2f\n", (double)
			       counter / time_used.tv_sec);
			printf("frames: %d\n", counter);
 			printf("time: %.3fs\n", (double)
			       (time_used.tv_sec * BILLION + time_used.tv_nsec)
			       / BILLION);

			counter = 0;
			clock_gettime(CLOCK_MONOTONIC, &start);
		}
	}
}

/**
 * poll_events - check for mouse, keyboard, and window events by user
 *
 * @maze: pointer to the MazeStruct
 *
 * Return: 1 if event happened, 0 otherwise.
 */
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

	keystates(maze);
	if (DEBUG == 5)
	{
		print_map_p(maze->map, maze->p);
	}

	return (0);
}

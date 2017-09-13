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
	int counter;
	struct timespec fps_start, fps_end, time_used;

	clock_gettime(CLOCK_MONOTONIC, &(maze->time_s));

	fps_start = maze->time_s;

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

		/* usleep(10000); */

		counter++;
		/* printf("counter: %d\n", counter); */

		clock_gettime(CLOCK_MONOTONIC, &fps_end);
		timespec_subtract(&time_used, &fps_start, &fps_end);
		if (time_used.tv_sec >= 1)
		{
			printf("-----------FPS-----------\n");
			printf("fps: %d\n", fps_calc(counter, time_used));
			printf("frames: %d\n", counter);
			printf("time: %.3fs\n", (double)
			       (time_used.tv_sec * BILLION + time_used.tv_nsec)
			       / BILLION);
			counter = 0;
			clock_gettime(CLOCK_MONOTONIC, &fps_start);
		}
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

	keystates(maze);
	if (DEBUG == 5)
	{
		print_map_p(maze->map, maze->p);
	}

	return (0);
}

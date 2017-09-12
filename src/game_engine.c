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
	int t_flag, counter;
	struct timespec start, end, time_used;

	t_flag = clock_gettime(CLOCK_MONOTONIC, &start);
	if (t_flag == -1)
	{
		perror("timer not working");
	}

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

		usleep(10000);

		if (t_flag == 0)
		{
			counter++;
			/* printf("counter: %d\n", counter); */

			clock_gettime(CLOCK_MONOTONIC, &end);
			timespec_subtract(&time_used, &start, &end);
			if (time_used.tv_sec >= 1)
			{
				if (1)
				{
					printf("-----------FPS-----------\n");
					printf("fps: %.2f\n", (double)
					       counter / time_used.tv_sec);
					printf("frames: %d\n", counter);
					printf("time: %.3fs\n", (double)
					       time_used.tv_sec);
				}
				counter = 0;
				clock_gettime(CLOCK_MONOTONIC, &start);
			}
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

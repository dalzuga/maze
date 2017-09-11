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
	clock_t start, end;
	double time_used;

	t_flag = 1;
	start = clock();
	if (start == -1)
	{
		perror("timer not working");
		t_flag = 0;
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

		if (t_flag)
		{
			counter++;
			/* printf("counter: %d\n", counter); */

			end = clock();
			time_used = ((double) (end - start))
				/ CLOCKS_PER_SEC;
			if (time_used >= 1)
			{
				if (1)
				{
					printf("-----------FPS-----------\n");
					printf("fps: %.2f\n", (double)
					       counter / time_used);
					printf("frames: %d\n", counter);
					printf("time: %.3fs\n", time_used);
				}
				counter = 0;
				start = clock();
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

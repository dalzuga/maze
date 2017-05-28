#include "../headers/demo.h"

/**
 * game_func01 - entry point for the game engine
 *
 * @instance: SDL window and renderer instance
 * @map: the current map
 * @p: the player struct
 *
 * Return: Nothing.
 */
void game_func01(SDL_Instance instance, int **map, GamePlayer *p)
{
	while(1)
	{
		/* sleep(1); 	/\* one second *\/ */
		usleep(30000); /* 30ms */
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break; 	/* press ESC twice to exit a.out */

		/* draw_stuff(instance); */
		game_func02(instance, map, p);

		fflush(stdout);

		SDL_RenderPresent(instance.renderer);

		(p->theta) += 1;
		p->theta = p->theta % 360;
	}

}

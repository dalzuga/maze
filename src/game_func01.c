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
void game_func01(SDL_Instance instance, GameMap *map, GamePlayer *p)
{
	while(1)
	{
		if (DEBUG == 1)
		{
			sleep(1); /* one second */
		}
		else
		{
			usleep(FRAME_SLEEP);
		}
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break; 	/* press ESC twice to exit a.out */

		/* draw_stuff(instance); */
		game_func02(instance, map, p);

		fflush(stdout);

		SDL_RenderPresent(instance.renderer);

		p->theta += ANGLE_STEP;
		p->theta = p->theta % 360;
	}

}

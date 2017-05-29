#include "../headers/demo.h"

/**
 * game_func02 - draws the game on the projection plane (monitor)
 *
 * @instance: SDL window and renderer instance
 * @map: the current map
 * @p: the player struct
 *
 * Return: Nothing.
 */
void game_func02(SDL_Instance instance, int **map, GamePlayer *p)
{
	/* declarations */
	int i;
	double col_height;	/* column height */
	double rclen;		/* ray cast length */
	int top, bottom;

	for (i = 0; i < X_RES; i++)
	{
		rclen = calc_rclen(map, p, i);
		col_height = WALL_HEIGHT * p->dpp / rclen;
		top = Y_RES / 2 + col_height / 2;
		bottom = Y_RES / 2 - col_height / 2;

		if (DEBUG == 1)
		{
			printf("---------------4--------------\n");
			printf("col_height: %f, top: %d, bottom: %d\n",
			       col_height, top, bottom);
			printf("i: %d, X_RES: %d\n", i, X_RES);
			printf("i / X_RES: %f\n", (double) i / X_RES);
			printf("FOV_ANGLE (radians): %f\n", FOV_ANGLE);
			printf("FOV_ANGLE (degrees): %f\n",
			       FOV_ANGLE * 180 / M_PI);
			printf("------------------------------\n");
			if (poll_events() == 1)
			{
				break;
			}
			usleep(SLEEP_TIME);
		}

		SDL_RenderDrawLine(instance.renderer, i, top, i, bottom);

		if (DEBUG == 1)
		{
			SDL_RenderPresent(instance.renderer);
		}
	}
}

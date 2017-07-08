#include "../headers/demo.h"

/**
 * game_frame - draws the game on the projection plane (monitor)
 *
 * @instance: SDL window and renderer instance
 * @map: the current map
 * @p: the player struct
 *
 * Return: Nothing.
 */
void game_frame(MazeStruct *maze)
{
	GamePlayer *p = maze->p;

	/* declarations */
	int i;
	double col_height;	/* column height */
	double rclen;		/* ray cast length */
	int top, bottom;

	for (i = 0; i < X_RES; i++)
	{
		/* rclen = calc_func01(map, p, i); */

		rclen = calc_rclen(maze, i);

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
			printf("FOV_ANGLE: %d\n", FOV_ANGLE);
			printf("------------------------------\n");
		}
		if (DEBUG > 0)
		{
			if (poll_events() == 1)
			{
				exit(EXIT_FAILURE); /* press ESC to exit */
			}
			usleep(DEBUG_SLEEP);
		}

		/* game_func03(instance); */
		/* SDL_RenderDrawLine(instance.renderer, i, top, i, bottom); */

		/* if (DEBUG == 1) */
		/* { */
		/* 	SDL_RenderPresent(instance.renderer); */
		/* } */
	}
}

/**
 * axis_angle - if the angle is on an axis
 */
int axis_angle(double angle)
{
	if (angle == 0 || angle == 90 || angle == 180 || angle == 270)
	{
		return (1);
	}

	return (0);
}

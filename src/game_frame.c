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
	double adj_dist;	/* adjusted distance */
	int top, bottom;
	double beta;

	for (i = 0; i < X_RES; i++)
	{
		rclen = calc_rclen(maze, i);

		beta = (double) i / X_RES * FOV_ANGLE - FOV_ANGLE / 2;
		beta = calc_mod360(beta);
		adj_dist = rclen * cos(beta * M_PI / 180);

		col_height = WALL_HEIGHT * p->dpp / adj_dist;
		top = Y_RES / 2 + col_height / 2;
		bottom = Y_RES / 2 - col_height / 2;

		if (DEBUG == 1)
		{
			printf("---------------4--------------\n");
			printf("col_height: %f, top: %d, bottom: %d\n",
			       col_height, top, bottom);
			printf("i: %d, X_RES: %d\n", i, X_RES);
			printf("i / X_RES: %f\n", (double) i / X_RES);
			printf("FOV_ANGLE: %d\t\t", FOV_ANGLE);
			printf("p->theta: %d\n", p->theta);
			printf("------------------------------\n");
		}
		if (DEBUG > 0)
		{
			if (poll_events(maze) == 1)
			{
				exit(EXIT_FAILURE); /* press ESC to exit */
			}
		}

		SDL_RenderDrawLine(maze->instance.renderer, i, top, i, bottom);

		if (DEBUG >= 1)
		{
			SDL_RenderPresent(maze->instance.renderer);
		}
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

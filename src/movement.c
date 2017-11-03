#include "../headers/demo.h"

/**
 * step_up - moves player north, ignores walls
 * @maze: the maze struct
 */
void step_up(MazeStruct *maze)
{
	(maze->p->py) -= STEP_FACTOR;
}

/**
 * step_down - moves player south, ignores walls
 * @maze: the maze struct
 */
void step_down(MazeStruct *maze)
{
	(maze->p->py) += STEP_FACTOR;
}

/**
 * step_left - moves player west, ignores walls
 * @maze: the maze struct
 */
void step_left(MazeStruct *maze)
{
	(maze->p->px) -= STEP_FACTOR;
}

/**
 * step_right - moves player east, ignores walls
 * @maze: the maze struct
 */
void step_right(MazeStruct *maze)
{
	(maze->p->px) += STEP_FACTOR;
}

/**
 * step_fwd - moves the player forward
 * @maze: the maze struct
 */
void step_fwd(MazeStruct *maze)
{
	int dx;
	int dy;
	double tc;

	int i, j;

	tc = (double) maze->p->theta + FOV_ANGLE / 2;
	tc = calc_mod360(tc);

	dx = STEP_FACTOR * sin(tc * M_PI / 180);
	dy = -( STEP_FACTOR * cos(tc * M_PI / 180) );

	if (DEBUG >= 1)
	{
		printf("sin(tc * M_PI / 180): %f\t", sin(tc * M_PI / 180));
		printf("cos(tc * M_PI / 180): %f\n", cos(tc * M_PI / 180));
		printf("\t\t\t\t\t\ttc: %f\n", tc);

		printf("dx: %d\t\t", dx);
		printf("dy: %d\n", dy);
	}

	i = maze->p->px + dx;
	j = maze->p->py + dy;

	if (check_blocks(maze, i, j))
	{
		maze->p->px = i;
		maze->p->py = j;
	}
	else if (check_blocks(maze, i - dx, j))
	{
		maze->p->py = j;
	}
	else if (check_blocks(maze, i, j - dy))
	{
		maze->p->px = i;
	}
}

/**
 * step_rwd - moves the player backwards
 * @maze: the maze struct
 */
void step_rwd(MazeStruct *maze __attribute__((unused)))
{
	int dx;
	int dy;
	double tc;

	int i, j;

	tc = (double) maze->p->theta + FOV_ANGLE / 2;
	tc = calc_mod360(tc);

	dx = STEP_FACTOR * sin(tc * M_PI / 180);
	dy = -( STEP_FACTOR * cos(tc * M_PI / 180) );

	if (DEBUG >= 1)
	{
		printf("sin(tc * M_PI / 180): %f\t", sin(tc * M_PI / 180));
		printf("cos(tc * M_PI / 180): %f\n", cos(tc * M_PI / 180));
		printf("\t\t\t\t\t\ttc: %f\n", tc);

		printf("dx: %d\t\t", dx);
		printf("dy: %d\n", dy);
	}

	i = maze->p->px - dx;
	j = maze->p->py - dy;

	if (check_blocks(maze, i, j))
	{
		maze->p->px = i;
		maze->p->py = j;
	}
	else if (check_blocks(maze, i + dx, j))
	{
		maze->p->py = j;
	}
	else if (check_blocks(maze, i, j + dy))
	{
		maze->p->px = i;
	}
}

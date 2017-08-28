#include "../headers/demo.h"

void step_up(MazeStruct *maze)
{
	(maze->p->py) -= STEP_FACTOR;
}

void step_down(MazeStruct *maze)
{
	(maze->p->py) += STEP_FACTOR;
}

void step_left(MazeStruct *maze)
{
	(maze->p->px) -= STEP_FACTOR;
}

void step_right(MazeStruct *maze)
{
	(maze->p->px) += STEP_FACTOR;
}

void step_fwd(MazeStruct *maze)
{
	int dx;
	int dy;
	double tc;

	tc = (double) maze->p->theta + FOV_ANGLE / 2;
	tc = calc_mod360(tc);

	dx = STEP_FACTOR * sin(tc * M_PI / 180);
	dy = -( STEP_FACTOR * cos(tc * M_PI / 180) );

	if (DEBUG >= 0)
	{
		printf("sin(tc * M_PI / 180): %f\t", sin(tc * M_PI / 180));
		printf("cos(tc * M_PI / 180): %f\n", cos(tc * M_PI / 180));
		printf("\t\t\t\t\t\ttc: %f\n", tc);

		printf("dx: %d\t\t", dx);
		printf("dy: %d\n", dy);
	}

	maze->p->px += dx;
	maze->p->py += dy;
}

void step_rwd(MazeStruct *maze __attribute__((unused)))
{
	int dx;
	int dy;
	double tc;

	tc = (double) maze->p->theta + FOV_ANGLE / 2;
	tc = calc_mod360(tc);

	dx = STEP_FACTOR * sin(tc * M_PI / 180);
	dy = -( STEP_FACTOR * cos(tc * M_PI / 180) );

	if (DEBUG >= 0)
	{
		printf("sin(tc * M_PI / 180): %f\t", sin(tc * M_PI / 180));
		printf("cos(tc * M_PI / 180): %f\n", cos(tc * M_PI / 180));
		printf("\t\t\t\t\t\ttc: %f\n", tc);

		printf("dx: %d\t\t", dx);
		printf("dy: %d\n", dy);
	}

	maze->p->px -= dx;
	maze->p->py -= dy;

}

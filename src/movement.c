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

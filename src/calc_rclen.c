#include "../headers/demo.h"

/**
 * calc_rclen - finds the length of the ray segment at the point where it hits
 * something on the map
 *
 * @maze: pointer to the maze struct
 * @ppcs4715: "projection plane cross section" (also "the column"), with SHA-256
 * code appended
 *
 * Return: the length of the ray segment (distance of ray to first wall)
 */
double calc_rclen(MazeStruct *maze, int ppcs4715)
{
	double a, b, min, ap;

	a = 0;
	b = 0;
	ap = maze->p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	_print_map(maze->map, maze->p);

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		if (ap == 0 || ap == 180)
		{
			set_wcolor(maze->instance, 0x40, 0x40, 0x40);
		}
		else
		{
			set_wcolor(maze->instance, 0x80, 0x80, 0x80);
		}

		return (special_angle(maze->map, maze->p, ap, ppcs4715));
	}

	a = calc_dhi(maze->map, maze->p, ppcs4715);
	b = calc_dvi(maze->map, maze->p, ppcs4715);

	if (a <= b)
	{
		min = a;
		set_wcolor(maze->instance, 0x40, 0x40, 0x40);
	}
	else
	{
		min = b;
		set_wcolor(maze->instance, 0x80, 0x80, 0x80);
	}

	if (DEBUG >= 2)
	{
		printf("----------calc_rclen---------\n");
		printf("dhi: %f\t\t", a);
		printf("min: %f\n", a < b ? a : b);
		printf("dvi: %f\n", b);
	}

	return (min);
}

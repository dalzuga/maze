#include "../headers/demo.h"

/**
 * calc_rclen - finds the length of the ray segment at the point where it hits
 * something on the map
 *
 * @maze: pointer to the maze struct
 * @ppcs4715: "projection plane cross section" (also "the column"), with SHA-256
 */
double calc_rclen(MazeStruct *maze, int ppcs4715)
{
	int a, b, min;

	a = 0;
	b = 0;

	_print_map(maze->map, maze->p);

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
		printf("dhi: %d\t\t", a);
		printf("min: %d\n", a < b ? a : b);
		printf("dvi: %d\n", b);
	}

	return (min);
}

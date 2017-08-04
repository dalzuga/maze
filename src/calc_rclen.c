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
	int a, b;

	print_map(maze->map, maze->p);

	a = _calc_dhi(maze->map, maze->p, ppcs4715);

	b = _calc_dvi(maze->map, maze->p, ppcs4715);

	if (DEBUG >= 2)
	{
		printf("-------------12-1-------------\n");
		printf("dist_dhi: %d\n", a);
		printf("dist_dvi: %d\n", b);

		printf("min dist: %d\n", a < b ? a : b);
	}


	return (a < b ? a : b);
}

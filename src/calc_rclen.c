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
	double rclen;

	rclen = -98;

	_print_map(maze->map, maze->p);

	rclen = calc_dhi(maze->map, maze->p, ppcs4715);

	/* rclen = _calc_dvi(maze->map, maze->p, ppcs4715); */

	return (rclen);
}

#include "../headers/demo.h"

/**
 * calculate_dslice - calculate distance to wall slice
 *
 *
 */
int calculate_dslice(int **map __attribute__ ((unused)),
		     GamePlayer *p __attribute__((unused)), int beta)
{
	int dslice = 98;

	if (DEBUG % 2 == 0)
	{
		printf("angle beta: %d, dslice: %d\n", beta, dslice);
	}

	/*
	 * code to calculate dslice
	 */

	return (dslice);
}

#include "../headers/demo.h"

/**
 * calculate_dslice - calculate distance to wall slice
 *
 *
 */
int calculate_dslice(int **map __attribute__ ((unused)),
		     GamePlayer __attribute__ ((unused)) *p,
		     int i,
		     int *px __attribute__((unused)),
		     int *py __attribute__((unused)))
{
	/* declarations + inits */
	int dslice = 98;
	int alpha __attribute__((unused)) = 0;

	if (DEBUG == 1)
	{
		printf("angle beta: %f, dslice: %d\n",
		       (double) i / (double) X_RES, dslice);
	}

	/*
	 * code to calculate dslice
	 */

	/* calculate_angle(map, p, i); */

	/*
	 * end code to calculate dslice
	 */


	return (dslice);
}

/**
 *
 *
 */


/**
 * calculate_pposition - calculates player position in the center of the
 * player's block. This is necessary because we are using finer resolution to
 * position player inside the block itself.
 *
 *
 */
int calculate_pposition(int **map __attribute__ ((unused)),
			GamePlayer *p __attribute__((unused)), int *px, int *py)
{
	*px = (p->x + 1) * SQRT_BLOCK_UNITS - SQRT_BLOCK_UNITS_HALF;
	*py = (p->y + 1) * SQRT_BLOCK_UNITS - SQRT_BLOCK_UNITS_HALF;

	if (DEBUG == 1)
	{
		printf("p->x: %d, px: %d, ", p->x, *px);
		printf("p->y: %d, py: %d\n", p->y, *py);
	}

	return (0);
}

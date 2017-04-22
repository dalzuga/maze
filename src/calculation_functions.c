#include "../headers/demo.h"

/**
 * calculate_dslice - calculate distance to wall slice
 *
 *
 */
int calculate_dslice(int **map __attribute__ ((unused)),
		     GamePlayer __attribute__ ((unused)) *p,
		     int beta,
		     int *px __attribute__((unused)),
		     int *py __attribute__((unused)))
{
	/* declarations + inits */
	int dslice = 98;
	int alpha __attribute__((unused)) = 0;

	if (DEBUG % 2 == 0)
	{
		printf("angle beta: %d, dslice: %d\n", beta, dslice);
	}

	/*
	 * code to calculate dslice
	 */

	return (dslice);
}

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
	*px = p->x * SQRT_BLOCK_UNITS;
	*py = p->y * SQRT_BLOCK_UNITS;

	if (DEBUG == 1)
	{
		printf("p->x: %d, px: %d, ", p->x, *px);
		printf("p->y: %d, py: %d\n", p->y, *py);
	}

	return (0);
}

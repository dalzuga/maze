#include "../headers/demo.h"

/**
 * calculate_dslice - calculate distance to wall slice
 *
 *
 */
double calculate_dslice(int **map __attribute__ ((unused)),
		     GamePlayer __attribute__ ((unused)) *p,
		     int i,
		     int *px __attribute__((unused)),
		     int *py __attribute__((unused)))
{
	/* declarations + inits */
	double d_slice = 98;
	double beta = (double) FOV_ANGLE * i / (double) X_RES;
	double alpha __attribute__((unused)) = 0;
	double theta = p->theta - FOV_ANGLE / 2;
	double precompute[1] = { 0 };

	/* cos(theta + beta), as radians */
	precompute[0] = cos((theta + beta) * M_PI / 180);

	/*
	 * code to calculate dslice
	 */

	d_slice = (*py) / precompute[0];

	/*
	 * end code to calculate dslice
	 */

	if (DEBUG == 1)
	{
		printf("---------------3--------------\n");
		printf("player position on map: (%d, %d), absolute: (%d, %d)\n",
		       p->x, p->y, *px, *py);

		printf("cos((theta + beta) * M_PI / 180): %f\n", precompute[0]);
		printf("theta + beta: %f, cos(theta + beta): %f, d_slice: %f\n",
		       theta + beta, precompute[0], d_slice);
	}


	return (d_slice);
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
		printf("---------------2--------------\n");
		printf("p->x: %d, px: %d, ", p->x, *px);
		printf("p->y: %d, py: %d\n", p->y, *py);
	}

	return (0);
}

/**
 * paint_calculations - gets necessary calculations
 *
 *
 */
void paint_calculations(int **map __attribute__((unused)), GamePlayer *p)
{
	int start_angle, end_angle;
	int alpha;		/* alpha is the angle of the ray being cast */

	start_angle = p->theta - FOV_ANGLE / 2;
	end_angle = p->theta + FOV_ANGLE / 2;
	alpha = 90 - start_angle;

	if (DEBUG == 2)
	{
		printf("start angle: %d, end angle: %d, alpha: %d, cos(alpha): \
%d\n", start_angle, end_angle, alpha, (int) round(cos(alpha)));
	}
}

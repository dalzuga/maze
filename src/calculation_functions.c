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
	double dist_v = 0, dist_h = 0;

	if ((theta + beta) >= 90) /* tag: optimization1 */
	{
		return (0);
	}

	/*
	 * code to calculate dslice
	 */

	dist_v = vertical_intersects(map, p, beta, px, py);
	dist_h = horizontal_intersects(map, p, beta, px, py);

	if (dist_v <= dist_h)
	{
		d_slice = (*py) / dist_v;
	}
	else
	{
		d_slice = (*px) / dist_h;
	}

	printf("d_slice: %f\n", d_slice);

	/* d_slice = (*py) / (cos((theta + beta) * M_PI / 180)); */

	/*
	 * end code to calculate dslice
	 */

	if (DEBUG == 1)
	{
		printf("---------------3--------------\n");
		printf("player position on map: (%d, %d), absolute: (%d, %d), \
p->theta: %d\n", p->x, p->y, *px, *py, p->theta);

		printf("cos((theta + beta) * M_PI / 180): %f\n",
		       cos((theta + beta) * M_PI / 180));
		printf("theta + beta: %f, cos(theta + beta): %f, d_slice: %f\n",
		       theta + beta, cos((theta + beta) * M_PI / 180), d_slice);
		printf("beta - FOV_ANGLE / 2: %f\n", beta - FOV_ANGLE / 2);
	}

	/* correct for spherical distortion */
	d_slice = d_slice * cos((beta - FOV_ANGLE / 2) * M_PI / 180);

	return (d_slice);
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
 * calculate_block - inverse of calculate_pposition
 *
 *
 */
void calculate_block(int px, int py)
{
	int map_x = 0, map_y = 0;

	map_x = px / SQRT_BLOCK_UNITS;
	map_y = py / SQRT_BLOCK_UNITS;

	if (DEBUG == 2)
	{
		printf("---------------5--------------\n");
		printf("map_x: %d\n", map_x);
		printf("map_y: %d\n", map_y);
		exit(EXIT_FAILURE);
	}
}

/**
 * paint_calculations - gets necessary calculations
 *
 *
 */
void print_calculations(int **map __attribute__((unused)), GamePlayer *p)
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

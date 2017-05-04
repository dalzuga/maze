#include "../headers/demo.h"

/**
 * vertical_intersects - finds the closest vertical wall hit by the ray
 *
 */
double vertical_intersects(int ***map, GamePlayer **p, double beta, int *px,
			   int *py)
{
	if (DEBUG == 2)
	{
		printf("---------------2--1--------------\n");
		printf("%p\n", (void *) map);
		printf("%p\n", (void *) p);
		printf("%p\n", (void *) &beta);
		printf("%p\n", (void *) px);
		printf("%p\n", (void *) py);
	}

	calculate_block(*px, *py);

	return (0);
}

/**
 * horizontal_intersects - finds the closest horizontal wall hit by the ray
 *
 */
double horizontal_intersects(int ***map, GamePlayer **p, int *px, int *py)
{

	return (0)
}

/**
 *
 *
 */
int get_pix(int **map, int px, int py)
{

}

/**
 *
 *
 */
int get_piy(int **map, int px, int py)
{

}

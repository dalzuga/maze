#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (x == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map __attribute__ ((unused)),
		GamePlayer *p, int i)
{
	/* declarations */
	double ap;
	int dy, Py, Ay;

	/* inits */
	ap = p->theta + (double) i / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	Py = p->py;
	dy = (64) * (Py/64) - Py - 1;
	Ay = Py + dy;

	printf("Ay: %d\n", Ay);

	return (ap);
}

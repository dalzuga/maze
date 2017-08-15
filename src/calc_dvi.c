#include "../headers/demo.h"

/**
 * calc_dvi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	/* declarations */
	double ap;
	int dx;
	int Px, Py, c, i, j;
	int Xa;
	int flag;
	int dist;

	/* inits */
	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);
	Py = p->py;
	Px = p->px;
	flag = 0;
	dist = 0;
	/* end inits */

	if (axis_angle(ap))	/* special cases: 0, 90, 180, 270 */
	{
		return (special_dhi(map, p, ap, ppcs4715));
	}

	dx = calc_dx(p, ap);
	Xa = calc_Xa(ap);

	i = Px + dx;

	if (DEBUG >= 2)
	{
		printf("-------------11-1-------------\n");
		printf("(i, j): (%d, %d)\t\t", i, j);
		printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
		printf("player_pos: (%d, %d)\t\t", Px, Py);
		printf("player_pos: [%d, %d]\t\t", Px/64, Py/64);
		printf("ap: %f\n", ap);
		printf("c: %d\t\t", c);
		printf("ppcs4715: %d\n", ppcs4715);
		printf("Ya: %d\t\t", Ya);
		printf("Xa: %d\n", Xa);
	}

	return (ap);
}

/**
 * _calc_dvi - debug wrapper to call calc_dvi
 *
 */
double _calc_dvi(GameMap *map, GamePlayer *p, int ppcs4715)
{
	return (calc_dvi(map, p, ppcs4715));
}

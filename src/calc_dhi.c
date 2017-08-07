#include "../headers/demo.h"

/**
 * calc_dhi - finds the closest horizontal wall (y == C) hit by the ray
 *
 */
double calc_dhi(GameMap *map __attribute__ ((unused)), GamePlayer *p, int ppcs4715)
{
	/* 
         * /\* declarations *\/
	 * double ap;
	 * int dy;
	 * int Px, Py, Ya, Xa, c, i, j;
	 * 
	 * /\* inits *\/
	 * ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	 * ap = calc_mod360(ap);
	 * 
	 * if (axis_angle(ap))	/\* special cases: 0, 90, 180, 270 *\/
	 * {
	 * 	return (special_dhi(map, p, ap, ppcs4715));
	 * }
	 * 
	 * Py = p->py;
	 * Px = p->px;
	 * /\* end inits *\/
         */

	int dy;
	double ap;

	ap = p->theta + (double) ppcs4715 / X_RES * FOV_ANGLE;
	ap = calc_mod360(ap);

	dy = calc_dy(p, ap);

	/* 
         * if (DEBUG >= 2)
	 * {
	 * 	printf("----------11-1-SPECIAL--------\n");
	 * 	printf("(i, j): (%d, %d)\t\t", i, j);
	 * 	printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
	 * 	printf("player_pos: (%d, %d)\t\t", Px, Py);
	 * 	printf("player_pos: [%d, %d]\t\t", Px/64, Py/64);
	 * 	/\* 
         *          * printf("(i, j): (%d, %d)\t\t", i, j);
	 * 	 * printf("(i/64, j/64): (%d, %d)\n", i/64, j/64);
	 * 	 * printf("player_pos: (%d, %d)\t\t", Px, Py);
         *          *\/
	 * 	printf("ap: %f\n", angle);
	 * 	printf("c: %d\t\t", c);
	 * 	printf("ppcs4715: %d\n", ppcs4715);
	 * 	printf("dist: %d\n", dist);
	 * 	print_map(map, p);
	 * 	rcprint_map(map, p, j/64, i/64);
	 * }
	 * 
	 * return (dist);
         */

	return (dy);
}

int calc_dy(GamePlayer *p, double ap)
{
	int dy;
	int Py;

	Py = p->py;

	if (ap < 90 || ap > 270) /* up */
	{
		dy = Py - Py/64 * 64;
	}
	else 			/* down */
	{
		dy = (Py/64 + 1) * 64 - Py;
	}

	return (dy);
}

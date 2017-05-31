#include "../headers/demo.h"

/**
 * calc_quadrants - calculates alpha based on quadrant
 *
 */
double calc_quadrants(double beta, double theta)
{
	/* declaration */
	double tplusb = calc_quadrants_helper(beta, theta);

	return (alpha);
}

/**
 * calc_quadrants01 - helper for calc_quadrants()
 *
 */
double calc_quadrants_helper(double tplusb)
{
	while (tplusb <= -180)
	{
		tplusb += 360;
	}

	while (tplusb >= 180)
	{
		tplusb -= 360;
	}

	return (tplusb);
}

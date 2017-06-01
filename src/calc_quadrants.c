#include "../headers/demo.h"

/**
 * calc_quadrants - calculates alpha based on quadrant
 *
 */
double calc_quadrants(double beta, double theta)
{
	/* declaration */
	double tplusb = calc_quad01(beta + theta);

	if (tplusb > 0 && tplusb < 90) /* quadrant I */
	{
		return (90 - tplusb);
	}
	else if (tplusb > 90 && tplusb < 180) /* quadrant II */
	{
		return (tplusb - 90);
	}
	else if (tplusb < -90) /* quadrant III */
	{
		return ((-1) * (tplusb + 90));
	}
	else if (tplusb < 0 && tplusb > -90) /* quadrant IV */
	{
		return (tplusb + 90);
	}

	return (0); 		/* alpha is 0 if we're on an axis */
}

/**
 * calc_quad01 - special modding function, guarantees range (-180, 180]
 *
 */
double calc_quad01(double tplusb)
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

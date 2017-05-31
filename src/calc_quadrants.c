#include "../headers/demo.h"

/**
 * calc_quadrants - calculates alpha based on quadrant
 *
 */
double calc_quadrants(double beta, double theta)
{
	/* declaration */
	double tplusb = calc_quad01(beta, theta);

	if (tplusb > 0 && tplusb < 90) /* quadrant I */
	{
		return (tplusb);
	}
	else if (tplusb > 90 && tplusb < 180) /* quadrant II */
	{

	}
	else if (tplusb < -90) /* quadrant III */
	{

	}
	else if (tplusb < 0 && tplusb > -90) /* quadrant IV */
	{

	}
	else			/* we're on an axis */
	{
		return (0);
	}

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

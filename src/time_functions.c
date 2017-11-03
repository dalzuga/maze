#include "../headers/demo.h"

/**
 * timespec_subtract - subtracts time between two time points
 *
 * @result: address to store the result in
 * @start: address of the first time point
 * @end: address of the second time point
 *
 * Return: 1 if the second time point occurs before the first time point.
 */
int timespec_subtract(struct timespec *result, struct timespec *start, \
		      struct timespec *end)
{
	/* subtract seconds */
	result->tv_sec = end->tv_sec - start->tv_sec;

	/* subtract nanoseconds */
	result->tv_nsec = end->tv_nsec - start->tv_nsec;

	/* fix remainder */
	if (result->tv_nsec < 0)
	{
		result->tv_sec--;
		result->tv_nsec += BILLION;
	}

	return (end->tv_sec < start->tv_sec);
}

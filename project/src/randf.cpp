#include "randf.h"

float Mathf::randf()
{
	return ((float) rand()) / RAND_MAX;
}


float Mathf::randf(float max)
{
	if(max == 0)
		max = .000001;
	return ((float) rand()) / (RAND_MAX /  max);
}


float Mathf::randf(float min, float max)
{
	if(max - min == 0)
		max += .000001;
	else if (min > max)
	{
		int temp = max;
		max = min;
		min = max;
	}

	return min + ((float) rand()) / (RAND_MAX /  (max - min));
}

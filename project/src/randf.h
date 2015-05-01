#pragma once
#include <stdlib.h>

namespace Mathf
{
	/*! Return a random float value
		\return A random float value (float)
	*/
	float randf();
	/*! Return a random float value less than the maximum
		\param max the maximum value (float)
		\return A random float value (float)
	*/
	float randf(float max);
	/*! Return a random float value within the specified range
		\param min the minimum value (float)
		\param max the maxium value (float)
		\return A random float value (float)
	*/
	float randf(float min, float max);
}

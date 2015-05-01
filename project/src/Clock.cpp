#include "Clock.h"

Clock& Clock::getInstance()
{
	static Clock instance;
	return instance;
}


void Clock::update()
{
	//Update the clock's time
	deltaTime = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - currentTime;
	currentTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
}

/*! Get the time between frames
\return delta time as seconds in a float
*/
float Clock::getDeltaTime()
{
	// Get the time between frames
	return deltaTime;
}

/*! Get the time since the program began
\return time as seconds in a float
*/
float Clock::getCurrentTime()
{
	// Get the time since the program began
	return currentTime;
}

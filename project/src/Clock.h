#pragma once
#include <GL/glui.h>

/*! This class holds information about the time of the program */
class Clock
{
private:
	float currentTime;
	float deltaTime;
public:

	/*! Get the Clock instance
		\return the instance of Clock
	*/
	static Clock& getInstance();

	/*! Update the clock's time
	*/
	void update();

	/*! Get the time between frames
		\return delta time as seconds in a float
	*/
	float getDeltaTime();

	/*! Get the time since the program began
		\return time as seconds in a float
	*/
	float getCurrentTime();
private:
	Clock(): currentTime(glutGet(GLUT_ELAPSED_TIME) / 1000.0){}
};

/*!
*
* \brief Main application class for the robot simulation
* \author CSci3081 Guru
*/


#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>

#include "BaseGfxApp.h"

/*! The Simulation class.  This sets up the GUI and the drawing environment. */
class Simulation : public BaseGfxApp {

public:

	enum UIControlType {
		UI_QUIT = 0,
		UI_START = 1,
		UI_PAUSE = 2,
		UI_RESUME = 3,
		UI_LIGHTS_MORE = 4,
		UI_LIGHTS_LESS = 5
	};

	Simulation(int argc, char* argv[], int width, int height);
	virtual ~Simulation();

	void gluiControl(int controlID);
	void leftMouseDown(int x, int y);
	void leftMouseUp(int x, int y);
	void keyboard(unsigned char c, int x, int y);
	void keyboardUp(unsigned char c, int x, int y);

	void display();
	void update();
};

#endif
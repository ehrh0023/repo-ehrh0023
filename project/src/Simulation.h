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
	UI_RESUME = 3
    };

    Simulation(int argc, char* argv[], int width, int height);
    virtual ~Simulation();

	void update();
	void display();    
	void gluiControl(int controlID);
	void leftMouseDown(int x, int y);
	void leftMouseUp(int x, int y);

	/*! Starts the simulation */
	void start(int);
	/*! Pauses the simulation */
	void pause(int);
	/*! Resumes the simulation */
	void resume(int);
	/*! Quits the simulation */
	void quit(int);

private:
	/*! Spawns the entities in the simulation*/
	void spawnEntities();
};


#endif

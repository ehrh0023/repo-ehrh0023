#include "Simulation.h"
#include "Entity/RobotClass.h"
#include "Entity/Obstacle.h"
#include "Entity/Target.h"
#include "Entity/EntityManager.h"
#include "Clock.h"
#include <time.h>
#include <iostream>
#include "randf.h"

bool paused = false;

Simulation::Simulation(int argc, char* argv[], int width, int height) 
	: BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH, true, 851, 50)
{
	setCaption("Robot Simulation");

    //creates a basic UI panel with quit button
	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Control Panel");
    new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)exit);
#ifndef WIN32
    new GLUI_Button(m_glui, "Start", UI_START, (GLUI_Update_CB)&Simulation::start);
    new GLUI_Button(m_glui, "Pause", UI_PAUSE, (GLUI_Update_CB)&Simulation::pause);
    new GLUI_Button(m_glui, "Resume", UI_RESUME, (GLUI_Update_CB)&Simulation::resume);
#endif

    // Initialize OpenGL
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    gluOrtho2D(0, m_width, 0, m_height);
    glViewport(0, 0, m_width, m_height);

	srand(time(NULL));

#ifdef WIN32
	spawnEntities();
#endif
}

void Simulation::gluiControl(int controlID)
{
    // nothing here for now
}

void Simulation::display()
{    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // drawing commands go here!
    // for example: a red rectangle
    glColor3f(1.0f, 0.0f, 0.0f);
    //glRecti(100, 100, 200, 200);

    // or... a robot!
	EntityManager::getInstance().render();

    // debugging messages
	int err;
    if ((err = glGetError()) != GL_NO_ERROR) 
	{
        cerr << "GL is in an error state" << endl;
        cerr << "(GL error code " << err << ")\n";
        assert(0);
    }
    // advance
    glutSwapBuffers();
	update();
	glutPostRedisplay();
}

Simulation::~Simulation()
{
}

void Simulation::leftMouseDown(int x, int y)
{
    // nothing here for now
}

void Simulation::leftMouseUp(int x, int y)
{
	EntityManager::getInstance().render();
    // nohing here for now
}


void Simulation::update()
{
	Clock::getInstance().update();
	if (!paused)
	{
		EntityManager::getInstance().update();
	}
}

// Author:
void Simulation::start(int i)
{
	EntityManager::getInstance().clear();
	spawnEntities();
	paused = false;
}

// Author: Andrew Hartfiel
void Simulation::pause(int i)
{
	paused = true;
}

// Author: Andrew Hartfiel
void Simulation::resume(int i)
{
	paused = false;
}

void Simulation::spawnEntities()
{
	const int borderFudge = 70;
	const int maxRadiusAddition = 60; //Added on top of the minimum radius to form a 100 max radius.
	const int minRadius = 35;

	// make robots
	for (int i = 0; i < 2; i++)
	{
		int radius = 50;
		int xpos = rand() % (glutGet(GLUT_WINDOW_WIDTH) - 2 * radius) + radius;
		int ypos = rand() % (glutGet(GLUT_WINDOW_HEIGHT) - 2 * radius - borderFudge) + radius;
		RobotClass* robot = new RobotClass(xpos, ypos, radius);
		while (EntityManager::getInstance().collideWithAnything(robot))
		{
			xpos = rand() % (glutGet(GLUT_WINDOW_WIDTH) - 2 * radius) + radius;
			ypos = rand() % (glutGet(GLUT_WINDOW_HEIGHT) - 2 * radius - borderFudge) + radius;
			robot->setPosition(Vector2<float>(xpos, ypos));
		}
		robot->setSpeed(50);
		float r = Mathf::randf(0, .4);
		float g = Mathf::randf(.5, 1.0);
		float b = Mathf::randf(0, .4);
		robot->setColor(Color(r, g, b));
		EntityManager::getInstance().add(robot);


		radius = 40;
		xpos = rand() % (glutGet(GLUT_WINDOW_WIDTH) - 2 * radius) + radius;
		ypos = rand() % (glutGet(GLUT_WINDOW_HEIGHT) - 2 * radius - borderFudge) + radius;
		Target* target = new Target(xpos, ypos, radius);
		while (EntityManager::getInstance().collideWithAnything(target))
		{
			xpos = rand() % (glutGet(GLUT_WINDOW_WIDTH) - 2 * radius) + radius;
			ypos = rand() % (glutGet(GLUT_WINDOW_HEIGHT) - 2 * radius - borderFudge) + radius;
			target->setPosition(Vector2<float>(xpos, ypos));
		}
		target->setSpeed(30);
		target->setColor(Color(r, b, g));
		EntityManager::getInstance().add(target);
		robot->setTargetID(target->getID());
	}

	// make obstacle 1
	for (int i = 0; i < 6; i++)
	{
		int radius = rand() % maxRadiusAddition + minRadius;
		int xpos = rand() % (glutGet(GLUT_WINDOW_WIDTH) - 2 * radius) + radius;
		int ypos = rand() % (glutGet(GLUT_WINDOW_HEIGHT) - 2 * radius - borderFudge) + radius;
		Obstacle* obstacle = new Obstacle(xpos, ypos, radius);
		while (EntityManager::getInstance().collideWithAnything(obstacle))
		{
			xpos = rand() % (glutGet(GLUT_WINDOW_WIDTH) - 2 * radius) + radius;
			ypos = rand() % (glutGet(GLUT_WINDOW_HEIGHT) - 2 * radius - borderFudge) + radius;
			obstacle->setPosition(Vector2<float>(xpos, ypos));
		}
		obstacle->setSpeed(30);

		float r = Mathf::randf(.7, 1.0);
		float g = Mathf::randf(.7, 1.0);
		float b = Mathf::randf(0, .4);
		obstacle->setColor(Color(r, g, b));

		EntityManager::getInstance().add(obstacle);
	}
}

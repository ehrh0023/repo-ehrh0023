#include "Simulation.h"
#include "Entity/Paddle.h"
#include "Entity/Ball.h"
#include "Entity/EntityManager.h"
#include "Clock.h"
#include "Keyboard.h"
#include <time.h>
#include <iostream>
#include "randf.h"

bool paused = false;

void start(int);
void pause(int);
void resume(int);
void quit(int);
void spawnEntities();

void changeAccelMode(int);
void changepLeftAIMode(int);
void changepRightAIMode(int);

GLUI_Checkbox* accelCheck;
GLUI_Checkbox* pLeftAICheck;
GLUI_Checkbox* pRightAICheck;

bool pLeftAI = false;
bool pRightAI = false;

Simulation::Simulation(int argc, char* argv[], int width, int height) 
	: BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH, true, 851, 50)
{
	setCaption("Robot Simulation");

    //creates a basic UI panel with quit button
	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Control Panel");
    new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)exit);
    new GLUI_Button(m_glui, "Start", UI_START, (GLUI_Update_CB)start);
    new GLUI_Button(m_glui, "Pause", UI_PAUSE, (GLUI_Update_CB)pause);
    new GLUI_Button(m_glui, "Resume", UI_RESUME, (GLUI_Update_CB)resume);

	GLUI_Panel *behaviorPanel = new GLUI_Panel(m_glui, "Game Options");
	accelCheck = new GLUI_Checkbox(behaviorPanel, "Acceleration mode", NULL, -1, changeAccelMode);
	accelCheck->set_int_val(0);
	pLeftAICheck = new GLUI_Checkbox(behaviorPanel, "Left Player AI", NULL, -1, changepLeftAIMode);
	pLeftAICheck->set_int_val(0);
	pRightAICheck = new GLUI_Checkbox(behaviorPanel, "Right Player AI", NULL, -1, changepRightAIMode);
	pRightAICheck->set_int_val(0);


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
}

void Simulation::gluiControl(int controlID)
{
    // nothing here for now
}

void Simulation::display()
{    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

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

void Simulation::keyboard(unsigned char c, int x, int y)
{
	System::Keyboard::getInstance().onKeyPress(c);
}


void Simulation::keyboardUp(unsigned char c, int x, int y)
{
	System::Keyboard::getInstance().onKeyRelease(c);
}

void Simulation::update()
{
	Clock::getInstance().update();
	System::Keyboard::getInstance().update();
	if (!paused)
	{
		EntityManager::getInstance().update();
	}
	if (EntityManager::gameOver)
	{
		spawnEntities();
		EntityManager::gameOver = false;
	}
}

// Author:
void start(int i)
{
	EntityManager::getInstance().clear();
	spawnEntities();
	paused = false;
}

// Author: Andrew Hartfiel
void pause(int i)
{
	paused = true;
}

// Author: Andrew Hartfiel
void resume(int i)
{
	paused = false;
}

Paddle* pLeft;
Paddle* pRight;


void spawnEntities()
{
	EntityManager::getInstance().clear();

	Ball* ball = new Ball(Drawing::getWindowWidth() >> 1, rand() % Drawing::getWindowHeight(), 20, 20);
	int chance = rand() & 3;
	switch (chance)
	{
	case 0:
		ball->rotate(90);
		break;
	case 1:
		ball->rotate(180);
		break;
	case 2:
		ball->rotate(-90);
		break;
	}
	EntityManager::getInstance().add(ball);
	ball->setSpeed(300);
	ball->setColor(Color(1, 1, 1));

	Controls controls1('w', 's');
	Paddle* paddle = new Paddle(20, Drawing::getWindowHeight() >> 1, 20, 120, controls1);
	EntityManager::getInstance().add(paddle);
	paddle->setSpeed(200);
	paddle->setColor(Color(1, 1, 1));
	paddle->setBall(ball);
	pLeft = paddle;
	pLeft->setAI(pLeftAI);

	Controls controls2('i', 'k');
	paddle = new Paddle(Drawing::getWindowWidth() - 60, Drawing::getWindowHeight() >> 1, 20, 120, controls2);
	EntityManager::getInstance().add(paddle);
	paddle->setSpeed(200);
	paddle->setColor(Color(1, 1, 1));
	paddle->setBall(ball);
	pRight = paddle;
	pRight->setAI(pRightAI);
}

void changeAccelMode(int mode)
{	
	Ball::accelMode = !Ball::accelMode;
}

void changepLeftAIMode(int mode)
{
	pLeftAI = !pLeftAI;

	if (pLeft != NULL)
		pLeft->setAI(pLeftAI);
}

void changepRightAIMode(int mode)
{
	pRightAI = !pRightAI;

	if (pRight!=NULL)
		pRight->setAI(pRightAI);
}
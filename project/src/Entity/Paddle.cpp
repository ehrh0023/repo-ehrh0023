#include "Paddle.h"
#include <GL/glui.h>
#include "../randf.h"
#include "../Clock.h"
#include "../Keyboard.h"

// Author: Dennis Ehrhardt
void Paddle::update()
{
	if (!isAI)
	{
		System::Keyboard keyboard = System::Keyboard::getInstance();
		if (keyboard.keyHeld(controls.up))
		{
			translate(Vector2f(0, 1) * speed * Clock::getInstance().getDeltaTime());
		}
		if (keyboard.keyHeld(controls.down))
		{
			translate(Vector2f(0, -1) * speed * Clock::getInstance().getDeltaTime());
		}
	}
	else if (ball != NULL)
	{
		float y = estimateCollisionPoint();
		if (y > getPosition().y)	
			translate(Vector2f(0, 1) * speed * Clock::getInstance().getDeltaTime());
		if (y < getPosition().y)
			translate(Vector2f(0, -1) * speed * Clock::getInstance().getDeltaTime());

	}
}

float Paddle::estimateCollisionPoint()
{
	float xdist = abs(ball->getBody().getCenter().x - body.getCenter().x);

	float deltaY = Drawing::getWindowHeight() - 200;
	float deltaX = deltaY; // 45 degree angles are awesome


	bool fromTop = ball->getOrientation().y < 0;

	while (xdist > deltaX)
	{
		xdist -= deltaX;
		fromTop != fromTop;
	}

	float ydist = xdist * ball->getSpeed();

	if (fromTop)
	{
		return Drawing::getWindowHeight() - 100 - ydist;
	}
	else
		return 100 + ydist;

}

// Author: Dennis Ehrhardt
void Paddle::render()
{
	Entity::render();
}


void Paddle::setBall(Ball* ball)
{
	this->ball = ball;
}


void Paddle::setAI(bool on)
{
	isAI = on;
}
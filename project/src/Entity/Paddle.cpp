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
	return ball->getPosition().y;
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
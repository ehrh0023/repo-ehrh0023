#include "Ball.h"
#include "../randf.h"
#include "../Clock.h"

void Ball::update()
{
	if (body.getTop() >= Drawing::getWindowHeight())
		setOrientation(Vector2f(orientation.x, -.3));
	else if (body.getBottom() < 0)
		setOrientation(Vector2f(orientation.x, .3));


	setSpeed(100);
	velocity = orientation * speed * Clock::getInstance().getDeltaTime();
	translate(velocity);
}

void Ball::render()
{
	// Draw the entity on the screen
	Entity::render();
}


void Ball::onCollideLeft()
{
	setOrientation(Vector2f(.6, orientation.y));
}

void Ball::onCollideRight()
{
	setOrientation(Vector2f(-.6, orientation.y));
}
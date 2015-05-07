#include "Ball.h"
#include "../randf.h"
#include "../Clock.h"

void Ball::update()
{
	translate(velocity);
	velocity = orientation * speed * Clock::getInstance().getDeltaTime();
}

void Ball::render()
{
	// Draw the entity on the screen
	Entity::render();
}


void Ball::onCollideLeft()
{
	Entity::onCollideLeft();
	setOrientation(Vector2f(0.70710678118, orientation.y));
}

void Ball::onCollideRight()
{
	Entity::onCollideRight();
	setOrientation(Vector2f(-0.70710678118, orientation.y));
}

void Ball::onCollideDown()
{
	Entity::onCollideDown();
	setOrientation(Vector2f(orientation.x, 0.70710678118));
}

void Ball::onCollideUp()
{
	Entity::onCollideUp();
	setOrientation(Vector2f(orientation.x, -0.70710678118));
}
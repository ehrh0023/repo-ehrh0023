#include "Ball.h"
#include "Paddle.h"
#include "../randf.h"
#include "../Clock.h"
#include "EntityManager.h"

bool isEntityCol;

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
	if (!isEntityCol)
	{
		EntityManager::rightWins++;
	}
	Entity::onCollideLeft();
	setOrientation(Vector2f(0.70710678118, orientation.y));
}

void Ball::onCollideRight()
{
	if (!isEntityCol)
	{
		EntityManager::leftWins++;
	}
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

void Ball::collide(Entity* otherEntity)
{
	Paddle* paddle = dynamic_cast<Paddle*>(otherEntity);
	if (paddle != NULL)
	{
		if (getPosition().x < Drawing::getWindowWidth() >> 1)
		{
			Rect myBody = body;
			Rect theirBody = otherEntity->getBody();

			if (myBody.overlaps(theirBody))
			{
				body.setLeft(paddle->getBody().getRight());
				isEntityCol = true;
				onCollideLeft();
				isEntityCol = false;
			}
		}
		else
		{
			Rect myBody = body;
			Rect theirBody = otherEntity->getBody();

			if (myBody.overlaps(theirBody))
			{
				body.setRight(paddle->getBody().getLeft());
				isEntityCol = true;
				onCollideRight();
				isEntityCol = false;
			}
		}
	}
}
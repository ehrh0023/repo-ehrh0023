#include "RobotClass.h"
#include "Target.h"
#include "Obstacle.h"
#include "../Clock.h"
#include "EntityManager.h"
#include "../Color.h"
#include <iostream>

// Author: Evan Stuempfig
void RobotClass::update()
{

	// Update the entity's position and behavior
	if (collidePathCount == 0)
	{
		pointAtTarget();
	}
	else if (collidePathCount > 0)
	{
		collidePathCount --;
	}
	translate(orientation * speed * Clock::getInstance().getDeltaTime());

}

// Author: Dennis Ehrhardt
void RobotClass::render()
{
	// Draw the entitiy on the screen
	if (colliding || Clock::getInstance().getCurrentTime() < collisionColorDelay)
	{
		Drawing::drawCircle(position, radius, Color());
		collisionColorDelay = Clock::getInstance().getCurrentTime() + 1000;
	}
	else
		Drawing::drawCircle(position, radius, rgb);

	Vector2f lineEnd(position.x + orientation.x * radius, position.y + orientation.y * radius);
	Drawing::drawLine(position, lineEnd, Color(1.0f, 0.0f, 1.0f), 4);

	if (!hasCollided)
	{
		colliding = false;	
	}
	else
	{
		hasCollided = false;
	}
}

// Author: Andrew Hartfiel
void RobotClass::pointAtTarget()
{
	setOrientation(EntityManager::getInstance().homingFeedback(entityID, targetID));
}

// Author: Andrew Hartfiel
Vector2f RobotClass::getHomingInfo()
{
	return EntityManager::getInstance().homingFeedback(entityID, targetID);
}

// Author: Andrew Hartfiel
unsigned int RobotClass::getTargetID()
{
	return targetID;
}

// Author: Andrew Hartfiel
void RobotClass::setTargetID(unsigned int tar)
{
	targetID = tar;
}


// Author: Evan Stuempfig, Andrew Hartfiel
void RobotClass::onCollide(Entity* otherEntity)
{
	
	hasCollided = true;
	/*
	Note: This code is intended for future distinction between additional collision behaviors	

	int collisionType = 0;

	if (dynamic_cast<Target *>(otherEntity) != NULL)
	{
		collisionType = 1;
	}
	else if (dynamic_cast<RobotClass *>(otherEntity) != NULL)
	{
		collisionType = 2;
	}
	else if (dynamic_cast<Obstacle *>(otherEntity) != NULL)
	{
		collisionType = 3;
	}*/

	// Function called when this entity collides with another
	// If a collided with a RobotClass the round ends
	unsigned int otherEntID = EntityManager::getInstance().getEntityID(otherEntity);
	// If the ID of the object matches that of the robots target, mark both for deletion
	if (otherEntID == targetID)
	{
		markForDeletion();
		otherEntity->markForDeletion();
	}
	// Otherwise, respond to collision with any other entity
	else
	{
		if (!colliding)
		{
			colliding = true;
			rotate(90);
			/*Vector2f otherPosition = otherEntity->getPosition();
			if (position.angle(otherPosition) > 0)
			{
				rotate(90);
			}
			else
			{
				rotate(270);
			}*/
			collidePathCount = 50;
		}
	}	
}

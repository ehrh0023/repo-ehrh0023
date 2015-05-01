#include "Entity.h"
#include "EntityManager.h"
#include <math.h>
#include <iostream>
#include "../Drawing.h"
#include "../Color.h"

const Vector2f stdVect(1, 0);

// Author: Dennis Ehrhardt
// Constructor for x and y coordinates and radius
Entity::Entity(int posX, int posY, int radiusIn):
	position(Vector2f(posX, posY)),
	setForDeletion(false),
	radius(radiusIn),
	orientation(stdVect),
	rotation(0)
	//wallCollideCount(0)
{
}

// Author: Dennis Ehrhardt
// Constructor for Vector2 position instance and radius
Entity::Entity(Vector2f vectorIn, int radiusIn):
	position(vectorIn),
	setForDeletion(false),
	radius(radiusIn),
	orientation(stdVect),
	rotation(0)
	//wallCollideCount(0)
{


} 

// Author: Evan Stuempfig
// Calls EntityManager's collide function to check whether it has encountered any other entities or the walls.
// Will perform other tasks as well in the future.
void Entity::update() 
{
	// This code, along with other commented-out sections, is for a potential improved collision system if it proves useful in future iterations
	//if (wallCollideCount > 0)
	//{
	//	wallCollideCount --;
	//}
}

// Author: Dennis Ehrhardt
// Displays the entity in the output window
void Entity::render() 
{	
	Drawing::drawCircle(position, radius, rgb);
}

// Author: Andrew Hartfiel
// Translate by an integer Vector2
void Entity::translate(Vector2<int> const& shift)
{
	position.x += shift.x;
	position.y += shift.y;
}

// Author: Andrew Hartfiel
// Translate by a float Vector2
void Entity::translate(Vector2f const& shift)
{
	position += shift;
}

// Author: Andrew Hartfiel
// Translate by x and y integers
void Entity::translate(int x, int y)
{
	position.x += x;
	position.y += y;
}

// Author: Andrew Hartfiel
// Rotate by specified number of degrees (converts degree parameter to radians before updating orientation)
void Entity::rotate(float angle)
{
	const float PI = 3.14159265359;
	float radAngle = (angle / 180)*PI;
	orientation.rotate(radAngle);
	rotation += radAngle;

	while (rotation <= -PI)
	{
		rotation += 2 * PI;
	}
	while (rotation > PI)
	{
		rotation -= 2 * PI;
	}
}

// Author: Andrew Hartfiel
// Rotate by specified number of radians
void Entity::rotateRad(float angle)
{
	const float PI = 3.14159265359;
	orientation.rotate(angle);
	rotation += angle;

	while (rotation <= -PI)
	{
		rotation += 2 * PI;
	}
	while (rotation > PI)
	{
		rotation -= 2 * PI;
	}
}

// Author: Evan Stuempfig
// Returns position Vector2 of entity
Vector2f Entity::getPosition() const
{
	return position;
}

// Author: Evan Stuempfig
// Assigns supplied Vector2 to position
void Entity::setPosition(Vector2f const& newPosition)
{
	position = newPosition;
}

// Author: Andrew Hartfiel
// Returns orientation Vector2 of entity
Vector2f Entity::getOrientation() const
{
	return orientation;
}

// Author: Andrew Hartfiel
// Assigns supplied Vector2 to orientation
void Entity::setOrientation(Vector2f const& newOrientation)
{
	orientation = newOrientation;
	orientation.normalize();

	// Change Rotation
	rotation = acos(orientation.dot(stdVect));
	if (orientation.y > 0)
		rotation = -rotation;
}

// Author: Dennis Ehrhardt
// Returns rotation float of entity
float Entity::getRotation() const
{
	return rotation;
}

// Author: Dennis Ehrhardt
// Assigns supplied float to rotation
void Entity::setRotation(float newRotation)
{
	const float PI = 3.14159265359;
	rotation = newRotation;

	while (rotation <= -PI)
	{
		rotation += 2 * PI;
	}
	while (rotation > PI)
	{
		rotation -= 2 * PI;
	}
}

// Author: David Tran
// Returns speed integer (pixels per second)
int Entity::getSpeed() const 
{
	return speed;
}

// Author: David Tran
// Sets speed (defaults to 0 if input is negative)
void Entity:: setSpeed(int newSpeed)
{
	if (newSpeed > 0)
		speed = newSpeed;
	else
		speed = 0;
}

// Author: David Tran
// Returns velocity Vector2 of entity
Vector2f Entity::getVelocity() const
{
	return velocity;
}

// Author: David Tran
// Assigns supplied Vector2 to velocity
void Entity::setVelocity(Vector2f const& newVelocity)
{
	velocity = newVelocity;
}

// Author: Evan Stuempfig
// Compares the positions of entity to the entity supplied, returning true if there is a collision and false otherwise
// Assumes both entities are circles, which is the case for all entities at this point
// A shared point along the circumference of both entities counts as a collision
bool Entity::collide(Entity* otherEntity)
{
	float combinedRadius = radius + otherEntity->radius;
	float distanceSqr = position.lengthSquared(otherEntity->position);
	if (distanceSqr <= combinedRadius*combinedRadius)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

// Author: David Tran
// Checks whether entity is within bounds of window, returning true if its position is valid and false otherwise
// Window size is hardcoded for now, but may be changeable in future iterations
bool Entity::boundsCheck() 
{
	return (
		((position.x - radius) >= 0) &&
		((position.x + radius) <= 800) &&
		((position.y - radius) >= 0) &&
		((position.y + radius) <= 800));
}

// Author: Dennis Ehrhardt
// Default onCollide function, in which objects deflect at approximately their angle of incidence
void Entity::onCollide(Entity* otherEntity) 
{
	const float PI = 3.14159265359;
	Vector2f colOrientation = (position - otherEntity->position).normalize();
	float combinedRadius = radius + otherEntity->radius + 1;
	setPosition(colOrientation * combinedRadius + otherEntity->position);
	float twoangle = 2* colOrientation.angle(orientation);
	rotateRad(PI + twoangle);
}

// Author: Evan Stuempfig
// Determines which wall is collided with, if any, and adjusts position and orientation appropriately
void Entity::wallCollide() 
{

	//const float PI = 3.14159265359;

	if ((position.x - radius) < 0)
	{
		setPosition(Vector2f(radius, position.y));
		setOrientation(Vector2f(-1 * orientation.x, orientation.y));
		//wallCollideCount = 300;
	}
	else if ((position.x + radius) > 800)
	{
		setPosition(Vector2f(800 - radius, position.y));
		setOrientation(Vector2f(-1 * orientation.x, orientation.y));
		//wallCollideCount = 300;
	}
	else if ((position.y - radius) < 0) 
	{
		setPosition(Vector2f(position.x, radius));
		setOrientation(Vector2f(orientation.x, -1 * orientation.y));
		//wallCollideCount = 300;
	}
	else if ((position.y + radius) > 800)
	{
		setPosition(Vector2f(position.x, 800 - radius));
		setOrientation(Vector2f(orientation.x, -1 * orientation.y));
		//wallCollideCount = 300;
	}
}

// Author: David Tran
// Returns radius integer
int Entity::getRadius() const
{
	return radius;
}

// Author: David Tran
// Sets radius
void Entity::setRadius(int newRadius)
{
	radius = newRadius;
}


// Author: Dennis Ehrhardt
// Gets ID
unsigned int Entity::getID()
{
	return entityID;
}

// Author: Dennis Ehrhardt
// Sets ID
void Entity::setID(unsigned int id)
{
	entityID = id;
}


// Author: David Tran
// Sets color
void Entity::setColor(Color newColor)
{
	rgb = newColor;
}

Color Entity::getColor()
{
	return rgb;
}


void Entity::markForDeletion()
{
	setForDeletion = true;
}

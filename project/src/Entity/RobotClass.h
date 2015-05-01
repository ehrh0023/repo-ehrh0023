#pragma once
#include "Entity.h"

/*! 
	\brief The class for creating robots.
	\author Dennis Ehrhardt
	\author Evan Stuempfig
	\author Andrew Hartfiel
	\author David Tran
*/
class RobotClass : public Entity
{
protected:
	unsigned int targetID;
	bool hasCollided;
	bool colliding;
	bool collisionColorDelay;
	Color rgb;
	int collidePathCount;
	
public:
	/*! This constructor requires three parameters: x position, y position, and radius.
		\param posX the x position in pixels
		\param posY the y position in pixels
		\param radius the radius in pixels
	*/
	RobotClass(int posX, int posY, int radius): Entity(posX, posY, radius)
	{
		rgb = Color(0.0f,1.0f,0.0f);
		colliding = false;
		hasCollided = false;
		collisionColorDelay = 0;
		collidePathCount = 0;
	}

	/*! This constructor requires two parameters: location and radius.
		\param location the x and y position in pixels as a Vector2
		\param radius the radius in pixels
	*/
	RobotClass(Vector2f position, int radius): Entity(position, radius) 
	{
		rgb = Color(0.0f, 1.0f, 0.0f);
		colliding = false;
		hasCollided = false;
		collisionColorDelay = 0;
		collidePathCount = 0;
	}
	
	/*! Update the robot's position and behavior, which alternates between seeking its target and responding to collisions */
	void update();

	/*! Draw the robot on the screen */
	void render();
	
	/*! Point the robot at the target */
	void pointAtTarget();

	/*! Gets the distance and direction to target
		\return Homing information
	*/
	Vector2f getHomingInfo();

	/*! Get the target ID
		\return Target ID
	*/
	unsigned int getTargetID();

	/*! Set the target ID
		\param tar change the robot's target (int)
	*/
	void setTargetID(unsigned int tar);

	/*! Called when this robot collides with another entity, rotating 90 degrees unless the robot collides with its assigned target, in which case both the robot and the target are removed from the simulation.
		\param otherEntity the other entity
	*/
	void onCollide(Entity* otherEntity);

};

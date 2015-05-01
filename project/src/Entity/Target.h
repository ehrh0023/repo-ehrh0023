#pragma once
#include "Entity.h"

/*! 
	\brief The class for creating targets.
	\author Dennis Ehrhardt
	\author Evan Stuempfig
	\author Andrew Hartfiel
	\author David Tran
*/
class Target : public Entity
{
	Vector2f wanderTarget;

	const float wanderRadius;
	const float wanderDistance;
	const float wanderJitter;

public:
	/*! This constructor requires three parameters: x position, y position, and radius.
		\param posX the x position in pixels
		\param posY the y position in pixels
		\param radius the radius in pixels
	*/
	Target(int posX, int posY, int radius)
		: Entity(posX, posY, radius),
		wanderRadius(50),
		wanderDistance(0),
		wanderJitter(1)
	{
		rgb = Color(0.0f,0.0f,1.0f);
	}

	/*! This constructor requires two parameters: location and radius.
		\param location the x and y position in pixels as a Vector2
		\param radius the radius in pixels
	*/
	Target(Vector2f position, int radius)
		: Entity(position, radius),
		wanderRadius(50),
		wanderDistance(0),
		wanderJitter(1)
	{
		rgb = Color(0.0f,0.0f,1.0f);
	}
	
	/*! Update the target's position and behavior; Utilizes randomized motion */
	void update();
	/*! Draw the target on the screen */
	void render();

private:
	/*! Called when this entity collides with another
		\param otherEntity the other entity
		\param colPoint the point of collision
		\note Collision with a RobotClass ends the round
	*/
	void onCollide(Entity* otherEntity, Vector2f const& colPoint);
};

#pragma once
#include "Entity.h"

/*! 
	\brief The class for creating obstacles.
	\author Dennis Ehrhardt
	\author Evan Stuempfig
	\author Andrew Hartfiel
	\author David Tran
*/
class Obstacle : public Entity
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
	Obstacle(int posX, int posY, int width, int height): 
		Entity(posX, posY, width, height),
		wanderRadius(50),
		wanderDistance(0),
		wanderJitter(1)
	{
		rgb = Color(1.0f,1.0f,0.0f);
	}

	/*! This constructor requires two parameters: location and radius.
		\param location the x and y position in pixels as a Vector2
		\param radius the radius in pixels
	*/
	Obstacle(Vector2f position, int width, int height):
		Entity(position, width, height), 
		wanderRadius(50),
		wanderDistance(0),
		wanderJitter(1)
	{
		rgb = Color(1.0f,1.0f,0.0f);
	}
	
	/*! Update the obstacle's position and behavior; Utilizes randomized motion */
	void update();

	/*! Draw the obstacle on the screen */
	void render();
};

#pragma once
#include "Entity.h"

class Ball : public Entity
{
public:
	Ball(int posX, int posY, int width, int height) :
		Entity(posX, posY, width, height)
	{
		rgb = Color(1.0f, 1.0f, 0.0f);
	}


	Ball(Vector2f position, int width, int height) :
		Entity(position, width, height)
	{
		rgb = Color(1.0f, 1.0f, 0.0f);
	}

	/*! Update the balls's position and behavior */
	void update();

	/*! Draw the ball on the screen */
	void render();
};
#pragma once
#include "Entity.h"
#include <iostream>

class Ball : public Entity
{
public:
	Ball(int posX, int posY, int width, int height) :
		Entity(posX, posY, width, height)
	{
		rgb = Color(1.0f, 1.0f, 0.0f);
		setOrientation(Vector2f(0.70710678118, 0.70710678118));
	}


	Ball(Vector2f position, int width, int height) :
		Entity(position, width, height)
	{
		rgb = Color(1.0f, 1.0f, 0.0f);
		setOrientation(Vector2f(0.70710678118, 0.70710678118));
	}

	/*! Update the balls's position and behavior */
	void update();

	/*! Draw the ball on the screen */
	void render();

	void collide(Entity* otherEntity);
	void onCollideLeft();
	void onCollideRight();
	void onCollideUp();
	void onCollideDown();
};
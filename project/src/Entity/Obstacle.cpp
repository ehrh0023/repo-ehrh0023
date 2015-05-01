#include "Obstacle.h"
#include <GL/glui.h>
#include "../randf.h"
#include "../Clock.h"

// Author: Dennis Ehrhardt, Evan Stuempfig
void Obstacle::update()
{
	// Update the entity's position and behavior
	Entity::update();
	
	//if (wallCollideCount == 0)
	//{
		float jitter = wanderJitter;
		wanderTarget.x += Mathf::randf(-jitter, jitter);
		wanderTarget.y += Mathf::randf(-jitter, jitter);
	
		wanderTarget.normalize();
		wanderTarget *= wanderRadius;
	
		Vector2f target = wanderTarget;
		target.x += wanderDistance;
		target.rotate(rotation);
	
		target.normalize();
		setOrientation(target);
	
		target *= speed * Clock::getInstance().getDeltaTime();
		translate(target);
	//}
	//else
	//{
		//translate(orientation * speed * Clock::getInstance().getDeltaTime());
	//}
	
}

// Author: Dennis Ehrhardt
void Obstacle::render()
{
	// Draw the entity on the screen
//	glColor3f(1.0f, 1.0f, 0.0f);
	Entity::render();
}

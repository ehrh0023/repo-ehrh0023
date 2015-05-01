#include "Target.h"
#include <GL/glui.h>
#include "../randf.h"
#include "../Clock.h"

// Author: Dennis Ehrhardt, Evan Stuempfig
void Target::update()
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
	//	translate(orientation * speed * Clock::getInstance().getDeltaTime());
	//}

}

// Author: Dennis Ehrhardt
void Target::render()
{
	// Draw the entitiy on the screen
//	glColor3f(0.0f, 0.0f, 1.0f);
	Entity::render();
}



void Target::onCollide(Entity* otherEntity, Vector2f const& colPoint)
{
	// Function called when this entity collides with another
	// If collided with a RobotClass the round ends
}

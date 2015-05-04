#include "Paddle.h"
#include <GL/glui.h>
#include "../randf.h"
#include "../Clock.h"
#include "../Keyboard.h"

// Author: Dennis Ehrhardt
void Paddle::update()
{
	System::Keyboard keyboard = System::Keyboard::getInstance();
	if (keyboard.keyHeld(controls.up))
	{
		translate(Vector2f(0, 1) * speed * Clock::getInstance().getDeltaTime());
	}
	if (keyboard.keyHeld(controls.down))
	{
		translate(Vector2f(0, -1) * speed * Clock::getInstance().getDeltaTime());
	}
}

// Author: Dennis Ehrhardt
void Paddle::render()
{
	Entity::render();
}

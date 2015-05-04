#include "Paddle.h"
#include <GL/glui.h>
#include "../randf.h"
#include "../Clock.h"
#include "../Keyboard.h"

// Author: Dennis Ehrhardt
void Paddle::update()
{
	System::Keyboard keyboard = System::Keyboard::getInstance();
	if (keyboard.keyHeld('w') || keyboard.keyHeld('W'))
	{
		translate(Vector2f(0, 1) * speed * Clock::getInstance().getDeltaTime());
	}
	if (keyboard.keyHeld('s') || keyboard.keyHeld('S'))
	{
		translate(Vector2f(0, -1) * speed * Clock::getInstance().getDeltaTime());
	}
}

// Author: Dennis Ehrhardt
void Paddle::render()
{
	Entity::render();
}

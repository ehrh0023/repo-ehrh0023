#include "Keyboard.h"

System::Keyboard::Keyboard()
{
	for(int i = 0; i < 256; i++)
	{
		keys[i] = Key::ksUp;
	}
}

System::Keyboard& System::Keyboard::getInstance()
{
	static System::Keyboard instance;
	return instance;
}

void System::Keyboard::update()
{
	for(int i = 0; i < 256; i++)
	{
		if(keys[i] == Key::ksLetGo)
			keys[i] = Key::ksUp;
		else if(keys[i] == Key::ksHit)
			keys[i] = Key::ksHeld;
	}
}

void System::Keyboard::onKeyPress(unsigned char key)
{
	keys[key] = Key::ksHit;
}

void System::Keyboard::onKeyRelease(unsigned char key)
{
	keys[key] = Key::ksLetGo;
}

bool System::Keyboard::keyHit(unsigned char key)
{
	return keys[key] == Key::ksHit;
}
		
bool System::Keyboard::keyHeld(unsigned char key)
{
	return keys[key] == Key::ksHit || keys[key] == Key::ksHeld;
}
		
bool System::Keyboard::keyLetGo(unsigned char key)
{
	return keys[key] == Key::ksLetGo;
}

bool System::Keyboard::keyUp(unsigned char key)
{
	return keys[key] == Key::ksUp || keys[key] == Key::ksLetGo;
}

bool System::Keyboard::anyKeyHeld()
{
	for(int i = 0; i < 256; i++)
	{
		if(keyHeld(i))
			return true;
	}
	return false;
}

bool System::Keyboard::anyKeyHit()
{
	for(int i = 0; i < 256; i++)
	{
		if(keyHit(i))
			return true;
	}
	return false;
}
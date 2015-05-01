#ifndef KEYBOARD_H
#define KEYBOARD_H

namespace System
{
	namespace Key
	{	
		enum KeyState
		{
			ksUp = 0,
			ksHit,
			ksHeld,
			ksLetGo,
		};
	}

	class Keyboard
	{
		Key::KeyState keys[256];
		
		Keyboard();
		void operator=(Keyboard const&);

	public:

		/* Keyboard is a singleton class */
		static Keyboard& getInstance();

		/* Update the keyboard's key states */
		void update();

		void onKeyPress(unsigned char key);
		void onKeyRelease(unsigned char key);

		/*! returns true if key is was just pressed - edge sensitive
			\param key (unsigned char) to check
			\return return true if key is was just pressed (bool)
		*/
		bool keyHit(unsigned char key);

		/*! returns true if key is down
			\param key (unsigned char) to check
			\return return true if key is held (bool)
		*/
		bool keyHeld(unsigned char key);
		
		/*! returns true if key is was just released  - edge sensitive
			\param key (unsigned char) to check
			\return return true if key is was just released (bool)
		*/
		bool keyLetGo(unsigned char key);

		/*! returns true if key is up
			\param key (unsigned char) to check
			\return return true if key is up (bool)
		*/
		bool keyUp(unsigned char key);
		
		/*! returns true if any key was just pressed - edge sensitive
			\return return true if key sny was just pressed (bool)
		*/
		bool anyKeyHit();
		
		/*! returns true if any key is down
			\return true if any key is down (bool)
		*/
		bool anyKeyHeld();
	};
}
#endif

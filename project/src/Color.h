#pragma once
#include <math.h>

/*! 
	\brief A Three float holder for colors to be cast as (R,G,B)
	\author David Tran
*/

// Currently broken. (3/2/15: 9:00 PM)
class Color
{

public:
	/* Color holds 3 float pieces of data representing red, green, and blue on a color spectrum. */
	float red;
	float green;
	float blue;

	/*! Default constructor: sets color to white. */
	Color(): red(1.0f), green(1.0f), blue(1.0f) {}

	/*! Second constructor: allows manual setting of red, green, and blue, but within the boundaries of 0.0 and 1.0. */
	Color(float input_red, float input_green, float input_blue): red(input_red), green(input_green), blue(input_blue) {}
	
	/*! Set the red, green, and blue
		\param input_red the new red value
		\param input_green the new green value
		\param input_blue the new blue value
	*/
	Color setColors(float input_red, float input_green, float input_blue);

	/*! Set the red. 
		\param input_red the new red value	
	*/	
	Color setRed(float input_red);
	
	/*! Set the green. 
		\param input_green the new green value	
	*/
	Color setGreen(float input_green);
	
	/*! Set the blue. 
		\param input_blue the new blue value	
	*/
	Color setBlue(float input_blue);
	
	/*! Change the RGB so that this color set represents red.	
		\return The color red
	*/
	Color turnRed();

	/*! Change the RGB so that this color set represents green.	
		\return The color green
	*/
	Color turnGreen();

	/*! Change the RGB so that this color set represents blue.
		\return The color blue
	*/
	Color turnBlue();

	/*! Change the RGB so that this color set represents black.
		\return The color black
	*/
	Color turnBlack();

	/*! Change the RGB so that this color set represents white.
		\return The color white
	*/
	Color turnWhite();

	/*! Get the float value for red 
		\return The red value (float)
	*/
	float getRed();

	/*! Get the float value for green 
		\return The green value (float)
	*/
	float getGreen();

	/*! Get the float value for blue 
		\return The blue value (float)
	*/
	float getBlue();

	/*! Change the current color of something to copy a different color.
		\param baseColor the color we wish to copy
	*/
	Color copy(Color baseColor);

	/*! Returns the inverse of the current color
	\return the inverse of the current color
	*/
	Color inverse();
};

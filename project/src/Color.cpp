#include "Color.h"

// Author: David Tran
// Currently broken (3/2/15, 9:00 PM)
Color Color::setColors(float input_red, float input_green, float input_blue)
{
	// Set x and y of the vector
	this->red = input_red;
	this->green = input_green;
	this->blue = input_blue;

	return *this;
}

Color Color::setRed(float input_red)
{
	if (input_red > 1.0f)
	{
		red = 1.0f;
	}
	else if (input_red < 0.0f)
	{
		red = 0.0f;
	}
	else 
	{
		red = input_red;
	}

	return *this;
}


Color Color::setGreen(float input_green)
{
	if (input_green > 1.0f)
	{
		green = 1.0f;
	}
	else if (input_green < 0.0f)
	{
		green = 0.0f;
	}
	else 
	{
		green = input_green;
	}

	return *this;
}


Color Color::setBlue(float input_blue)
{
	if (input_blue > 1.0f)
	{
		blue = 1.0f;
	}
	else if (input_blue < 0.0f)
	{
		blue = 0.0f;
	}
	else 
	{
		blue = input_blue;
	}

	return *this;
}


Color Color::turnRed()
{
	red = 1.0f;
	green = 0.0f;
	blue = 0.0f;

	return *this;
}


Color Color::turnGreen()
{
	red = 0.0f;
	green = 1.0f;
	blue = 0.0f;

	return *this;
}


Color Color::turnBlue()
{
	red = 0.0f;
	green = 0.0f;
	blue = 1.0f;

	return *this;
}


Color Color::turnBlack()
{
	red = 0.0f;
	green = 0.0f;
	blue = 0.0f;

	return *this;
}


Color Color::turnWhite()
{
	red = 1.0f;
	green = 1.0f;
	blue = 1.0f;

	return *this;
}


float Color::getRed()
{
	if (red > 1.0f)
	{
		return 1.0f;
	}
	else if (red < 0.0f)
	{
		return 0.0f;
	}
	else
	{
		return red;
	}
}

float Color::getGreen()
{
	if (green > 1.0f)
	{
		return 1.0f;
	}
	else if (green < 0.0f)
	{
		return 0.0f;
	}
	else
	{
		return green;
	}
}


float Color::getBlue()
{
	if (blue > 1.0f)
	{
		return 1.0f;
	}
	else if (blue < 0.0f)
	{
		return 0.0f;
	}
	else
	{
		return blue;
	}
}

Color Color::copy(Color baseColor)
{
	red = baseColor.red;
	green = baseColor.green;
	blue = baseColor.blue;

	return *this;
}



//Author: Dennis Ehrhardt
Color Color::inverse()
{
	return Color(1-red, 1-green, 1-blue);
}

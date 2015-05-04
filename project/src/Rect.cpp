#include "Rect.h"

Rect::Rect()
	:position(0, 0),
	width(0),
	height(0)
{
}

Rect::Rect(Vector2f topLeftPos, float rectWidth, float rectHeight)
	:position(topLeftPos),
	width(rectWidth),
	height(rectHeight)
{
}

Rect::Rect(float left, float top, float rectWidth, float rectHeight)
	:position(left, top),
	width(rectWidth),
	height(rectHeight)
{
}

Vector2f Rect::getTopLeft() const
{
	return position;
}

float Rect::getHeight() const
{
	return height;
}

float Rect::getWidth() const
{
	return width;
}

float Rect::getTop() const
{
	return position.y;
}
float Rect::getBottom() const
{
	return position.y + height;
}
float Rect::getLeft() const
{
	return position.x;
}

float Rect::getRight() const
{
	return position.x + width;
}

void Rect::setTopLeft(Vector2f topLeft)
{
	position = topLeft;
}

void Rect::setHeight(float rectHeight)
{
	height = rectHeight;
}

void Rect::setWidth(float rectWidth)
{
	width = rectWidth;
}

Vector2f Rect::getCenter() const
{
	return position + Vector2f(width/2, height/2);
}

Vector2f Rect::setCenter(Vector2f const& center)
{
	position = center - Vector2f(width/2, height/2);
	return center;
}

bool Rect::containsPoint(Vector2f)
{
	return false;
}

bool Rect::overlaps(Rect const& otherRect)
{
	if ((getBottom() > otherRect.getTop()) &&
		(getTop() < otherRect.getBottom()) &&
		(getRight() > otherRect.getLeft()) &&
		(getLeft() < otherRect.getRight())) 
	{ 
	
		// The two objects' collision boxes overlap
		return true;
	}
	
	// The two objects' collision boxes do not overlap
	return false;
}

Vector2f Rect::getBottomRight() const
{
	return Vector2f(position.x + width, position.y + height);
}

Vector2f Rect::setBottomRight(Vector2f const& bottomRight)
{
	position = Vector2f(bottomRight.x - width, bottomRight.y - height);
	return bottomRight;
}


Rect Rect::operator=(Rect const& other)
{
	position = other.position;
	width = other.width;
	height = other.height;
	return *this;
}


float Rect::setTop(float top)
{
	position.y = top;
	return top;
}

float Rect::setBottom(float bottom)
{
	position.y = bottom - height;
	return bottom;
}

float Rect::setLeft(float left)
{
	position.x = left;
	return left;
}

float Rect::setRight(float right)
{
	position.x = right - width;
	return right;
}
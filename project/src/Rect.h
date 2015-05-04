#pragma once
#include "Vector2.h"

class Rect
{
	Vector2f position;
	float width;
	float height;

public:
	Rect();
	Rect(Vector2f, float, float);
	Rect(float, float, float, float);

	Rect operator=(Rect const&);

	/*!
		Get position of the top left corner
		\return the top left corner (Vector2f)
	*/
	Vector2f getTopLeft() const;
	/*!
		Get position of the bottom right corner
		\return the bottom right corner (Vector2f)
	*/
	Vector2f getBottomRight() const;
	/*!
		Get position of the center
		\return the center position (Vector2f)
	*/
	Vector2f getCenter() const;
	/*!
		Get the height of the rectangle
		\return the height (float)
	*/
	float getHeight() const;
	/*!
		Get the width of the rectangle
		\return the width (float)
	*/
	float getWidth() const;

	/*!
		Set position of the top left corner
		\param the top left corner (Vector2f)
	*/
	void setTopLeft(Vector2f);
	/*!
		Set position of the bottom right corner
		\param the bottom right corner (Vector2f)
	*/
	Vector2f setBottomRight(Vector2f const&);
	/*!
		Set position of the center
		\param the center position (Vector2f)
	*/
	Vector2f setCenter(Vector2f const&);
	/*!
		Set the height of the rectangle
		\param the height (float)
	*/
	void setHeight(float);
	/*!
		Set the width of the rectangle
		\param the width (float)
	*/
	void setWidth(float);

	float getTop() const;
	float getBottom() const;
	float getLeft() const;
	float getRight() const;

	/*!
		Set the top position of the rectangle
		\param the top (float)
	*/
	float setTop(float);
	/*!
		Set the bottom position of the rectangle
		\param the bottom (float)
	*/
	float setBottom(float);
	/*!
		Set the left position of the rectangle
		\param the left (float)
	*/
	float setLeft(float);
	/*!
		Set the right position of the rectangle
		\param the right (float)
	*/
	float setRight(float);

	/*!
		Checks to see if the rectangle contains a point
		\param the point (Vector2f) to check
		\return true if the point is in the rectangle (bool)
	*/
	bool containsPoint(Vector2f);

	/*!
		Checks to see if this rectangle overlaps with another
		\param the rectangle (Rect&) to check
		\return true if they overlap (bool)
	*/
	bool overlaps(Rect const&);
};

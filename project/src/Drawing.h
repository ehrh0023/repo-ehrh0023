#include "Color.h"
#include "Vector2.h"
#include "Rect.h"
#include <string>

/*! This namespace holds the drawing functions for rendering the entities. */
namespace Drawing
{
	/*! Draw a circle
		\param position the position of the circle in pixels (Vector2f)
		\param radius the radius of the circle in pixels (float)
		\param color the color of the circle (Color)
	*/
	void drawCircle(Vector2f position, float radius, Color color);

	/*! Draw a line
	\param start the beginning point of the line (Vector2f)
	\param end the ending point of the line (Vector2f)
	\param color the color of the line (Color)
	\param lineWidth  (optional) the width of the line (float)
	*/
	void drawLine(Vector2f start, Vector2f end, Color color, float lineWidth);

	/*! Draw a rectangle
		\param the rectangle to be drawn (Rect&)
		\param color the color of the rectangle (Color)
	*/
	void drawRectangle(Rect& rectangle, Color color);


	void drawText(Vector2f position, std::string s);

	/*! Get the window width
		\return The window width (int)
	*/
	int getWindowWidth();
	/*! Get the window height
		\return The window height (int)
	*/
	int getWindowHeight();
}

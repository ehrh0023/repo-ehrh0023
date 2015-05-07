#include "Drawing.h"
#include <GL/glui.h>

/*!
	\brief A place to hold the render function.
	\author David Tran
*/

namespace Drawing{
	void drawCircle(Vector2f position, float radius, Color color)
	{
		glColor3f(color.red, color.green, color.blue);
		const GLfloat twoPI = (GLfloat) 6.28318530718;
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f((GLfloat)position.x, (GLfloat)position.y);
		for (int i = 0; i <= 20; i++)
		{
			glVertex2f(position.x + (radius * cos(i * twoPI / 20)),
				position.y + (radius * sin(i * twoPI / 20)));
		}

		glEnd();
	}

	// Author: Dennis Ehrhardt
	void drawLine(Vector2f start, Vector2f end, Color color, float lineWidth = 4)
	{
		glLineWidth(lineWidth);
		glColor3f(color.red, color.green, color.blue);
		glBegin(GL_LINES);
		glVertex3f(start.x, start.y, 0.0);
		glVertex3f(end.x, end.y, 0.0);
		glEnd();
	}

	void drawRectangle(Rect& rectangle, Color color)
	{
		glColor3f(color.getRed(), color.getGreen(), color.getBlue()); // sets color to black.
		glBegin(GL_QUADS);
			glVertex2f(rectangle.getLeft(), rectangle.getTop()); // vertex 1
			glVertex2f(rectangle.getRight(), rectangle.getTop()); // vertex 2
			glVertex2f(rectangle.getRight(), rectangle.getBottom()); // vertex 3
			glVertex2f(rectangle.getLeft(), rectangle.getBottom()); // vertex 4
		glEnd();
	}

	void drawText(Vector2f position, std::string s)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		glRasterPos3f(position.x, position.y, 0); // location to start printing text
		for (int i = 0; i < s.size(); i++) 
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
		}
	}

	// Author: Dennis Ehrhardt
	int getWindowWidth()
	{
#ifdef __cxxtest__TestSuite_h__
		return 800;
#else
		return glutGet(GLUT_WINDOW_WIDTH);
#endif
	}

	// Author: Dennis Ehrhardt
	int getWindowHeight()
	{
#ifdef __cxxtest__TestSuite_h__
		return 800;
#else
		return glutGet(GLUT_WINDOW_HEIGHT);
#endif
	}
}
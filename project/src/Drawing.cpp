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
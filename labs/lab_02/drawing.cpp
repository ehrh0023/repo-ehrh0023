/*
 *  drawing.cpp
 *  myglutsample
 *
 *  Created by Amy Larson on 8/18/12.
 *  Copyright 2012 Chafee Family. All rights reserved.
 *
 */

// complete the preprocessor directives

#include

#define PI 3.14f

/* 
 The drawObject struct is used only internally to this file.
 Objects created with the Shape class, are converted to this struct,
 which stores things in specific GLUT types.
 
 A global array of these structs (myObjects) stores all objects
 to be drawn in each drawing loop. A max of 3 objects can be created.
 */
struct drawObject {
	int type;
	GLfloat loc[2];
	GLfloat size;
	GLfloat color[3];
};
int numOfObjects = 0;
drawObject myObjects[6];

void drawSquare(drawObject square);
void drawCircle(drawObject circle);
void drawTriangle(drawObject triangle);

/* This function is the connection to the code that students
 are writing. They establish the shapes, then send this info
 to the drawing program to set up the shapes for glut. 
 -- Inside the Shapes class, this function is declared as a friend.
 */
void initObject (Shapes object) 
{
	// Don't go past the array!
	if (6<=numOfObjects) {
		return;
	}
	
	//Initialize the RGB colors to 0
	myObjects[numOfObjects].color[0] = 0.0f;
	myObjects[numOfObjects].color[1] = 0.0f;
	myObjects[numOfObjects].color[2] = 0.0f;
	
	// Set color. Default is red.
	switch (object.color) {
		case 'R':
			myObjects[numOfObjects].color[0] = 1.0f;
			break;
		case 'G':
			myObjects[numOfObjects].color[1] = 1.0f;
			break;
		case 'B':
			myObjects[numOfObjects].color[2] = 1.0f;
			break;
		default:
			myObjects[numOfObjects].color[0] = 1.0f;
			break;
	}
	
	// Set other relevant values ...
	myObjects[numOfObjects].type = object.shape;
	myObjects[numOfObjects].loc[0] = (GLfloat) object.location[0];
	myObjects[numOfObjects].loc[1] = (GLfloat) object.location[1];
	myObjects[numOfObjects].size = (GLfloat) object.size;

	++numOfObjects;
}

void display(void)
{
	// This function is called at each glutMainLoop.
	// It draws each object each time.
	int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	for (i=0; i<numOfObjects; i++) {
		switch (myObjects[i].type) {
			case square:
				drawSquare(myObjects[i]);
				break;
			case circle:
				drawCircle(myObjects[i]);
				break;
			case triangle:
				drawTriangle(myObjects[i]);
				break;
			default:
				break;
		}
	}
	glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void idle(void)
{
    glutPostRedisplay();
}

int runGlut()
{
	// Once objects are initialized, main() can
	// call runGlut() to display everything.
	
	//glutInit(&argc, argv); This function call has to be in main()
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    
    glutCreateWindow("GLUT Program");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
	
    glutMainLoop();
    return EXIT_SUCCESS;
}

void drawTriangle(drawObject triangle)
{
	// Store the current matrix, move to the location of the object, 
	// and rotate so square becomes triangle.
	glPushMatrix();
	glTranslatef(triangle.loc[0], triangle.loc[1], 0.0f);
	glPushMatrix();
	glRotatef(45.0f, 0.0f, 0.0f, 10.0f);
	// draw the square/triangle ...
	glBegin(GL_QUADS);
	glColor3f(triangle.color[0], triangle.color[1], triangle.color[2]);
	glVertex2f(  0.0f,   0.0f);
    glVertex2f(triangle.size,   0.0f);
    glVertex2f(triangle.size, triangle.size);
    glVertex2f(  0.0f, triangle.size);
    glEnd();
	// go back to starting matrix
	glPopMatrix();
	glPopMatrix();
}

void drawSquare(drawObject square) 
{
	glPushMatrix();
	glTranslatef(square.loc[0], square.loc[1], 0.0f);
	glBegin(GL_QUADS);
	glColor3f(square.color[0], square.color[1], square.color[2]);
	glVertex2f(  0.0f,   0.0f);
    glVertex2f(square.size,   0.0f);
    glVertex2f(square.size, square.size);
    glVertex2f(  0.0f, square.size);
    glEnd();
	glPopMatrix();
}

void drawCircle(drawObject circle) {
	int i;
	
	glPushMatrix();
	glTranslatef(circle.loc[0], circle.loc[1], 0.0f);
	
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(circle.color[0], circle.color[1], circle.color[2]);
	glVertex2f(0.0f,0.0f);
	for(i = 0; i <= 100; i++) {
		glVertex2f(
				   (circle.size * cos(i * 2.0*3.14 / 20.0)),
				   (circle.size * sin(i * 2.0*3.14 / 20.0))
				   );
	}
	glEnd();
	glPopMatrix();
}


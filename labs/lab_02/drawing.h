/*
 *  drawing.h
 *  myglutsample
 *
 *  Created by Amy Larson on 8/18/12.
 *
 */


#include <GL/glut.h>
#include <GL/glu.h>

// Complete the preprocessor directives ..

#include 

// DECLARATIONS OF FUNCTIONS DEFINED IN drawing.cpp

// Once an object has been established,
// you can send it to the drawing program using this function
void initObject(Shapes shapeObject);

// Once all objects have been established and initialized with 
// the drawing program, call this function to display everything.
int runGlut();


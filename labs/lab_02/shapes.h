/*
 *  shapes.h
 *  myglutsample
 *
 *  Created by Amy Larson on 8/18/12.
 *
 */

// complete the preprocessor directives

#include 

// DEFINITION of a new enumerated type.
// I meant "diamond" instead of "triangle". Leaving it as is.
enum ShapeType {
	square,
	circle,
	triangle,
};

// DECLARATION of the class Shapes. Methods are DEFINED in shapes.cpp

// This class stores information about each shape that the user wants displayed. 
class Shapes
{
private: 

	ShapeType shape;
	char color;			// color should be 'R' 'G' or 'B'

	// The size and location are specified in pixels. The GLUT window is defined as 640x480.
	// These values should be reasonable with respect to the window size.
	int size;
	int location[2];

public:
	// constructors

	// This is the default constructor. It requires no parameters.
	// All private members above are set to default values.
	// You define an object using this constructor with "Shapes shapeObj;"  
	Shapes();

	// This is an alternate way to create a Shapes object.
	// The user defines all private members above except location.
	// Here is an example of how to define an object 
	//     using this constructor "Shapes shapeObj(square,30,'R');"
	Shapes(ShapeType shapeIn, int sizeIn, char colorIn);

	// modifiers
	void setLocation(int x, int y);
	
	// methods
	void displayInfo();
	void draw();
	
	// By making initObject() a "friend", it can access the private information above.
	// initObject() is defined in drawing.cpp. 
	friend void initObject(Shapes shapeObject);
};

// here's a clue about the preprocessor directives that are needed to compile this project ...
#endif

/*
 *  shapes.cpp
 *  myglutsample
 *
 *  Created by Amy Larson on 8/18/12.
 *
 */

// Fill in any necessary preprocessor directives ...


Shapes::Shapes()
{
  // This is the default constructor, which is called when there are no parameters.
  // Rewrite this so that all features are set randomly
  // note the use of rand() in the following constructor.
	shape = circle;
	size = 100;
	color = 'R';
	location[0] = 300;
	location[1] = 200;
}

Shapes::Shapes(ShapeType shapeIn, int sizeIn, char colorIn)
{
  // This constructor is called if 3 parameters are passed in.
	shape = shapeIn;
	size = sizeIn;
	color = colorIn;

	// set x-y location to a random value between {0-600,0-450} 
	location[0] = rand() % 600;
	location[1] = rand() % 450;
}

void Shapes::setLocation(int x, int y)
{
  // This modifies the location member
	location[0] = x;
	location[1] = y;
}
	
void Shapes::displayInfo()
{
  // Modify this method to textually display all member values of this shape.
	cout << "Display the type, color, size, and location of this object." << endl;
}

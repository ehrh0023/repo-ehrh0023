// NAME:
// Student ID:

// PARTNERS NAME:
//

// Fill in the preprocessor directives as needed

#include 

int main(int argc, char** argv)
{
  // Put code here to process argc and argv parameters.

  // The first hard-coded object. It is a circle, with radius 10, color Red.
  // It is located at {50,50}: those are pixel values with respect to the graphics window.
  Shapes object1( circle, 10, 'R');
  object1.setLocation( 50, 50 );
  initObject( object1 );
  object1.displayInfo();

  // The 2nd hard-coded object of class Shapes
  Shapes object2( square,  75, 'G' );
  object2.setLocation( 300, 100 );
  initObject(object2);
  object2.displayInfo();

  // The 3rd hard-coded object
  Shapes object3( triangle, 125, 'B' );
  object3.setLocation( 500, 300 );
  initObject(object3);
  object3.displayInfo();

  // This will print out okay...
  cout << "before glut" << endl;

  // Don't change these 2 lines of code!!
  glutInit(&argc, argv);
  runGlut();

  // This will never print, because control has gone to GLUT
  cout << "after glut" << endl;
}


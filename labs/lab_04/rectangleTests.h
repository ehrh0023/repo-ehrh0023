#include <cxxtest/TestSuite.h>

#include "rectangle.h"

using namespace std;

class RectangleTests : public CxxTest::TestSuite 
{
 public:
  void Test_Area(void){
    // This test tests functionality of int Rectangle::getArea()

    // Create a rectangle object to test

    // Test to ensure the object has the correct area
  }
  
  void Test_ContainsPoint_Inside(void){
    // This test tests functionality of bool Rectangle::contains(int,int)
    // The point is contained inside the rectangle and not on the border

    // Create a rectangle object to test

    // Tests  
  }

  void Test_ContainsPoint_Border(void){
    // This test tests functionality of bool Rectangle::contains(int,int)
    // The point is on the border

    // Create a rectangle object to test

    // Tests  
  }

  void Test_ContainsRectangle_AllInside(void){
    // This test tests functionality of bool Rectangle::contains(Rectangle)
    // The rectangle passed as a parameter is inside the rectangle with no shared border  

    // Create two rectangle objects

    // Tests 
  }

};

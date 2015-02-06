#include "rectangle.h"




Rectangle::Rectangle(int x,int y,int width,int height){
  _x =x;
  _y =y;
  this->_width = width; //example if fields are the same name as local scope.
  _height = height;
}


/*Returns true if the coordinate(x,y) is inside or on the boundary of this rectangle.
 *
 *@Param x the x param of the coordinate being checked 
 *@Param y the y param of the coordinate being checked 
 *
 */
bool Rectangle::contains(int x, int y){
  if(x<_x || x>_x+_width){
    return false;
  }else if(y<_y || y>_y+_height){
    return false;
  }
  return true;
}            

/*Returns true if all corners of r2 are inside or on the boundary of this rectangle.
 *
 *@Param r2 a rectange that is checked 
 *
 */
bool Rectangle::contains(Rectangle const &r2){
  //TODO 
  return false; 
}

//returns width * height 
int Rectangle::getArea(){
  return -1;//TODO
}

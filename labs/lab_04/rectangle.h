#ifndef RectangleParty
#define RectangleParty

class Rectangle{
 public:
  Rectangle(int,int,int,int);
  bool contains(int x, int y); //point
  bool contains(Rectangle const &r2); //rectangle
  int getArea();
 private:
  int _x;
  int _y;
  int _width;
  int _height;
};

#endif

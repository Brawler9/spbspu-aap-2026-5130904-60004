#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Diamond.hpp"


namespace pechnikov
{
  void printinf(Shape** shapes, int n)
  {
    rectangle_t firstFrame = shapes[0]->getFrameRect();

    double xmin = firstFrame.pos.x - firstFrame.width / 2.0;
    double xmax = firstFrame.pos.x + firstFrame.width / 2.0;
    double ymin = firstFrame.pos.y - firstFrame.height / 2.0;
    double ymax = firstFrame.pos.y + firstFrame.height / 2.0;

    double SumArea = 0.0;
    for (int i = 0; i < n; i++)
    {
      std::cout << "Shape #" << i + 1 << "\n";
      std::cout << "Area: " << shapes[i]->getArea() << "\n";
      SumArea += shapes[i]->getArea();
      rectangle_t frame = shapes[i]->getFrameRect();
      std::cout << "Frame: width " << frame.width
      << ", height " << frame.height
      << ", pos(" << frame.pos.x << ", " << frame.pos.y << ")\n";

      double left = frame.pos.x - frame.width / 2.0;
      double right = frame.pos.x + frame.width / 2.0;
      double bottom = frame.pos.y - frame.height / 2.0;
      double top = frame.pos.y + frame.height / 2.0;

      if (left < xmin)   xmin = left;
      if (right > xmax)  xmax = right;
      if (bottom < ymin) ymin = bottom;
      if (top > ymax)    ymax = top;
    }
    std::cout << "Summary Area: " << SumArea << "\n";
    std::cout << "all width = " << xmax - xmin
    std::cout << ", all height = " << ymax - ymin
    std::cout << ", all pos(" << (xmax + xmin) / 2 << ", " << (ymax + ymin) / 2 << ")\n";
  }

  void niceshape(Shape* shape, point_t tochka, double k)
  {
    rectangle_t rec = shape->getFrameRect();
    point_t oldpos = rec.pos;
    double dx = tochka.x - oldpos.x;
    double dy = tochka.y - oldpos.y;

    shape->scale(k);

    shape->move({ oldpos.x + dx - k * dx,oldpos.y + dy - k * dy });
  }

  void niceshapes(Shape* const* shapes, point_t tochka, double k, int n)
  {
    for (int i = 0; i < n; i++)
    {
      niceshape(shapes[i], tochka, k);
    }
  }
}

int main()
{
  const int n = 3;
  pechnikov::Shape* shapes[n] = {};
  try
  {
    shapes[0] = new pechnikov::Rectangle{ 3.1,5.0,{0.0,0.0} };
    shapes[1] = new pechnikov::Diamond{ 10.0,7.0,{1.0,6.0} };
    shapes[2] = new pechnikov::Circle{ 13.0, {5.0,6.0} };
    pechnikov::printinf(shapes, n);
    double cx, cy, k;
    if (!(std::cin >> cx >> cy >> k))
    {
      throw std::invalid_argument("incorrect argument");
    }
    if (k <= 0.0)
    {
      throw std::invalid_argument("Invalid koef");
    }
    pechnikov::point_t tochka{ cx,cy };
    pechnikov::niceshapes(shapes, tochka, k, n);
    pechnikov::printinf(shapes, n);
  }
  catch (const std::exception& err)
  {
    std::cerr << err.what();
    for (int i = 0; i < n; i++)
    {
      delete shapes[i];
    }
    return 1;
  }
  for (int i = 0; i < n; i++)
  {
    delete shapes[i];
  }
}


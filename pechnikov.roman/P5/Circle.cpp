#include "Circle.hpp"
#include <stdexcept>
pechnikov::Circle::Circle(double r, pechnikov::point_t p) : radius(r), pos(p)
{
  if (r <= 0.0)
  {
    throw std::invalid_argument("Circle: invalid radius");
  }
}
double pechnikov::Circle::getArea() const
{
  return 3.14159 * radius * radius;
}
pechnikov::rectangle_t pechnikov::Circle::getFrameRect() const
{
  double width = 2 * radius;
  double height = 2 * radius;
  return { width, height, pos };
}
void pechnikov::Circle::move(const pechnikov::point_t& p)
{
  pos = p;
}
void pechnikov::Circle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
void pechnikov::Circle::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Invalid koef");
  }
  radius *= k;
}

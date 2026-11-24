#include "Rectangle.hpp"
#include <stdexcept>

pechnikov::Rectangle::Rectangle(double w, double h, pechnikov::point_t p) : width{ w }, height{ h }, pos{ p }
{
  if (w <= 0.0 || h <= 0.0)
  {
    throw std::invalid_argument("Rectangle: sides must be positive");
  }
}
double pechnikov::Rectangle::getArea() const
{
  return width * height;
}
pechnikov::rectangle_t pechnikov::Rectangle::getFrameRect() const
{
  return { width, height, pos };
}
void pechnikov::Rectangle::move(const pechnikov::point_t& p)
{
  pos = p;
}
void pechnikov::Rectangle::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
void pechnikov::Rectangle::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Invalid koef");
  }
  width *= k;
  height *= k;
}

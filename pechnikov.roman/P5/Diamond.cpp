#include "Diamond.hpp"
#include <stdexcept>
pechnikov::Diamond::Diamond(double x, double y, pechnikov::point_t p) : diagX(x), diagY(y), pos(p)
{
  if (diagX <= 0.0 || diagY <= 0.0)
  {
    throw std::invalid_argument("Diamond: Invalid len diagonali");
  }
}

double pechnikov::Diamond::getArea() const
{
  return 0.5 * diagX * diagY;
}
pechnikov::rectangle_t pechnikov::Diamond::getFrameRect() const
{
  double width = diagX;
  double height = diagY;
  return { width, height, pos };
}
void pechnikov::Diamond::move(const pechnikov::point_t& p)
{
  pos = p;
}
void pechnikov::Diamond::move(double dx, double dy)
{
  pos.x += dx;
  pos.y += dy;
}
void pechnikov::Diamond::scale(double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("Invalid koef");
  }
  diagX *= k;
  diagY *= k;
}

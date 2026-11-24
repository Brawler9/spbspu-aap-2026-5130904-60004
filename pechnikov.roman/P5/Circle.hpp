#pragma once

#include "shape.hpp"


namespace pechnikov
{
  class Circle :public Shape
  {
    double radius;
    point_t pos;
  public:
    Circle(double r, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

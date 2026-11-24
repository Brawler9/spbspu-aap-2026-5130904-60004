#pragma once

#include "shape.hpp"

namespace pechnikov
{
  class Rectangle :public Shape
  {
  private:
    double width, height;
    point_t pos;
  public:
    Rectangle(double w, double h, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

#include "shape2d.h"
#include <string.h>
#include <vector>
#include <math.h>
#include <iostream>



Shape2D::Shape2D(const std::vector<Point2D>& vp2d, const std::string& name, ColorRGB* color): Shape(name, color), points(vp2d)
{

}



bool Shape2D::operator ==(const Shape &s) const
{
    if(Shape::operator ==(s))
    {
        const Shape2D& s2d = static_cast<const Shape2D&>(s);
        if(points == s2d.getPoints())
        {
            return true;
        }
    }
    return false;
}


unsigned int Shape2D::getNumberSide() const
{
    return points.size();
}



unsigned int Shape2D::getNumberVertex() const
{
    return points.size();
}

void Shape2D::translate(const Point2D& p)
{
    for(std::vector<Point2D>::iterator it = points.begin(); it != points.end(); ++it)
    {
        (*it).setX(p.getX() +(*it).getX());
        (*it).setY(p.getY() + (*it).getY());
    }
}

const std::vector<Point2D>& Shape2D::getPoints() const
{
    return points;
}

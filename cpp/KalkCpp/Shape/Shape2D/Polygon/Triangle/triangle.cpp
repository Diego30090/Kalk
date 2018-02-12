#include "triangle.h"



Triangle::Triangle(const std::vector<Point2D>& vp2d, const std::string& name, ColorRGB* color): Polygon(vp2d, name, color)
{

}


bool Triangle::isTriangle(double a, double b, double c)
{
    if ( a < 0 && b < 0 && c < 0)
        return false;

    if (a < (b + c) && b < (a + c) && c < (a + b))
         return true;

    return false;
}


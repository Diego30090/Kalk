#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../polygon.h"

class Triangle : public Polygon
{
public:
    /**
        Constructor for Triangle with 3 params: points, Triangle's name and color

        @param vp2d The vector of points for the Triangle
        @param name The name for the Triangle
        @param color The color for the Triangle (default is (0,0,0)
    */
    Triangle(const std::vector<Point2D>&, const std::string&, ColorRGB* = new ColorRGB());

    /**
        Static function that return true if the given sides can build a triangle
        false otherwise
        @return (bool) possibility to build a tringle
    */
    static bool isTriangle(double, double, double);
};

#endif // TRIANGLE_H

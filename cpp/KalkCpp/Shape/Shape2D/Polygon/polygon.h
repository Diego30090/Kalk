#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <string.h>
#include "../../../Color/colorrgb.h"
#include "../shape2d.h"

class Polygon : public Shape2D
{
public:
    /**
        Constructor for Polygon with 3 params: points, Polygon's name and color

        @param vp2d The vector of points for the Polygon
        @param name The name for the Polygon
        @param color The color for the Polygon (default is (0,0,0)
    */
    Polygon(const std::vector<Point2D>&, const std::string&, ColorRGB* = new ColorRGB());


    /**
        Function to get the perimeter of the Polygon

        @return The perimeter of the Polygon
    */
    virtual double perimeter() const;

    /**
        Function to get the area of the Polygon

        @return The area of the Polygon
    */
    virtual double area() const =0;

    /**
        Function to get the base of the Polygon

        @return The base of the Polygon
    */
    virtual double base() const =0;

    /**
        Function to get the height of the Polygon

        @return The height of the Polygon
    */
    virtual double height() const =0;

    /**
        Function to get the area of the Polygon using the Gauss Algorithm

        @param The area of the Polygon
        @return The area of the Polygon
    */
    static double gaussArea(const std::vector<Point2D>&);
};

#endif // POLYGON_H

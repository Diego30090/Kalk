#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include <string.h>
#include "Color/colorrgb.h"
#include "../point2d.h"
#include "shape2d.h"

class Circle : public Shape2D
{
private:
    /**
        Function that build a circle from the ray

        @return The points of the circle (contains center and ray)
    */
    std::vector<Point2D> buildCircle(double) const;

    /**
        Function that controls if the build of a circle with given parameters is possible
        true if it is possible, false otherwise

        @param sideLength The ray Length for the Circle
        @return(bool) Possibility to build the circle
    */
    bool canBuild(double) const;

    /**
        Function that controls if the build of a circle with given parameters is possible
        true if it is possible, false otherwise

        @param sideLength The ray Length for the Circle
        @return(bool) Possibility to build the circle
    */
    bool canBuild(const std::vector<Point2D>&) const;
public:
    /**
        Constructor for Circle with 3 params

        @param vp2d The points to use for the circle
        @param name The name of the shape (by default is a "circle")
        @param color The color of the shape (by deafult (0,0,0))
    */
    Circle(const std::vector<Point2D>&, ColorRGB* = new ColorRGB());

    /**
        Constructor for Circle with 3 params

        @param ray The ray to use for create the circle
        @param name The name of the shape (by default is a "circle")
        @param color The color of the shape (by deafult (0,0,0))
    */
    Circle(double, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new circle from an existing one
     *
     * @return a new circle that is a copy of the current one
     */
    Circle* clone() const;

    /**
        Difference operator for Circle

        @param c the (second) Circle to use
        @return a new Circle that is the difference between the two Circles
    */
    Circle* operator-(const Shape2D& ) const;

    /**
        Sum operator for Circle

        @param c the (second) Circle to use
        @return a new Circle that is the sum between the two Circles
    */
    Circle* operator+(const Shape2D& ) const;

    /**
        Multiply operator for Circle

        @param c the (second) Circle to use
        @return a new Circle that is the multiplication between the two Circles
    */
     Circle* operator*(const Shape2D& ) const;

    /**
        Division operator for Circle

        @param s the (second) Circle to use
        @return a new Circle that is the division between the two Circles
    */
    Circle* operator/(const Shape2D& ) const;

    /**
        Function that return the ray of the circle

        @return The circle's ray
    */
    double ray() const;
	
    /**
        Function that return a side value that will used in operators

        @return The side value of the Circle (the Ray)
    */
    double sideToOperator() const;

    /**
        Function that return the diameter of the circle

        @return The circle's diameter
    */
    double diameter() const;

    /**
        Function that return the area of the circle

        @return The area of the circle
    */
    double area() const;
	
    /**
        Function that return the circumference of the circle

        @return The circumference of the circle
    */
    double circumference() const;

};

#endif // CIRCLE_H

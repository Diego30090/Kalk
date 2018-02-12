#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>
#include <string.h>
#include "../../../../Color/colorrgb.h"
#include "../../../point2d.h"
#include "quadrilateral.h"

class Rectangle : public Quadrilateral
{
private:
    /**
        Function that build a Rectangle from the two sides(origin is in (0,0)

        @param sideLength The first side length for the Rectangle
        @param sideLength The second side length for the Rectangle
        @return The points of the new Rectangle
    */
    std::vector<Point2D> buildRectangle(double, double) const;

    /**
        Function that controls if the build of a rectangle with given parameters is possible
        true if it is possible, false otherwise

        @param baseLength The base Length for the Rectangle
        @param heightLength The base Height for the Rectangle
        @return(bool) Possibility to build the rectangle
    */
    bool canBuild(double, double) const;


    /**
        Function that controls if the build of a rectangle with given parameters is possible
        true if it is possible, false otherwise

        @param baseLength The base Length for the Rectangle
        @param heightLength The base Height for the Rectangle
        @return(bool) Possibility to build the rectangle
    */
    bool canBuild(const std::vector<Point2D>&) const;
public:
    /**
        Constructor for Rectangle with 3 params: points, Rectangle's name and color

        @param vp2d The vector of points for the Rectangle
        @param name The name for the Rectangle (By default is "Rectangle")
        @param color The color for the Rectangle (By default create a simple ColorRGB (0,0,0))
    */
    Rectangle(const std::vector<Point2D>&, ColorRGB* = new ColorRGB());

    /**
        Constructor for Rectangle with 4 params: first side, second side, Rectangle's name and color

        @param sideLength The first  side Length for the Rectangle
        @param sideLength The second side Length for the Rectangle
        @param name The name for the Rectangle (By default is "Rectangle")
        @param color The color for the Rectangle (By default create a simple ColorRGB (0,0,0))
    */
    Rectangle(double, double, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new Rectangle from an existing one
     *
     * @return a new Rectangle that is a copy of the current one
     */
    Rectangle* clone() const;

    /**
        Difference operator for Rectangle

        @param r the (second) Shape to use
        @return a new Rectangle that is the difference between the Rectangle and the Shape
    */
    Rectangle* operator-(const Shape2D&) const;

    /**
        Sum operator for Rectangle

        @param r the (second) Shape to use
        @return a new Rectangle that is the sum between the Rectangle and the Shape
    */
    Rectangle* operator+(const Shape2D&) const;

    /**
        Multiply operator for Rectangle

        @param r the (second) Shape to use
        @return a new Rectangle that is the multiplication between the Rectangle and the Shape
    */
    Rectangle* operator*(const Shape2D&) const;

    /**
        Division operator for Rectangle

        @param r the (second) Shape to use
        @return a new Rectangle that is the division between the Rectangle and the Shape
    */
    Rectangle* operator/(const Shape2D&) const;

    /**
        Function that return the area of the Rectangle

        @return The area of the Rectangle
    */
    double area() const;

    /**
        Function that return the base of the Rectangle

        @return The base of the Rectangle
    */
    double base() const;

    /**
        Function that return the height of the Rectangle

        @return The height of the Rectangle
    */
    double height() const;

    /**
        Function that return the diagonal of the Rectangle

        @return The diagonal of the Rectangle
    */
    double diagonal() const;
	
    /**
        Function that return a side value that will used in operators

        @return The side value of the rectangle (the base)
    */
    double sideToOperator() const;

};

#endif // RECTANGLE_H

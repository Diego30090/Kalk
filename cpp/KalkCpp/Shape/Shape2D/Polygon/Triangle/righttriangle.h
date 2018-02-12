#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "triangle.h"

class RightTriangle : public Triangle
{
private:
    /**
        Function that build a RightTriangle from the two side values(origin is in (0,0)

        @param cathetusMax The bigger cathetus length
        @param cathetusMin The shorter cathetus length
        @return The points of the new RightTriangle
    */
    std::vector<Point2D> buildRightTriangle(double, double) const;

    /**
        Function that controls if the build of the isoscelesTriangle with given parameters is possible
        true if it is possible, false otherwise

        @param baseLength The base Length for the IsoscelesTriangle
        @param baseLength The side Length for the IsoscelesTriangle (cathetus)

        @return(bool) Possibility to build the square
    */
    bool canBuild(double, double) const;

    /**
        Function that controls if the build of the isoscelesTriangle with given parameters is possible
        true if it is possible, false otherwise

        @param baseLength The base Length for the IsoscelesTriangle
        @param baseLength The side Length for the IsoscelesTriangle (cathetus)

        @return(bool) Possibility to build the square
    */
    bool canBuild(const std::vector<Point2D>&) const;
public:
    /**
        Constructor for RightTriangle with 3 params: points, RightTriangle's name and color

        @param vp2d The vector of points for the RightTriangle
        @param name The name for the RightTriangle (By default is "RightTriangle")
        @param color The color for the RightTriangle (By default create a simple ColorRGB (0,0,0))
    */
    RightTriangle(const std::vector<Point2D>&, ColorRGB* = new ColorRGB());

    /**
        Constructor for RightTriangle with 3 params: base length, sideLength, IsoscelesTriangle's name and color

        @param cathetusMax The bigger cathetus length
        @param cathetusMin The shorter cathetus length
        @param name The name for the IsoscelesTriangle (By default is "IsoscelesTriangle")
        @param color The color for the IsoscelesTriangle (By default create a simple ColorRGB (0,0,0))
    */
    RightTriangle(double, double, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new RightTriangle from an existing one
     *
     * @return a new RightTriangle that is a copy of the current one
     */
    RightTriangle* clone() const;

    /**
        Difference operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the difference between the IsoscelesTriangle and the Shape
    */
    RightTriangle* operator-(const Shape2D&) const;

    /**
        Sum operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the sum between the IsoscelesTriangle and the Shape
    */
    RightTriangle* operator+(const Shape2D&) const;

    /**
        Multiply operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the multiplication between the IsoscelesTriangle and the Shape
    */
    RightTriangle* operator*(const Shape2D&) const;

    /**
        Division operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the division between the IsoscelesTriangle and the Shape
    */
    RightTriangle* operator/(const Shape2D&) const;

    /**
        Function that return the area of the IsoscelesTriangle

        @return The area of the IsoscelesTriangle
    */
    double area() const;
	
    /**
        Function that return a side value that will used in operators

        @return The side value of the RightTriangle (the base)
    */
    double sideToOperator() const;

    /**
        Function that return the hypotenuse size of the RightTriangle

        @return The hypotenuse size of the RightTriangle
    */
    double hypotenuse() const;

    /**
        Function that return the base of the RightTriangle

        @return The base of the RightTriangle
    */
    double base() const;

    /**
        Function that return the height of the RightTriangle

        @return the Height of the RightTriangle
    */
    double height() const;
};

#endif // RIGHTTRIANGLE_H

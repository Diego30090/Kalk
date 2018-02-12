#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "triangle.h"

class IsoscelesTriangle : public Triangle
{
private:
    /**
        Function that build a IsoscelesTriangle from the two side values(origin is in (0,0)

        @param baseLength The base Length for the IsoscelesTriangle
        @param sideLength The height Length for the IsoscelesTriangle
        @return The points of the new IsoscelesTriangle
    */
    std::vector<Point2D> buildIsoscelesTriangle(double, double) const;

    /**
        Function that controls if the build of the isoscelesTriangle with given parameters is possible
        true if it is possible, false otherwise

        @param baseLength The base Length for the IsoscelesTriangle
        @param heightLength The Height Length for the IsoscelesTriangle

        @return(bool) Possibility to build the square
    */
    bool canBuild(double, double) const;

    /**
        Function that controls if the build of the isoscelesTriangle with given parameters is possible
        true if it is possible, false otherwise

        @param baseLength The base Length for the IsoscelesTriangle
        @param heightLength The Height Length for the IsoscelesTriangle

        @return(bool) Possibility to build the square
    */
    bool canBuild(const std::vector<Point2D>&) const;
public:
    /**
        Constructor for IsoscelesTriangle with 3 params: points, IsoscelesTriangle's name and color

        @param vp2d The vector of points for the IsoscelesTriangle
        @param name The name for the IsoscelesTriangle (By default is "IsoscelesTriangle")
        @param color The color for the IsoscelesTriangle (By default create a simple ColorRGB (0,0,0))
    */
    IsoscelesTriangle(const std::vector<Point2D>&, ColorRGB* = new ColorRGB());

    /**
        Constructor for IsoscelesTriangle with 3 params: base length, sideLength, IsoscelesTriangle's name and color

        @param base The base Length for the Square
        @param height The height Length for the Square
        @param name The name for the IsoscelesTriangle (By default is "IsoscelesTriangle")
        @param color The color for the IsoscelesTriangle (By default create a simple ColorRGB (0,0,0))
    */
    IsoscelesTriangle(double, double, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new IsoscelesTriangle from an existing one
     *
     * @return a new IsoscelesTriangle that is a copy of the current one
     */
    IsoscelesTriangle* clone() const;

    /**
        Difference operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the difference between the IsoscelesTriangle and the Shape
    */
    IsoscelesTriangle* operator-(const Shape2D&) const;

    /**
        Sum operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the sum between the IsoscelesTriangle and the Shape
    */
    IsoscelesTriangle* operator+(const Shape2D&) const;

    /**
        Multiply operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the multiplication between the IsoscelesTriangle and the Shape
    */
    IsoscelesTriangle* operator*(const Shape2D&) const;

    /**
        Division operator for IsoscelesTriangle

        @param it the (second) Shape to use
        @return a new IsoscelesTriangle that is the division between the IsoscelesTriangle and the Shape
    */
    IsoscelesTriangle* operator/(const Shape2D&) const;

    /**
        Function that return the height of the IsoscelesTriangle

        @param base The base of the current IsoscelesTriangle
        @param cathetus The side length of the IsoscelesTriangle
        @return The height of the IsoscelesTriangle
    */
    double getHeight(double, double) const;

    /**
        Function that return the area of the IsoscelesTriangle

        @return The area of the IsoscelesTriangle
    */
    double area() const;

    /**
        Function that return a side value that will used in operators

        @return The side value of the IsoscelesTriangle (the base)
    */
    double sideToOperator() const;

    /**
        Function that return the base of the IsoscelesTriangle

        @return The base of the IsoscelesTriangle
    */
    double base() const;

    /**
        Function that return the height of the IsoscelesTriangle

        @return the Height of the IsoscelesTriangle
    */
    double height() const;

    /**
        Function that return the side of the IsoscelesTriangle

        @return the Side of the IsoscelesTriangle
    */
    double side() const;
};

#endif // ISOSCELESTRIANGLE_H

#ifndef SQUARE_H
#define SQUARE_H

#include <vector>
#include <string.h>
#include "../../../../Color/colorrgb.h"
#include "../../../point2d.h"
#include "quadrilateral.h"

class Square : public Quadrilateral
{
private:
    /**
        Function that build a Square from the sideLength(origin is in (0,0)

        @param sideLength The side Length for the Square
        @return The points of the new Square
    */
    std::vector<Point2D> buildSquare(double) const;

    /**
        Function that controls if the build of a square with given parameters is possible
        true if it is possible, false otherwise

        @param sideLength The side Length for the Square
        @return(bool) Possibility to build the square
    */
    bool canBuild(double) const;

    /**
        Function that controls if the build of a square with given parameters is possible
        true if it is possible, false otherwise

        @param sideLength The side Length for the Square
        @return(bool) Possibility to build the square
    */
    bool canBuild(const std::vector<Point2D>&) const;
public:
    /**
        Constructor for Square with 3 params: points, Square's name and color

        @param vp2d The vector of points for the Square
        @param name The name for the Square (By default is "Square")
        @param color The color for the Square (By default create a simple ColorRGB (0,0,0))
    */
    Square(const std::vector<Point2D>&, ColorRGB* = new ColorRGB());

    /**
        Constructor for Square with 3 params: sideLength, Square's name and color

        @param sideLength The side Length for the Square
        @param name The name for the Square (By default is "Square")
        @param color The color for the Square (By default create a simple ColorRGB (0,0,0))
    */
    Square(double, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new Square from an existing one
     *
     * @return a new Square that is a copy of the current one
     */
    Square* clone() const;

    /**
        Difference operator for Square

        @param s the (second) Shape to use
        @return a new Square that is the difference between the Square and the Shape
    */
    Square* operator-(const Shape2D&) const;

    /**
        Sum operator for Square

        @param s the (second) Shape to use
        @return a new Square that is the sum between the Square and the Shape
    */
    Square* operator+(const Shape2D& s) const;

    /**
        Multiply operator for Square

        @param s the (second) Shape to use
        @return a new Square that is the multiplication between the Square and the Shape
    */
    Square* operator*(const Shape2D& s) const;

    /**
        Division operator for Square

        @param s the (second) Shape to use
        @return a new Square that is the division between the Square and the Shape
    */
    Square* operator/(const Shape2D& s) const;

    /**
        Function that return the area of the square

        @return The area of the Square
    */
    double area() const;

    /**
        Function that return a side value that will used in operators

        @return The side value of the square (the base)
    */
    double sideToOperator() const;

    /**
        Function that return the base of the Square

        @return The base of the Square
    */
    double base() const;

    /**
        Function that return the height of the Square

        @return the Height of the Square
    */
    double height() const;

    /**
        Function that return the diagonal of the Square

        @return the diagonal of the Square
    */
    double diagonal() const;

};

#endif // SQUARE_H

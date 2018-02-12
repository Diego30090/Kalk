#ifndef Shape2D_H
#define Shape2D_H

#include <vector>
#include <string.h>
#include "../../Color/colorrgb.h"
#include  "../point2d.h"
#include "../shape.h"

class Shape2D : public Shape
{
protected:
    //The vector (made of Point2D) that contains all the points for a Shape2D
    std::vector<Point2D> points;
public:
    /**
        Constructor for Shape2D with 3 params: points, shape's name and color

        @param vp2d The vector of points for the shape
        @param name The name for the shape
        @param color The color for the shape (By default create a simple ColorRGB (0,0,0))
    */
    Shape2D(const std::vector<Point2D>& vp2d, const std::string& name, ColorRGB* color = new ColorRGB());

    /**
     * Clone() virtual method to create a new shape2d from an existing one
     *
     * @return a new shape2d that is a copy of the current one
     */
    virtual Shape2D* clone() const =0;

    /**
        Equal operator for Shape2D

        @param s2d the (second) Shape to use
        @return (bool) if the invocation Shape2D is equal to s2d
    */
    virtual bool operator==(const Shape &s) const;

    /**
        Difference operator for Shape

        @param s the (second) Shape to use
        @return a new Shape that is the difference between the two Shapes
    */
    virtual Shape2D* operator-(const Shape2D& s) const =0;

    /**
        Sum operator for Shape

        @param s the (second) Shape to use
         @return a new Shape that is the sum between the two Shapes
    */
    virtual Shape2D* operator+(const Shape2D& s) const =0;

    /**
        Multiply operator for Shape

        @param s the (second) Shape to use
        @return a new Shape that is the multiplication between the two Shapes
    */
    virtual Shape2D* operator*(const Shape2D& s) const =0;

    /**
        Division operator for Shape

        @param s the (second) Shape to use
        @return a new Shape that is the division between the two Shapes
    */
    virtual Shape2D* operator/(const Shape2D& s) const =0;

    /**
        Function to get the number of Side of the Shape2D

        @return The number of Side
    */
    virtual unsigned int getNumberSide() const;

    /**
        Function to get the number of Vertex of the Shape2D

        @return The number of vertex
    */
    virtual unsigned int getNumberVertex() const;

    /**
        Function to get the vector of points of the current Shape2D

        @return The points of the current shape
    */
    const std::vector<Point2D>& getPoints() const;

    /**
     * Translate the current shape using the param vector
     *
     * @param p The translation vector for the shape
     */
    void translate(const Point2D& p);
	
    /**
        Function that return a side value that will used in operators

        @return The side value of the Shape
    */
	virtual double sideToOperator() const =0;
};

#endif // Shape2D_H

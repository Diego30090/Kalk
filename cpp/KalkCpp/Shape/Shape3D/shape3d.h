#ifndef SHAPE3D_H
#define SHAPE3D_H

#include <vector>
#include <string.h>
#include "../../Color/colorrgb.h"
#include  "../point3d.h"
#include "../shape.h"
#include "../Shape2D/Polygon/polygon.h"

class Shape3D : public Shape
{

protected:
    //The vector (made of Point3D) that contains all the points for a Shape3D
    std::vector<Point3D> points;
    //Reference to the base Shape of the 3D shape
    Shape2D* baseShape;
    /**
        Function that adjust a vector of Point2D to Point3D
        (Add them in the current points vector)

        @param bs_points The vector of Point2D
    */
    void adjustPoints(const std::vector<Point2D>& bs_points);
public:
    /**
        Constructor for Shape3D with 3 params: points, base polygon, shape's name and color

        @param vp3d The vector of points for the shape
        @param basePolygon The basePolygon of the current shape
        @param name The name for the shape
        @param color The color for the shape (By default create a simple ColorRGB (0,0,0))
    */
    Shape3D(const std::vector<Point3D>&, Shape2D*, std::string, ColorRGB* = new ColorRGB());

    /**
        Copy constructor for Shape3D

        @param s3d the shape to copy
    */
    Shape3D(const Shape3D&);

    /**
        Equal operator for Shape3D

        @param s3d the (second) Shape to use
        @return (bool) if the invocation Shape3D is equal to s3d
    */
    virtual bool operator==(const Shape&) const;

    /**
        Assignment operator for Shape3D

        @param s the (second) Shape3D to use
        @return the Shape3D that received s3d values
    */
    virtual Shape3D& operator=(const Shape3D&);

    /**
        Difference operator for Shape

        @param s the (second) Shape to use
        @return a new Shape that is the difference between the two Shapes
    */
    virtual Shape3D* operator-(const Shape3D& s) const =0;

    /**
        Sum operator for Shape

        @param s the (second) Shape to use
         @return a new Shape that is the sum between the two Shapes
    */
    virtual Shape3D* operator+(const Shape3D& s) const =0;

    /**
        Multiply operator for Shape

        @param s the (second) Shape to use
        @return a new Shape that is the multiplication between the two Shapes
    */
    virtual Shape3D* operator*(const Shape3D& s) const =0;

    /**
        Division operator for Shape

        @param s the (second) Shape to use
        @return a new Shape that is the division between the two Shapes
    */
    virtual Shape3D* operator/(const Shape3D& s) const =0;

    /**
        Function to get the number of vertex of the Shape3D

        @return The number of Vertex
    */
    unsigned int getNumberVertex() const;

    /**
        Function to get the number volume of the Shape3D

        @return The Volume of the current shape
    */
    virtual double volume() const =0;

    /**
        Function to get the total surface that the current Shape3D has

        @return The total surface of the Shape
    */
    virtual double totalSurface() const =0;

    /**
        Function to get a reference of the vector of points

        @return The vector of points of the current Shape
    */
    virtual const std::vector<Point3D>& getPoints() const;

    /**
        Function to get a reference of the current shape

        @return The current base shape of this Shape3D
    */
    const Shape2D* getBaseShape() const;

    /**
        Virtual distructor of the class
    */
    virtual ~Shape3D() =0;
};

#endif // SHAPE3D_H

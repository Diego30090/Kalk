#ifndef CUBE_H
#define CUBE_H

#include "polyhedron.h"
#include "../../Shape2D/Polygon/Quadrilateral/square.h"

class Cube : public Polyhedron
{
private:
    /**
        Function that build a Cube from the base shape (Square)

        @param  baseShape
        @return The points of the new Cube
    */
    std::vector<Point3D> buildCube(Square*) const;
public:
    /**
        Constructor for Cube with 3 params: points, base shape, Cube's name and color

        @param vp3d The vector of points for the Cube
        @param baseShape
        @param name The name for the Square (By default is "Cube")
        @param color The color for the Square (By default create a simple ColorRGB (0,0,0))
    */
    Cube(const std::vector<Point3D>&, Square*, ColorRGB* = new ColorRGB());

    /**
        Constructor for Square with 3 params: sideLength, Square's name and color

        @param sideLength The side Length for the Square
        @param name The name for the Square (By default is "Square")
        @param color The color for the Square (By default create a simple ColorRGB (0,0,0))
    */
    Cube(Square* s, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new Cube from an existing one
     *
     * @return a new Cube that is a copy of the current one
     */
    Cube* clone() const;

    /**
        Difference operator for Cube

        @param c the (second) Shape to use
        @return a new Square that is the difference between the Cube and the Shape
    */
    Cube* operator-(const Shape3D& s) const;

    /**
        Sum operator for Cube

        @param c the (second) Shape to use
        @return a new Square that is the sum between the Cube and the Shape
    */
    Cube* operator+(const Shape3D& s) const;

    /**
        Multiply operator for Cube

        @param c the (second) Shape to use
        @return a new Square that is the multiplication between the Cube and the Shape
    */
    Cube* operator*(const Shape3D& s) const;

    /**
        Division operator for Cube

        @param c the (second) Shape to use
        @return a new Square that is the division between the Cube and the Shape
    */
    Cube* operator/(const Shape3D& s) const;

    /**
        Function that return the number of corner os the Cube

        @return The number of corners
    */
    unsigned int getNumberCorner() const;

    /**
        Function that return the number of faces of the Cube

        @return The number of faces of the the Cube
    */
    unsigned int getNumberFaces() const;

    /**
        Function that return volume of the Cube

        @return The volume of the Cube
    */
    double volume() const;

    /**
        Function that return the lateral surface length of the Cube

        @return The lateral surface length of the Cube
    */
    double lateralSurface() const;

    /**
        Function that return the total surface of the Cube

        @return The total surface of the Cube
    */
    double totalSurface() const;

    /**
        Function that return the diagonal of the Cube

        @return The diagonal length of the Cube
    */
    double diagonal() const;

    /**
        Function that return the side of the Cube

        @return The side length of the Cube
    */
    double side() const;

    /**
        Virtual distructor of the class
    */
    virtual ~Cube();
};

#endif // CUBE_H

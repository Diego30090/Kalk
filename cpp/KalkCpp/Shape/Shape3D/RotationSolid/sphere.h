#ifndef SPHERE_H
#define SPHERE_H

#include "rotationsolid.h"
#include "../../Shape2D/circle.h"

class Sphere : public RotationSolid
{
private:
    /**
        Function that build a Sphere from the base shape (Circle)

        @param  baseShape
        @return The points of the new Sphere
    */
    std::vector<Point3D> buildSphere(Circle*) const;
public:

    /**
        Constructor for Sphere with 3 params: points, base shape, Circle's name and color

        @param vp3d The vector of points for the Sphere
        @param baseShape
        @param name The name for the Circle (By default is "Sphere")
        @param color The color for the Circle (By default create a simple ColorRGB (0,0,0))
    */
    Sphere(const std::vector<Point3D>&, Circle*, ColorRGB* = new ColorRGB());

    /**
        Constructor for Circle with 3 params: sideLength, Circle's name and color

        @param sideLength The side Length for the Circle
        @param name The name for the Circle (By default is "Circle")
        @param color The color for the Circle (By default create a simple ColorRGB (0,0,0))
    */
    Sphere(Circle*, ColorRGB* = new ColorRGB());

    /**
     * Clone() virtual method to create a new Sphere from an existing one
     *
     * @return a new Sphere that is a copy of the current one
     */
    Sphere* clone() const;

    /**
        Difference operator for Sphere

        @param c the (second) Shape to use
        @return a new Circle that is the difference between the Sphere and the Shape
    */
    Sphere* operator-(const Shape3D&) const;

    /**
        Sum operator for Sphere

        @param c the (second) Shape to use
        @return a new Circle that is the sum between the Sphere and the Shape
    */
    Sphere* operator+(const Shape3D&) const;

    /**
        Multiply operator for Sphere

        @param c the (second) Shape to use
        @return a new Circle that is the multiplication between the Sphere and the Shape
    */
    Sphere* operator*(const Shape3D&) const;

    /**
        Division operator for Sphere

        @param c the (second) Shape to use
        @return a new Circle that is the division between the Sphere and the Shape
    */
    Sphere* operator/(const Shape3D&) const;

    /**
        Function that return the ray of the sphere

        @return The sphere's ray
    */
    double ray() const;

    /**
        Function that return the diameter of the sphere

        @return The sphere's diameter
    */
    double diameter() const;

    /**
        Function that return volume of the Sphere

        @return The volume of the Sphere
    */
    double volume() const;

    /**
        Function that return total surface of the Sphere

        @return The total surface of the Sphere
    */
    double totalSurface() const;

    /**
        Function that return circumference of the Sphere

        @return The circumference of the Sphere
    */
    double circumference() const;

};

#endif // SPHERE_H

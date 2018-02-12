#ifndef POLYHEDRON_H
#define POLYHEDRON_H

#include "../../Shape2D/Polygon/polygon.h"
#include "../shape3d.h"

class Polyhedron : public Shape3D
{
public:
    /**
        Constructor for Polyhedron with 3 params: points, base shape, Polyhedron's name and color

        @param vp3d The vector of points for the Polyhedron
        @param baseShape The base shape that will used for the Polyhedron and the Shape3D
        @param name The name for the Polyhedron
        @param color The color for the Polyhedron (default is (0,0,0)
    */
    Polyhedron(const std::vector<Point3D>&, Polygon*, const std::string&, ColorRGB* = new ColorRGB());

    /**
        Function that return the number of corners of the Polyhedron

        @return The number of corners of the Polyhedron
    */
    virtual unsigned int getNumberCorner() const =0;

    /**
        Function that return the number of faces of the Polyhedron

        @return The number of faces of the Polyhedron
    */
    virtual unsigned int getNumberFaces() const =0;

    /**
        Function that return the lateral surface length of the Polyhedron

        @return The lateral surface length of the Polyhedron
    */
    virtual double lateralSurface() const =0;

};

#endif // POLYHEDRON_H

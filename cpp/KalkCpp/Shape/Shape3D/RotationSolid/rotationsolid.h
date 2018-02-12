#ifndef ROTATIONSOLID_H
#define ROTATIONSOLID_H


#include "../../Shape2D/Polygon/polygon.h"
#include "../shape3d.h"

class RotationSolid : public Shape3D
{

public:
    /**
        Constructor for RotationSolid with 3 params: points, base shape, Polyhedron's name and color

        @param vp3d The vector of points for the RotationSolid
        @param baseShape The base shape that will used for the RotationSolid and the Shape3D
        @param name The name for the RotationSolid
        @param color The color for the RotationSolid (default is (0,0,0)
    */
    RotationSolid(const std::vector<Point3D>& vp3d, Shape2D* baseShape, const std::string& name, ColorRGB* color = new ColorRGB());


};

#endif // ROTATIONSOLID_H

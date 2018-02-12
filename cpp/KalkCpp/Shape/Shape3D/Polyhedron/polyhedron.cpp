#include "polyhedron.h"



Polyhedron::Polyhedron(const std::vector<Point3D>& vp3d, Polygon* bs, const std::string& name, ColorRGB* color):
    Shape3D(vp3d, bs, name, color)
{

}



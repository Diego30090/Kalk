#include "cube.h"
#include "math.h"
#include "algorithm"
#include "../../Shape2D/Polygon/Quadrilateral/square.h"



Cube::Cube(const std::vector<Point3D>& vp3d, Square* bs, ColorRGB* color): Polyhedron(vp3d, bs, "Cube", color)
{

}


Cube* Cube::clone() const
{
    return new Cube(*this);
}

std::vector<Point3D> Cube::buildCube(Square* s) const
{
    std::vector<Point3D> points = std::vector<Point3D>();

    for(std::vector<Point2D>::const_iterator it = s->getPoints().begin(); it != s->getPoints().end(); ++it)
    {
        points.push_back(Point3D::p2dTop3d(*it));
    }

    for(std::vector<Point2D>::const_iterator it = s->getPoints().begin(); it != s->getPoints().end(); ++it)
    {
        Point2D p = *it;
        points.push_back(Point3D(p.getX(), p.getY(), s->base()));
    }

    return points;
}



Cube::Cube(Square* bs, ColorRGB* color): Polyhedron(buildCube(bs), bs, "Cube", color)
{

}



Cube* Cube::operator-(const Shape3D& s) const
{
    Square* newbaseShape = static_cast<Square*>(baseShape)->operator -(*s.getBaseShape());
    Cube* newCube = new Cube(buildCube(newbaseShape),newbaseShape, getColor()->operator -(*s.getColor()));
    return newCube;
}



Cube* Cube::operator+(const Shape3D& s) const
{
    Square* newbaseShape = static_cast<Square*>(baseShape)->operator +(*s.getBaseShape());
    Cube* newCube = new Cube(buildCube(newbaseShape),newbaseShape, getColor()->operator +(*s.getColor()));
    return newCube;
}



Cube* Cube::operator*(const Shape3D& s) const
{
    Square* newbaseShape = static_cast<Square*>(baseShape)->operator *(*s.getBaseShape());
    Cube* newCube = new Cube(buildCube(newbaseShape),newbaseShape, getColor()->operator *(*s.getColor()));
    return newCube;
}



Cube* Cube::operator/(const Shape3D& s) const
{
    Square* newbaseShape = static_cast<Square*>(baseShape)->operator /(*s.getBaseShape());
    Cube* newCube = new Cube(buildCube(newbaseShape),newbaseShape, getColor()->operator /(*s.getColor()));
    return newCube;
}



unsigned int Cube::getNumberCorner() const
{
    return 12;
}



unsigned int Cube::getNumberFaces() const
{
    return getNumberCorner() / 2;
}



double Cube::volume() const
{
    Square* tmp = static_cast<Square*>(baseShape);
    return pow(tmp->base(),3);
}



double Cube::lateralSurface() const
{
  Square* tmp = static_cast<Square*>(baseShape);
  return 4 * pow(tmp->base(), 2);
}



double Cube::totalSurface() const
{
  Square* tmp = static_cast<Square*>(baseShape);
  return 6 * pow(tmp->base(), 2);
}

double Cube::diagonal() const
{
    return side() * sqrt(3);
}

double Cube::side() const
{
    Square* tmp = static_cast<Square*>(baseShape);
    return tmp->base();
}


Cube::~Cube()
{

}


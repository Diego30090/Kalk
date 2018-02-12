#include "cylinder.h"
#include "../..//Shape2D/Polygon/Quadrilateral/rectangle.h"
#include "math.h"



Cylinder::Cylinder(const std::vector<Point3D>& vp3d, Rectangle* bs, ColorRGB* color):
    RotationSolid(vp3d,bs, "Cylinder", color)
{

}

Cylinder* Cylinder::clone() const
{
    return new Cylinder(*this);
}

std::vector<Point3D> Cylinder::buildCylinder(Rectangle* p) const
{
    //if is rectangle
    std::vector<Point3D> points = std::vector<Point3D>();
    for(std::vector<Point2D>::const_iterator it = p->getPoints().begin(); it != p->getPoints().end(); ++it)
    {
        points.push_back(Point3D::p2dTop3d(*it));
    }

    return points; //solo quelli 2d, dovrebbero bastare
}



Cylinder::Cylinder(Rectangle* bs, ColorRGB* color):
    RotationSolid(buildCylinder(bs), bs, "Cylinder", color)
{

}


Cylinder* Cylinder::operator-(const Shape3D& s) const
{
    Rectangle* newbaseShape = static_cast<Rectangle*>(baseShape)->operator -(*s.getBaseShape());
    Cylinder* newCylinder = new Cylinder(buildCylinder(newbaseShape),newbaseShape, getColor()->operator -(*s.getColor()));
    return newCylinder;
}



Cylinder* Cylinder::operator+(const Shape3D& s) const
{
    Rectangle* newbaseShape = static_cast<Rectangle*>(baseShape)->operator +(*s.getBaseShape());
    Cylinder* newCylinder = new Cylinder(buildCylinder(newbaseShape),newbaseShape, getColor()->operator +(*s.getColor()));
    return newCylinder;
}



Cylinder* Cylinder::operator*(const Shape3D& s) const
{
    Rectangle* newbaseShape = static_cast<Rectangle*>(baseShape)->operator *(*s.getBaseShape());
    Cylinder* newCylinder = new Cylinder(buildCylinder(newbaseShape),newbaseShape, getColor()->operator *(*s.getColor()));
    return newCylinder;
}



Cylinder* Cylinder::operator/(const Shape3D& s) const
{
    Rectangle* newbaseShape = static_cast<Rectangle*>(baseShape)->operator /(*s.getBaseShape());
    Cylinder* newCylinder = new Cylinder(buildCylinder(newbaseShape),newbaseShape, getColor()->operator /(*s.getColor()));
    return newCylinder;
}



double Cylinder::height() const
{
    //return volume()/(M_PI * static_cast<Rectangle*>(baseShape)->base());
    return static_cast<Rectangle*>(baseShape)->height();
}

double Cylinder::ray() const
{
    return static_cast<Rectangle*>(baseShape) ->base();
}

double Cylinder::lateralSurface() const
{
    Rectangle* tmp = static_cast<Rectangle*>(baseShape);
    return 2 * M_PI * tmp->base() * tmp->height();
}



double Cylinder::baseSurface() const
{
    Rectangle* tmp = static_cast<Rectangle*>(baseShape);
    return M_PI * pow(tmp->base(),2);
}



double Cylinder::volume() const
{
    Rectangle* tmp = static_cast<Rectangle*>(baseShape);
    return M_PI * pow(tmp->base(),2) * tmp->height();
}



double Cylinder::totalSurface() const
{
    return lateralSurface() + 2 * baseSurface();
}

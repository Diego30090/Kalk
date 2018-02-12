#include "sphere.h"
#include "math.h"
#include "../../Shape2D/circle.h"



Sphere::Sphere(const std::vector<Point3D>& vp3d, Circle* bs, ColorRGB* color):
    RotationSolid(vp3d, bs, "Sphere", color)
{

}

Sphere* Sphere::clone() const
{
    return new Sphere(*this);
}

std::vector<Point3D> Sphere::buildSphere(Circle* p) const
{
    std::vector<Point3D> points = std::vector<Point3D>();

    for(std::vector<Point2D>::const_iterator it = p->getPoints().begin(); it != p->getPoints().end(); ++it)
    {
        points.push_back(Point3D::p2dTop3d(*it));
    }

    return points;
}



Sphere::Sphere(Circle* bs, ColorRGB* color): RotationSolid(buildSphere(bs), bs, "Sphere", color)
{

}



Sphere* Sphere::operator-(const Shape3D& s) const
{
    Circle* newbaseShape = static_cast<Circle*>(baseShape)->operator -(*s.getBaseShape());
    Sphere* newSphere = new Sphere(buildSphere(newbaseShape),newbaseShape, getColor()->operator -(*s.getColor()));
    return newSphere;
}



Sphere* Sphere::operator+(const Shape3D& s) const
{
    Circle* newbaseShape = static_cast<Circle*>(baseShape)->operator +(*s.getBaseShape());
    Sphere* newSphere = new Sphere(buildSphere(newbaseShape),newbaseShape, getColor()->operator +(*s.getColor()));
    return newSphere;
}



Sphere* Sphere::operator*(const Shape3D& s) const
{
    Circle* newbaseShape = static_cast<Circle*>(baseShape)->operator *(*s.getBaseShape());
    Sphere* newSphere = new Sphere(buildSphere(newbaseShape),newbaseShape, getColor()->operator +(*s.getColor()));
    return newSphere;
}



Sphere* Sphere::operator/(const Shape3D& s) const
{
    Circle* newbaseShape = static_cast<Circle*>(baseShape)->operator /(*s.getBaseShape());
    Sphere* newSphere = new Sphere(buildSphere(newbaseShape),newbaseShape, getColor()->operator +(*s.getColor()));
    return newSphere;
}



double Sphere::diameter() const
{
    Circle* tmp = static_cast<Circle*>(baseShape);
    return tmp->diameter();
}


double Sphere::ray() const
{
    return static_cast<Circle*>(baseShape) ->ray();
}

double Sphere::volume() const
{
    return (4 * M_PI * pow(ray(),3)) / 3;
}



double Sphere::totalSurface() const
{
    return 4 * M_PI * pow(ray(),2);
}

double Sphere::circumference() const
{
    Circle* tmp = static_cast<Circle*>(baseShape);
    return tmp->circumference();
}


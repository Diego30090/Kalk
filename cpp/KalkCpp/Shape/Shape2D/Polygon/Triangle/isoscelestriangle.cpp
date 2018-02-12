#include "isoscelestriangle.h"
#include "math.h"
#include <iostream>
#include "typeinfo"


IsoscelesTriangle::IsoscelesTriangle(const std::vector<Point2D>& vp2d, ColorRGB* color): Triangle(vp2d, "Isosceles Triangle", color)
{
    if(!canBuild(vp2d))
    {
        points = buildIsoscelesTriangle(1,1);
    }
}


IsoscelesTriangle* IsoscelesTriangle::clone() const
{
    return new IsoscelesTriangle(*this);
}

bool IsoscelesTriangle::canBuild(double base, double height) const
{
    return base > 0 && height > 0;
}

bool IsoscelesTriangle::canBuild(const std::vector<Point2D>& vp2d) const
{
    if(vp2d.size() == 3)
    {
        double base = Point2D::distance(vp2d[1], vp2d[0]);
        double height = Point2D::distance(vp2d[2],Point2D(base/2,0));
        if(base > 0 && height > 0)
        {
            return true;
        }
    }
    return false;
}

std::vector<Point2D> IsoscelesTriangle::buildIsoscelesTriangle(double base, double height) const
{
    if(!canBuild(base, height))
    {
        base = 1;
        height = 1;
    }

    std::vector<Point2D> points = std::vector<Point2D>();
    points.push_back(Point2D());
    points.push_back(Point2D(base,0));
    points.push_back(Point2D(base/2, height));

    return points;
}



IsoscelesTriangle::IsoscelesTriangle(double base, double height, ColorRGB* color): Triangle(buildIsoscelesTriangle(base, height), "Isosceles Triangle", color)
{

}


IsoscelesTriangle* IsoscelesTriangle::operator-(const Shape2D& s) const
{
    double newBase = 0;
    double newHeight = 0;
    IsoscelesTriangle* newIsoscelesTriangle = nullptr;
    if(typeid(s) == typeid(const IsoscelesTriangle&))
    {
        const IsoscelesTriangle& it = static_cast<const IsoscelesTriangle&>(s);
        newBase = base() - it.base();
        newHeight = height() - it.height();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator -(*s.getColor()));
    }else{
        newBase = base() - s.sideToOperator();
        newHeight = height() - s.sideToOperator();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator -(*s.getColor()));
    }
    return newIsoscelesTriangle;
}

IsoscelesTriangle* IsoscelesTriangle::operator+(const Shape2D& s) const
{
    double newBase = 0;
    double newHeight = 0;
    IsoscelesTriangle* newIsoscelesTriangle = nullptr;
    if(typeid(s) == typeid(const IsoscelesTriangle&))
    {
        const IsoscelesTriangle& it = static_cast<const IsoscelesTriangle&>(s);
        newBase = base() + it.base();
        newHeight = height() + it.height();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator +(*s.getColor()));
    }else{
        newBase = base() + s.sideToOperator();
        newHeight = height() + s.sideToOperator();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator +(*s.getColor()));
    }
    return newIsoscelesTriangle;
}

IsoscelesTriangle* IsoscelesTriangle::operator*(const Shape2D& s) const
{
    double newBase = 0;
    double newHeight = 0;
    IsoscelesTriangle* newIsoscelesTriangle = nullptr;
    if(typeid(s) == typeid(const IsoscelesTriangle&))
    {
        const IsoscelesTriangle& it = static_cast<const IsoscelesTriangle&>(s);
        newBase = base() * it.base();
        newHeight = height() * it.height();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator *(*s.getColor()));
    }else{
        newBase = base() * s.sideToOperator();
        newHeight = height() * s.sideToOperator();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator *(*s.getColor()));
    }
    return newIsoscelesTriangle;
}

IsoscelesTriangle* IsoscelesTriangle::operator/(const Shape2D& s) const
{
    double newBase = 0;
    double newHeight = 0;
    IsoscelesTriangle* newIsoscelesTriangle = nullptr;
    if(typeid(s) == typeid(const IsoscelesTriangle&))
    {
        const IsoscelesTriangle& it = static_cast<const IsoscelesTriangle&>(s);
        newBase = base() / it.base();
        newHeight = height() / it.height();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator /(*s.getColor()));
    }else{
        newBase = base() / s.sideToOperator();
        newHeight = height() / s.sideToOperator();
        newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight), getColor()->operator /(*s.getColor()));
    }
    return newIsoscelesTriangle;
}


double IsoscelesTriangle::sideToOperator() const
{
    return base() + height();
}



double IsoscelesTriangle::base() const
{
    return Point2D::distance(getPoints()[1], getPoints()[0]);
}



double IsoscelesTriangle::height() const
{
    return Point2D::distance(getPoints()[2], Point2D(base()/2,0));
}

double IsoscelesTriangle::side() const
{
    return (2 * perimeter() -base()) / 2;
}


double IsoscelesTriangle::area() const
{
    return (base() * height())/2;
}


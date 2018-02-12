#include "righttriangle.h"
#include "math.h"
#include "typeinfo"


RightTriangle::RightTriangle(const std::vector<Point2D>& vp2d, ColorRGB* color): Triangle(vp2d, "Right Triangle", color)
{
    if(!canBuild(vp2d))
    {
        points = buildRightTriangle(1,1);
    }
}

RightTriangle* RightTriangle::clone() const
{
    return new RightTriangle(*this);
}

bool RightTriangle::canBuild(double cMax, double cMin) const
{
    return cMax > 0 && cMin > 0;
}

bool RightTriangle::canBuild(const std::vector<Point2D>& vp2d) const
{
    if(vp2d.size() == 3)
    {
        double base = Point2D::distance(vp2d[1], vp2d[0]);
        double height = Point2D::distance(vp2d[2], vp2d[0]);
        if(base > 0 && height > 0)
        {
            return true;
        }
    }
    return false;
}

std::vector<Point2D> RightTriangle::buildRightTriangle(double cathetusMax, double cathetusMin) const
{

    if(!canBuild(cathetusMax, cathetusMax))
    {
        cathetusMax = 1;
        cathetusMin = 1;
    }

    std::vector<Point2D> points = std::vector<Point2D>();

    points.push_back(Point2D());
    points.push_back(Point2D(cathetusMin));
    points.push_back(Point2D(0, cathetusMax));

    return points;
}



RightTriangle::RightTriangle(double cathetusMax, double cathetusMin, ColorRGB* color): Triangle(buildRightTriangle(cathetusMax, cathetusMin), "Right Triangle", color)
{

}


RightTriangle* RightTriangle::operator-(const Shape2D& s) const
{
    double newCathetusMin = 0;
    double newCathetusMax = 0;
    RightTriangle* newRightTriangle = nullptr;
    if(typeid(s) == typeid(const RightTriangle&))
    {
        const RightTriangle& rt = static_cast<const RightTriangle&>(s);
        newCathetusMin = base() - rt.base();
        newCathetusMax = height() - rt.height();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator -(*s.getColor()));
    }else{
        newCathetusMin = base() - s.sideToOperator();
        newCathetusMax = height() - s.sideToOperator();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator -(*s.getColor()));
    }
    return newRightTriangle;
}

RightTriangle* RightTriangle::operator+(const Shape2D& s) const
{
    double newCathetusMin = 0;
    double newCathetusMax = 0;
    RightTriangle* newRightTriangle = nullptr;
    if(typeid(s) == typeid(const RightTriangle&))
    {
        const RightTriangle& rt = static_cast<const RightTriangle&>(s);
        newCathetusMin = base() + rt.base();
        newCathetusMax = height() + rt.height();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator +(*s.getColor()));
    }else{
        newCathetusMin = base() + s.sideToOperator();
        newCathetusMax = height() + s.sideToOperator();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator +(*s.getColor()));
    }
    return newRightTriangle;
}

RightTriangle* RightTriangle::operator*(const Shape2D& s) const
{
    double newCathetusMin = 0;
    double newCathetusMax = 0;
    RightTriangle* newRightTriangle = nullptr;
    if(typeid(s) == typeid(const RightTriangle&))
    {
        const RightTriangle& rt = static_cast<const RightTriangle&>(s);
        newCathetusMin = base() * rt.base();
        newCathetusMax = height() * rt.height();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator *(*s.getColor()));
    }else{
        newCathetusMin = base() * s.sideToOperator();
        newCathetusMax = height() * s.sideToOperator();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator *(*s.getColor()));
    }
    return newRightTriangle;
}

RightTriangle* RightTriangle::operator/(const Shape2D& s) const
{
    double newCathetusMin = 0;
    double newCathetusMax = 0;
    RightTriangle* newRightTriangle = nullptr;
    if(typeid(s) == typeid(const RightTriangle&))
    {
        const RightTriangle& rt = static_cast<const RightTriangle&>(s);
        newCathetusMin = base() / rt.base();
        newCathetusMax = height() / rt.height();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator /(*s.getColor()));
    }else{
        newCathetusMin = base() / s.sideToOperator();
        newCathetusMax = height() / s.sideToOperator();
        newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMax, newCathetusMin), getColor()->operator /(*s.getColor()));
    }
    return newRightTriangle;
}


double RightTriangle::sideToOperator() const
{
    return base() + height();
}



double RightTriangle::base() const
{
    return Point2D::distance(getPoints()[1], getPoints()[0]);
}



double RightTriangle::height() const
{
    return Point2D::distance(getPoints()[2], getPoints()[0]);
}



double RightTriangle::hypotenuse() const
{
    return sqrt(pow(base(), 2) + pow(height(), 2));
}

double RightTriangle::area() const
{
    return (base() * height())/2;
}


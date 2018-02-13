#include "point2d.h"
#include "math.h"
#include <typeinfo>
#include <string>


Point2D::Point2D(double var_x, double var_y) : x(var_x), y(var_y)
{

}



bool Point2D::operator==(const Point2D& p) const
{
    if(this == &p)
        return true;
    if(&p != 0 && typeid(*this) == typeid(p))
    {
        return x == p.x && y == p.y;
    }
    return false;
}




double Point2D::distance(const Point2D& p1, const Point2D& p2)
{
    return sqrt(pow(p2. x - p1. x, 2) + pow(p2.y - p1.y, 2));
}



double Point2D::getX() const
{
    return x;
}



double Point2D::getY() const
{
    return y;
}


void Point2D::setX(double nx)
{
    x = nx;
}

void Point2D::setY(double ny)
{
    y = ny;
}

void Point2D::printPoint() const
{
     std::cout << "P2D(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

std::ostream& operator<<(std::ostream& os, const Point2D& p2d)
{
    return os << "(" << p2d.x << "," << p2d.y << ")";
}


Point2D::~Point2D()
{

}

#include "point3d.h"
#include "math.h"
#include <string>


Point3D::Point3D(double var_x, double var_y, double var_z) : Point2D(var_x, var_y), z(var_z)
{

}



bool Point3D::operator==(const Point2D& p) const
{
    if(Point2D::operator ==(p))
    {
        const Point3D& p3d = static_cast<const Point3D&>(p);
        if(z == p3d.z)
        {
            return true;
        }
    }
    return false;
}



double Point3D::distance(const Point3D& p1, const Point3D& p2)
{
    return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2) + pow(p2.z - p1.z, 2));
}

Point3D Point3D::p2dTop3d(const Point2D& p2d)
{
    return Point3D(p2d.getX(), p2d.getY());
}


void Point3D::printPoint() const
{
     std::cout << "P2D(" + std::to_string(getX()) + "," + std::to_string(getY()) + "," + std::to_string(z) + ")";
}


std::ostream& operator<<(std::ostream& os, const Point3D& p3d)
{
 return os << "(" << p3d.getX() << "," << p3d.getY() << "," << p3d.z << ")";
}



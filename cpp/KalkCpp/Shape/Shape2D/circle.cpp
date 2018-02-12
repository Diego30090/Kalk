#include "circle.h"
#include "math.h"
#include "typeinfo"


Circle::Circle(const std::vector<Point2D>& vp2d, ColorRGB* color): Shape2D(vp2d, "Circle", color)
{

    if(!canBuild(vp2d))
    {
        points = buildCircle(1);
    }
}


Circle* Circle::clone() const
{
    return new Circle(*this);
}

bool Circle::canBuild(double ray) const
{
    return ray > 0;
}

bool Circle::canBuild(const std::vector<Point2D>& vp2d) const
{
    if(vp2d.size() == 2)
    {
        if(Point2D::distance(vp2d[1],vp2d[0]) >= 0)
        {
            return true;
        }
    }
    return false;
}

std::vector<Point2D> Circle::buildCircle(double ray) const
{

    if(!canBuild(ray))
        ray = 1;
    std::vector<Point2D> points = std::vector<Point2D>();

    points.push_back(Point2D());
    points.push_back(Point2D(ray,0));

    return points;
}



Circle::Circle(double ray, ColorRGB* color): Shape2D(buildCircle(ray), "Circle", color)
{

}


Circle* Circle::operator-(const Shape2D& s) const
{
    double newRay = 0;
    Circle* newCircle = nullptr;
    if(typeid(s) == typeid(const Circle&))
    {
        const Circle& c = static_cast<const Circle&>(s);
        newRay = ray() - c.ray();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator -(*s.getColor()));
    }else{
        newRay = ray() - s.sideToOperator();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator -(*s.getColor()));
    }
    return newCircle;
}

Circle* Circle::operator+(const Shape2D& s) const
{
    double newRay = 0;
    Circle* newCircle = nullptr;
    if(typeid(s) == typeid(const Circle&))
    {
        const Circle& c = static_cast<const Circle&>(s);
        newRay = ray() + c.ray();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator +(*s.getColor()));
    }else{
        newRay = ray() + s.sideToOperator();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator +(*s.getColor()));
    }
    return newCircle;
}

Circle* Circle::operator*(const Shape2D& s) const
{
    double newRay = 0;
    Circle* newCircle = nullptr;
    if(typeid(s) == typeid(const Circle&))
    {
        const Circle& c = static_cast<const Circle&>(s);
        newRay = ray() * c.ray();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator *(*s.getColor()));
    }else{
        newRay = ray() * s.sideToOperator();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator *(*s.getColor()));
    }
    return newCircle;
}

Circle* Circle::operator/(const Shape2D& s) const
{
    double newRay = 0;
    Circle* newCircle = nullptr;
    if(typeid(s) == typeid(const Circle&))
    {
        const Circle& c = static_cast<const Circle&>(s);
        newRay = ray() / c.ray();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator /(*s.getColor()));
    }else{
        newRay = ray() / s.sideToOperator();
        newCircle = new Circle(buildCircle(newRay), getColor()->operator /(*s.getColor()));
    }
    return newCircle;
}



double Circle::sideToOperator() const
{
    return ray();
}



double Circle::ray() const
{
    return Point2D::distance(getPoints()[1], getPoints()[0]);
}



double Circle::diameter() const
{
    return ray() * 2;
}



double Circle::circumference() const
{
    return 2 * M_PI * ray();
}



double Circle::area() const
{
    return M_PI * pow(ray(), 2);
}


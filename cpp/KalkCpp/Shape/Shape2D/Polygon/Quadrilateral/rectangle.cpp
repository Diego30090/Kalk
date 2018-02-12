#include "rectangle.h"
#include "typeinfo"
#include "math.h"


Rectangle::Rectangle(const std::vector<Point2D>& vp2d, ColorRGB* color): Quadrilateral(vp2d, "Rectangle", color)
{

    if(!canBuild(vp2d))
    {
        points = buildRectangle(2,1);
    }
}


Rectangle* Rectangle::clone() const
{
    return new Rectangle(*this);
}


bool Rectangle::canBuild(double base , double height) const
{
    return (base > 0 && height > 0 && base != height);
}

bool Rectangle::canBuild(const std::vector<Point2D>& vp2d) const
{
    if(vp2d.size() == 4)
    {
        double base = Point2D::distance(vp2d[1],vp2d[0]);
        double height = Point2D::distance(vp2d[2],vp2d[1]);
        if(base > 0 && height > 0 && base != height)
        {
            return true;
        }
    }
    return false;
}


std::vector<Point2D> Rectangle::buildRectangle(double base, double height) const
{
    if(!canBuild(base, height)) {
        base = 2;
        height = 1;
    }
    std::vector<Point2D> points = std::vector<Point2D>();
    points.push_back(Point2D());
    points.push_back(Point2D(base,0));
    points.push_back(Point2D(base,height));
    points.push_back(Point2D(0,height));

    return points;
}



Rectangle::Rectangle(double base, double height, ColorRGB* color): Quadrilateral(buildRectangle(base, height), "Rectangle", color)
{

}


Rectangle* Rectangle::operator-(const Shape2D& s) const
{
    double newSide1 = 0;
    double newSide2 = 0;
    Rectangle* newRectangle = nullptr;
    if(typeid(s) == typeid(const Rectangle&))
    {
        const Rectangle& rc = static_cast<const Rectangle&>(s);
        newSide1 = base() - rc.base();
        newSide2 = height() - rc.height();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator -(*s.getColor()));
    }else{

        newSide1 = base() - s.sideToOperator();
        newSide2 = height() - s.sideToOperator();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator -(*s.getColor()));
    }
    return newRectangle;
}

Rectangle* Rectangle::operator+(const Shape2D& s) const
{
    double newSide1 = 0;
    double newSide2 = 0;
    Rectangle* newRectangle = nullptr;
    if(typeid(s) == typeid(const Rectangle&))
    {
        const Rectangle& rc = static_cast<const Rectangle&>(s);
        newSide1 = base() + rc.base();
        newSide2 = height() + rc.height();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator +(*s.getColor()));
    }else{
        std:: cout << base() << " " << s.sideToOperator() << std::endl;
        newSide1 = base() + s.sideToOperator();
        newSide2 = height() + s.sideToOperator();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator +(*s.getColor()));
    }
    return newRectangle;
}

Rectangle* Rectangle::operator*(const Shape2D& s) const
{
    double newSide1 = 0;
    double newSide2 = 0;
    Rectangle* newRectangle = nullptr;
    if(typeid(s) == typeid(const Rectangle&))
    {
        const Rectangle& rc = static_cast<const Rectangle&>(s);
        newSide1 = base() * rc.base();
        newSide2 = height() * rc.height();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator *(*s.getColor()));
    }else{
        newSide1 = base() * s.sideToOperator();
        newSide2 = height() * s.sideToOperator();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator *(*s.getColor()));
    }
    return newRectangle;
}

Rectangle* Rectangle::operator/(const Shape2D& s) const
{
    double newSide1 = 0;
    double newSide2 = 0;
    Rectangle* newRectangle = nullptr;
    if(typeid(s) == typeid(const Rectangle&))
    {
        const Rectangle& rc = static_cast<const Rectangle&>(s);
        newSide1 = base() / rc.base();
        newSide2 = height() / rc.height();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator /(*s.getColor()));
    }else{
        newSide1 = base() / s.sideToOperator();
        newSide2 = height() / s.sideToOperator();
        newRectangle = new Rectangle(buildRectangle(newSide1, newSide2), getColor()->operator /(*s.getColor()));
    }
    return newRectangle;
}

double Rectangle::sideToOperator() const
{
    return base() + height();
}



double Rectangle::height() const
{
    return Point2D::distance(getPoints()[2], getPoints()[1]);
}



double Rectangle::base() const
{
    return Point2D::distance(getPoints()[1], getPoints()[0]);
}


double Rectangle::diagonal() const
{
    return sqrt(pow(base(),2) + pow(height(),2));
}


double Rectangle::area() const
{
    return base() * height();
}

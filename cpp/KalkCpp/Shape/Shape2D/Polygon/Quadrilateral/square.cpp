#include <iostream>
#include "square.h"
#include "math.h"
#include "typeinfo"

Square::Square(const std::vector<Point2D>& vp2d, ColorRGB* color): Quadrilateral(vp2d, "Square", color)
{
    if(!canBuild(vp2d))
    {
        points = buildSquare(1);
    }
}


Square* Square::clone() const
{
    return new Square(*this);
}

Square::Square(double sideLength, ColorRGB* color): Quadrilateral(buildSquare(sideLength), "Square", color)
{

}

bool Square::canBuild(double sideLenght) const
{
 return sideLenght > 0;
}

bool Square::canBuild(const std::vector<Point2D>& vp2d) const
{
    if(vp2d.size() == 4)
    {
        if(Point2D::distance(vp2d[1], vp2d[0]) > 0)
        {
            return true;
        }
    }
    return false;
}

std::vector<Point2D> Square::buildSquare(double sideLength) const
{
    if(!canBuild(sideLength))
        sideLength = 1;
    std::vector<Point2D> points =  std::vector<Point2D>();

    points.push_back(Point2D());
    points.push_back(Point2D(sideLength));
    points.push_back(Point2D(sideLength,sideLength));
    points.push_back(Point2D(0,sideLength));

    return points;
}



Square* Square::operator-(const Shape2D& s) const
{
    double newSide = 0;
    Square* newSquare = nullptr;
    if(typeid(s) == typeid(const Square&))
    {
        const Square& sq = static_cast<const Square&>(s);
        newSide = base() - sq.base();
        newSquare = new Square(buildSquare(newSide), getColor()->operator -(*s.getColor()));
    }else{
        newSide = base() - s.sideToOperator();
        newSquare = new Square(buildSquare(newSide), getColor()->operator -(*s.getColor()));
    }
    return newSquare;
}

Square* Square::operator+(const Shape2D& s) const
{
    double newSide = 0;
    Square* newSquare = nullptr;
    if(typeid(s) == typeid(const Square&))
    {
        const Square& sq = static_cast<const Square&>(s);
        newSide = base() + sq.base();
        newSquare = new Square(buildSquare(newSide), getColor()->operator +(*s.getColor()));
    }else{
        newSide = base() + s.sideToOperator();
        newSquare = new Square(buildSquare(newSide), getColor()->operator +(*s.getColor()));
    }
    return newSquare;
}

Square* Square::operator*(const Shape2D& s) const
{
    double newSide = 0;
    Square* newSquare = nullptr;
    if(typeid(s) == typeid(const Square&))
    {
        const Square& sq = static_cast<const Square&>(s);
        newSide = base() * sq.base();
        newSquare = new Square(buildSquare(newSide), getColor()->operator *(*s.getColor()));
    }else{
        newSide = base() * s.sideToOperator();
        newSquare = new Square(buildSquare(newSide), getColor()->operator *(*s.getColor()));
    }
    return newSquare;
}

Square* Square::operator/(const Shape2D& s) const
{
    double newSide = 0;
    Square* newSquare = nullptr;
    if(typeid(s) == typeid(const Square&))
    {
        const Square& sq = static_cast<const Square&>(s);
        newSide = base() / sq.base();
        newSquare = new Square(buildSquare(newSide), getColor()->operator /(*s.getColor()));
    }else{
        newSide = base() / s.sideToOperator();
        newSquare = new Square(buildSquare(newSide), getColor()->operator /(*s.getColor()));
    }
    return newSquare;
}

double Square::sideToOperator() const
{
    return base();
}



double Square::base() const
{
    return Point2D::distance(getPoints()[1], getPoints()[0]);
}



double Square::height() const
{
    return base();
}


double Square::diagonal() const
{
    return base() * sqrt(2);
}


double Square::area() const
{
    return pow(base(),2);
}


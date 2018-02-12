#include "polygon.h"
#include <string>
#include <vector>
#include <iostream>



Polygon::Polygon(const std::vector<Point2D>& vp2d, const std::string& name, ColorRGB* color): Shape2D(vp2d, name, color)
{

}





double Polygon::perimeter() const
{
    double perimeter = 0;
    double side = 0;
    unsigned short i = 0;
    std::vector<Point2D>::const_iterator second = getPoints().begin() + 1;
    for(std::vector<Point2D>::const_iterator it = getPoints().begin(); it != getPoints().end(); ++it) {
        if(i < getNumberSide() - 1){
            side = Point2D::distance(*second, *it);
            perimeter += side;
            ++second;
            ++i;
        }
    }
    second = getPoints().begin() + getNumberVertex() - 1;
    side = Point2D::distance(*second, *getPoints().begin());
    perimeter += side;

    return perimeter;
}

double Polygon::gaussArea(const std::vector<Point2D>& points)
{
    double area = 0;
    unsigned int i = 0;
    std::vector<Point2D>::const_iterator second = points.begin() + 1;
    for(std::vector<Point2D>::const_iterator it = points.begin(); it != points.end(); ++it)
    {
        if(i < points.size() - 1){
            area += it->getX() * second->getY();
            ++second;
            i++;
        }
    }

    second = points.begin() + points.size() - 1;
    area += second->getX() * points.begin()->getY();

    second = points.begin() + 1;
    for(std::vector<Point2D>::const_iterator it = points.begin(); it != points.end(); ++it)
    {
        if(i < points.size() - 1){
            area -= it->getY() * second->getX();
            ++second;
            i++;
        }
    }

    second = points.begin() + points.size() - 1;
    area -= second->getX() * points.begin()->getY();

    return area/2;
}


#include "shape3d.h"
#include <iostream>



Shape3D::Shape3D(const std::vector<Point3D>& vp3d, Shape2D* bs, std::string name, ColorRGB* color): Shape(name, color), points(vp3d), baseShape(bs)
{
    adjustPoints(bs->getPoints());
}



Shape3D::Shape3D(const Shape3D& s3d): Shape(s3d), points(s3d.points), baseShape(s3d.baseShape->clone())
{

}


bool Shape3D::operator ==(const Shape& s) const
{
    if(Shape::operator ==(s))
    {
        const Shape3D& s3d = static_cast<const Shape3D&>(s);
        if(points == s3d.points && *baseShape == *(s3d.baseShape))
        {
            return true;
        }
    }
    return false;
}

Shape3D& Shape3D::operator=(const Shape3D& s3d)
{
    if(this != &s3d){
        Shape::operator =(s3d);
        points = s3d.points;
        delete baseShape;
        baseShape = s3d.baseShape->clone();
    }
    return *this;
}



unsigned int Shape3D::getNumberVertex() const
{
    return points.size();
}



const std::vector<Point3D>& Shape3D::getPoints() const
{
    return points;
}



void Shape3D::adjustPoints(const std::vector<Point2D>& bs_points)
{
	for(std::vector<Point2D>::const_iterator it = bs_points.begin(); it != bs_points.end(); ++it)
	{
		Point3D tmp = Point3D::p2dTop3d(*it);
		bool found = false;
		for(std::vector<Point3D>::const_iterator it_t = points.begin(); it_t != points.end() && !found; ++it_t)
		{
			if(tmp == *it_t){
				found = true;
			}
		}
		if(!found){
			points.push_back(tmp);
		}
	}
}



const Shape2D* Shape3D::getBaseShape() const
{
    return baseShape;
}



Shape3D::~Shape3D()
{
    delete baseShape;
}

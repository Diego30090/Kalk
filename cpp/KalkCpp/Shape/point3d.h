#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include "point2d.h"

class Point3D : public Point2D
{
    /**
        Output operator for Point3D, print point in (x,y,z) style

        @param os the ostream for the output
        @param p3d the Point3D to print
        @return the ostream used for the output
    */
    friend std::ostream& operator<<(std::ostream&, const Point3D&);
private:
    //the z value of the point
    double z;
public:
    /**
        Constructor for Point3D with 3 params (x,y,z)
        (By default create a simple point (0,0,0))

        @param x The x value of the point
        @param y The y value of the point
        @param z The z value of the point
    */
    Point3D(double =0, double =0, double =0);

    /**
        Equal operator for Point3D

        @param p3d the (second) point to use
        @return (bool) if the invocation point is equal to p3d
    */
    bool operator==(const Point2D&) const;

    /**
        Distance Function

        @param a the first point
        @param b the second point
        @return the distance between two points
    */
    static double distance(const Point3D&, const Point3D&);

    /**
        Converter from Point2D to Point3D (create a point3d from a 2d point setting z to 0)

        @param p2d the point to convert
        @return a new point that is the 3d value of a 2d point
    */
    static Point3D p2dTop3d(const Point2D&);

    /**
     * Method that print the current point (X,Y,Z)
     */
    void printPoint() const;

};

/** Output operator for Point3D, see friend definition in class for more*/
std::ostream& operator<<(std::ostream&, const Point3D&);

#endif // POINT3D_H

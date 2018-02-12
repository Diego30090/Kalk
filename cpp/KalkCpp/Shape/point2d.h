#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D
{
    /**
        Output operator for Point2D, print point in (x,y) style

        @param os the ostream for the output
        @param p2d the Point2D to print
        @return the ostream used for the output
    */
    friend std::ostream& operator<<(std::ostream&, const Point2D&);
private:
    //the x value of the point
    double x;
    //the y value of the point
    double y;
public:
    /**
        Constructor for Point2D with 2 params (x,y)
        (By default create a simple point (0,0))

        @param x The x value of the point
        @param y The y value of the point
    */
    Point2D(double =0, double =0);

    /**
        Equal operator for Point2D

        @param p2d the (second) point to use
        @return (bool) if the invocation point is equal to p2d
    */
    virtual bool operator==(const Point2D&) const;

    /**
        Distance Function

        @param a the first point
        @param b the second point
        @return the distance between two points
    */
    static double distance(const Point2D&, const Point2D&);

    /**
        Function that return the X value of the point, useful for childs classes

        @return The X value of the current point
    */
    double getX() const;

    /**
        Function that return the Y value of the point, useful for childs classes

        @return The Y value of the current point
    */
    double getY() const;

    /**
     * Method to change the X value of the point
     *
     * @param The new X value
     */
    void setX(double);

    /**
     * Method to change the Y value of the point
     *
     * @param The new Y value
     */
    void setY(double);

    /**
     * Method that print the current point (X,Y)
     */
    virtual void printPoint() const;

    /**
        Virtual distructor of the class
    */
    virtual ~Point2D() ;
};

/** Output operator for Point2D, see friend definition in class for more*/
std::ostream& operator<<(std::ostream&, const Point2D&);

#endif // POINT2D_H

#ifndef TRIANGLERETCONTROLLER_H
#define TRIANGLERETCONTROLLER_H

#include "shape2dcontroller.h"
#include "Shape/Shape2D/Polygon/Triangle/righttriangle.h"

/**
 * @brief The TriangleRetController class is an extension of the Shape2DController, it's the controller for the RightTriangle Shape.
 * It contains a reference to a RightTriangle* (the model of this controller) and the definition of the abstract methods of the main 2D controller.
 */
class TriangleRetController: public Shape2DController
{
private:
    RightTriangle* model = nullptr;
public:
    TriangleRetController(RightTriangle*);
    TriangleRetController(const TriangleRetController& other);
    TriangleRetController& operator=(const TriangleRetController& other);

    virtual TriangleRetController* clone() const;
    RightTriangle* sum(const Shape2D& s) const;
    RightTriangle* sub(const Shape2D& s) const;
    RightTriangle* mul(const Shape2D& s) const;
    RightTriangle* div(const Shape2D& s) const;

    virtual void Translate(const Point2D&) const;
    double area() const;
    double perimeter() const;
    double base() const;
    double height() const;
    ColorRGB* color() const;
    virtual RightTriangle* getModel() const;
    virtual void setModel(const Shape2D*);

    virtual ~TriangleRetController();
};

#endif // TRIANGLERETCONTROLLER_H

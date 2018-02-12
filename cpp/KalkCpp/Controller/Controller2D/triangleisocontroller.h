#ifndef TRIANGLEISOCONTROLLER_H
#define TRIANGLEISOCONTROLLER_H

#include "shape2dcontroller.h"
#include "Shape/Shape2D/Polygon/Triangle/isoscelestriangle.h"

/**
 * @brief The TriangleIsoController class is an extension of the Shape2DController, it's the controller for the IsoscelesTriangle Shape.
 * It contains a reference to a IsoscelesTriangle* (the model of this controller) and the definition of the abstract methods of the main 2D controller.
 */
class TriangleIsoController: public Shape2DController
{
private:
    IsoscelesTriangle* model = nullptr;
public:
    TriangleIsoController(IsoscelesTriangle*);
    TriangleIsoController(const TriangleIsoController& other);
    TriangleIsoController& operator=(const TriangleIsoController& other);

    virtual TriangleIsoController* clone() const;
    IsoscelesTriangle* sum(const Shape2D& s) const;
    IsoscelesTriangle* sub(const Shape2D& s) const;
    IsoscelesTriangle* mul(const Shape2D& s) const;
    IsoscelesTriangle* div(const Shape2D& s) const;

    virtual void Translate(const Point2D&) const;
    double area() const;
    double perimeter() const;
    double base() const;
    double height() const;
    ColorRGB* color() const;
    virtual IsoscelesTriangle* getModel() const;
    virtual void setModel(const Shape2D*);

    virtual ~TriangleIsoController();
};

#endif // TRIANGLEISOCONTROLLER_H

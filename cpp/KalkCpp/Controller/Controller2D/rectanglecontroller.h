#ifndef RECTANGLECONTROLLER_H
#define RECTANGLECONTROLLER_H

#include "shape2dcontroller.h"
#include "Shape/Shape2D/Polygon/Quadrilateral/rectangle.h"

/**
 * @brief The RectangleController class is an extension of the Shape2DController, it's the controller for the Rectangle Shape.
 * It contains a reference to a Rectangle* (the model of this controller) and the definition of the abstract methods of the main 2D controller.
 */
class RectangleController: public Shape2DController
{
private:
    Rectangle* model = nullptr;
public:
    RectangleController(Rectangle*);
    RectangleController(const RectangleController& other);
    RectangleController& operator=(const RectangleController& other);

    virtual RectangleController* clone() const;
    Rectangle* sum(const Shape2D& s) const;
    Rectangle* sub(const Shape2D& s) const;
    Rectangle* mul(const Shape2D& s) const;
    Rectangle* div(const Shape2D& s) const;

    virtual void Translate(const Point2D&) const;
    double area() const;
    double perimeter() const;
    double side() const;
    double height() const;
    ColorRGB* color() const;
    virtual Rectangle* getModel() const;
    virtual void setModel(const Shape2D*);

    virtual ~RectangleController();
};

#endif // RECTANGLECONTROLLER_H

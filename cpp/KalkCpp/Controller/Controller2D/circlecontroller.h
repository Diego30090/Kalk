#ifndef CIRCLECONTROLLER_H
#define CIRCLECONTROLLER_H

#include "shape2dcontroller.h"
#include "Shape/Shape2D/circle.h"

/**
 * @brief The CircleController class is an extension of the Shape2DController, it's the controller for the Circle Shape.
 * It contains a reference to a Circle* (the model of this controller) and the definition of the abstract methods of the main 2D controller.
 */
class CircleController: public Shape2DController
{
private:
    Circle* model = nullptr;
public:
    CircleController(Circle*);
    CircleController(const CircleController& other);
    CircleController& operator=(const CircleController& other);

    virtual CircleController* clone() const;
    Circle* sum(const Shape2D& s) const;
    Circle* sub(const Shape2D& s) const;
    Circle* mul(const Shape2D& s) const;
    Circle* div(const Shape2D& s) const;

    virtual void Translate(const Point2D&) const;
    double area() const;
    double circumference() const;
    double ray() const;
    double diameter() const;
    ColorRGB* color() const;
    virtual Circle* getModel() const;
    virtual void setModel(const Shape2D*);

    virtual ~CircleController();
};

#endif // CIRCLECONTROLLER_H

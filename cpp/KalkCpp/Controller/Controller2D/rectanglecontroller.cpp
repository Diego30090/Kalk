#include "rectanglecontroller.h"

RectangleController& RectangleController::operator=(const RectangleController& other)
{
    if(this != &other)
    {
        Shape2DController::operator =(other);
        delete model;
        model = new Rectangle(*other.model);
    }
    return *this;
}

RectangleController::RectangleController(const RectangleController& other) : Shape2DController(other), model(other.model->clone())
{
}

RectangleController::RectangleController(Rectangle* s)
{
    model = s;
}

RectangleController* RectangleController::clone() const
{
    return new RectangleController(*this);
}

Rectangle* RectangleController::sum(const Shape2D& s) const
{
    return  *model + s;
}

Rectangle* RectangleController::sub(const Shape2D& s) const
{
    return  *model - s;
}

Rectangle* RectangleController::mul(const Shape2D& s) const
{
    return  *model * s;
}

Rectangle* RectangleController::div(const Shape2D& s) const
{
    return  *model / s;
}

double RectangleController::area() const
{
    return model->area();
}

double RectangleController::perimeter() const
{
    return model->perimeter();
}

double RectangleController::side() const
{
    return model->base();
}

double RectangleController::height() const
{
    return model->height();
}

ColorRGB* RectangleController::color() const
{
    return model->getColor();
}

void RectangleController::Translate(const Point2D& p) const
{
    model->translate(p);
}

Rectangle* RectangleController::getModel() const
{
    return model;
}

void RectangleController::setModel(const Shape2D* s)
{
    delete model;
    model = static_cast<Rectangle*>(const_cast<Shape2D*>(s));
}

RectangleController::~RectangleController()
{
    delete model;
}


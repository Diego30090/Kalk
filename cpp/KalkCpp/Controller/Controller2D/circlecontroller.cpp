#include "circlecontroller.h"

CircleController& CircleController::operator=(const CircleController& other)
{
    if(this != &other)
    {
        Shape2DController::operator =(other);
        delete model;
        model = new Circle(*other.model);
    }
    return *this;
}

CircleController::CircleController(const CircleController& other) : Shape2DController(other), model(other.model->clone())
{
}

CircleController::CircleController(Circle* s)
{
    model = s;
}

CircleController* CircleController::clone() const
{
    return new CircleController(*this);
}

Circle* CircleController::sum(const Shape2D& s) const
{
    return  *model + s;
}

Circle* CircleController::sub(const Shape2D& s) const
{
    return  *model - s;
}

Circle* CircleController::mul(const Shape2D& s) const
{
    return  *model * s;
}

Circle* CircleController::div(const Shape2D& s) const
{
    return  *model / s;
}

double CircleController::area() const
{
    return model->area();
}

double CircleController::circumference() const
{
    return model->circumference();
}

double CircleController::ray() const
{
    return model->ray();
}

double CircleController::diameter() const
{
    return model->diameter();
}

ColorRGB* CircleController::color() const
{
    return model->getColor();
}

void CircleController::Translate(const Point2D& p) const
{
    model->translate(p);
}

Circle* CircleController::getModel() const
{
    return model;
}

void CircleController::setModel(const Shape2D* s)
{
    delete model;
    model = static_cast<Circle*>(const_cast<Shape2D*>(s));
}

CircleController::~CircleController()
{
    delete model;
}


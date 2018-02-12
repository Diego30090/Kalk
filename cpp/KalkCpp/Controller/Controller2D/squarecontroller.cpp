#include "squarecontroller.h"

SquareController& SquareController::operator=(const SquareController& other)
{
    if(this != &other)
    {
        Shape2DController::operator =(other);
        delete model;
        model = new Square(*other.model);
    }
    return *this;
}

SquareController::SquareController(const SquareController& other) : Shape2DController(other), model(other.model->clone())
{
}

SquareController::SquareController(Square* s)
{
    model = s;
}

SquareController* SquareController::clone() const
{
    return new SquareController(*this);
}

Square* SquareController::sum(const Shape2D& s) const
{
    return  *model + s;
}

Square* SquareController::sub(const Shape2D& s) const
{
    return  *model - s;
}

Square* SquareController::mul(const Shape2D& s) const
{
    return  *model * s;
}

Square* SquareController::div(const Shape2D& s) const
{
    return  *model / s;
}

double SquareController::area() const
{
    return model->area();
}

double SquareController::perimeter() const
{
    return model->perimeter();
}

double SquareController::side() const
{
    return model->base();
}

double SquareController::diagonal() const
{
    return model->diagonal();
}

ColorRGB* SquareController::color() const
{
    return model->getColor();
}

void SquareController::Translate(const Point2D& p) const
{
    model->translate(p);
}

Square* SquareController::getModel() const
{
    return model;
}

void SquareController::setModel(const Shape2D* s)
{
    delete model;
    model = static_cast<Square*>(const_cast<Shape2D*>(s));
}

SquareController::~SquareController()
{
    delete model;
}

#include "triangleretcontroller.h"

TriangleRetController& TriangleRetController::operator=(const TriangleRetController& other)
{
    if(this != &other)
    {
        Shape2DController::operator =(other);
        delete model;
        model = new RightTriangle(*other.model);
    }
    return *this;
}

TriangleRetController::TriangleRetController(const TriangleRetController& other) : Shape2DController(other), model(other.model->clone())
{
}

TriangleRetController::TriangleRetController(RightTriangle* s)
{
    model = s;
}

TriangleRetController* TriangleRetController::clone() const
{
    return new TriangleRetController(*this);
}

RightTriangle* TriangleRetController::sum(const Shape2D& s) const
{
    return  *model + s;
}

RightTriangle* TriangleRetController::sub(const Shape2D& s) const
{
    return  *model - s;
}

RightTriangle* TriangleRetController::mul(const Shape2D& s) const
{
    return  *model * s;
}

RightTriangle* TriangleRetController::div(const Shape2D& s) const
{
    return  *model / s;
}

double TriangleRetController::area() const
{
    return model->area();
}

double TriangleRetController::perimeter() const
{
    return model->perimeter();
}

double TriangleRetController::base() const
{
    return model->base();
}

double TriangleRetController::height() const
{
    return model->height();
}

ColorRGB* TriangleRetController::color() const
{
    return model->getColor();
}

void TriangleRetController::Translate(const Point2D& p) const
{
    model->translate(p);
}

RightTriangle* TriangleRetController::getModel() const
{
    return model;
}

void TriangleRetController::setModel(const Shape2D* s)
{
    delete model;
    model = static_cast<RightTriangle*>(const_cast<Shape2D*>(s));
}

TriangleRetController::~TriangleRetController()
{
    delete model;
}




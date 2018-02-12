#include "triangleisocontroller.h"

TriangleIsoController& TriangleIsoController::operator=(const TriangleIsoController& other)
{
    if(this != &other)
    {
        Shape2DController::operator =(other);
        delete model;
        model = new IsoscelesTriangle(*other.model);
    }
    return *this;
}

TriangleIsoController::TriangleIsoController(const TriangleIsoController& other) : Shape2DController(other), model(other.model->clone())
{
}

TriangleIsoController::TriangleIsoController(IsoscelesTriangle* s)
{
    model = s;
}

TriangleIsoController* TriangleIsoController::clone() const
{
    return new TriangleIsoController(*this);
}

IsoscelesTriangle* TriangleIsoController::sum(const Shape2D& s) const
{
    return  *model + s;
}

IsoscelesTriangle* TriangleIsoController::sub(const Shape2D& s) const
{
    return  *model - s;
}

IsoscelesTriangle* TriangleIsoController::mul(const Shape2D& s) const
{
    return  *model * s;
}

IsoscelesTriangle* TriangleIsoController::div(const Shape2D& s) const
{
    return  *model / s;
}

double TriangleIsoController::area() const
{
    return model->area();
}

double TriangleIsoController::perimeter() const
{
    return model->perimeter();
}

double TriangleIsoController::base() const
{
    return model->base();
}

double TriangleIsoController::height() const
{
    return model->height();
}

ColorRGB* TriangleIsoController::color() const
{
    return model->getColor();
}

void TriangleIsoController::Translate(const Point2D& p) const
{
    model->translate(p);
}

IsoscelesTriangle* TriangleIsoController::getModel() const
{
    return model;
}

void TriangleIsoController::setModel(const Shape2D* s)
{
    delete model;
    model = static_cast<IsoscelesTriangle*>(const_cast<Shape2D*>(s));
}

TriangleIsoController::~TriangleIsoController()
{
    delete model;
}



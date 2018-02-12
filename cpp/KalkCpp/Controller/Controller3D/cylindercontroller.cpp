#include "cylindercontroller.h"

CylinderController& CylinderController::operator=(const CylinderController& other)
{
    if(this != &other)
    {
        Shape3DController::operator =(other);
        delete model;
        model = new Cylinder(*other.model);
    }
    return *this;
}

CylinderController::CylinderController(const CylinderController& other) : Shape3DController(other), model(other.model->clone())
{
}

CylinderController::CylinderController(Cylinder* s)
{
    model = s;
}

CylinderController* CylinderController::clone() const
{
    return new CylinderController(*this);
}

Cylinder* CylinderController::sum(const Shape3D& s) const
{
    return  *model + s;
}

Cylinder* CylinderController::sub(const Shape3D& s) const
{
    return  *model - s;
}

Cylinder* CylinderController::mul(const Shape3D& s) const
{
    return  *model * s;
}

Cylinder* CylinderController::div(const Shape3D& s) const
{
    return  *model / s;
}

double CylinderController::volume() const
{
    return model->volume();
}
double CylinderController::surface() const
{
    return model->totalSurface();
}
double CylinderController::ray() const
{
    return model->ray();
}
double CylinderController::height() const
{
    return model->height();
}

ColorRGB* CylinderController::color() const
{
    return model->getColor();
}

Cylinder* CylinderController::getModel() const
{
    return model;
}

void CylinderController::setModel(const Shape3D* s)
{
    delete model;
    model = static_cast<Cylinder*>(const_cast<Shape3D*>(s));
}

CylinderController::~CylinderController()
{
    delete model;
}



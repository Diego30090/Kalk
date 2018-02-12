#include "spherecontroller.h"

SphereController& SphereController::operator=(const SphereController& other)
{
    if(this != &other)
    {
        Shape3DController::operator =(other);
        delete model;
        model = new Sphere(*other.model);
    }
    return *this;
}

SphereController::SphereController(const SphereController& other) : Shape3DController(other), model(other.model->clone())
{
}

SphereController::SphereController(Sphere* s)
{
    model = s;
}

SphereController* SphereController::clone() const
{
    return new SphereController(*this);
}

Sphere* SphereController::sum(const Shape3D& s) const
{
    return  *model + s;
}

Sphere* SphereController::sub(const Shape3D& s) const
{
    return  *model - s;
}

Sphere* SphereController::mul(const Shape3D& s) const
{
    return  *model * s;
}

Sphere* SphereController::div(const Shape3D& s) const
{
    return  *model / s;
}

double SphereController::volume() const
{
    return model->volume();
}
double SphereController::surface() const
{
    return model->totalSurface();
}
double SphereController::ray() const
{
    return model->ray();
}
double SphereController::diameter() const
{
    return model->diameter();
}

ColorRGB* SphereController::color() const
{
    return model->getColor();
}

Sphere* SphereController::getModel() const
{
    return model;
}

void SphereController::setModel(const Shape3D* s)
{
    delete model;
    model = static_cast<Sphere*>(const_cast<Shape3D*>(s));
}

SphereController::~SphereController()
{
    delete model;
}




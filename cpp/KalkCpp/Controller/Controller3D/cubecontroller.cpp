#include "cubecontroller.h"

CubeController& CubeController::operator=(const CubeController& other)
{
    if(this != &other)
    {
        Shape3DController::operator =(other);
        delete model;
        model = new Cube(*other.model);
    }
    return *this;
}

CubeController::CubeController(const CubeController& other) : Shape3DController(other), model(other.model->clone())
{
}

CubeController::CubeController(Cube* s)
{
    model = s;
}

CubeController* CubeController::clone() const
{
    return new CubeController(*this);
}

Cube* CubeController::sum(const Shape3D& s) const
{
    return  *model + s;
}

Cube* CubeController::sub(const Shape3D& s) const
{
    return  *model - s;
}

Cube* CubeController::mul(const Shape3D& s) const
{
    return  *model * s;
}

Cube* CubeController::div(const Shape3D& s) const
{
    return  *model / s;
}

double CubeController::volume() const
{
    return model->volume();
}

double CubeController::surface() const
{
    return model->totalSurface();
}
double CubeController::side() const
{
    return model->side();
}

ColorRGB* CubeController::color() const
{
    return model->getColor();
}

Cube* CubeController::getModel() const
{
    return model;
}

void CubeController::setModel(const Shape3D* s)
{
    delete model;
    model = static_cast<Cube*>(const_cast<Shape3D*>(s));
}

CubeController::~CubeController()
{
    delete model;
}



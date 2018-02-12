#ifndef SPHERECONTROLLER_H
#define SPHERECONTROLLER_H

#include "shape3dcontroller.h"
#include "Shape/Shape3D/RotationSolid/sphere.h"

/**
 * @brief The SphereController class is an extension of the Shape3DController, it's the controller for the Sphere Shape.
 * It contains a reference to a Sphere* (the model of this controller) and the definition of the abstract methods of the main 3D controller.
 */
class SphereController : public Shape3DController
{
private:
    Sphere* model = nullptr;
public:
    SphereController(Sphere*);
    SphereController(const SphereController& other);
    SphereController& operator=(const SphereController& other);

    virtual SphereController* clone() const;
    Sphere* sum(const Shape3D& s) const;
    Sphere* sub(const Shape3D& s) const;
    Sphere* mul(const Shape3D& s) const;
    Sphere* div(const Shape3D& s) const;

    double volume() const;
    double surface() const;
    double ray() const;
    double diameter() const;
    ColorRGB* color() const;
    virtual Sphere* getModel() const;
    virtual void setModel(const Shape3D*);

    virtual ~SphereController();
};

#endif // SPHERECONTROLLER_H

#ifndef CYLINDERCONTROLLER_H
#define CYLINDERCONTROLLER_H

#include "shape3dcontroller.h"
#include "Shape/Shape3D/RotationSolid/cylinder.h"

/**
 * @brief The CylinderController class is an extension of the Shape3DController, it's the controller for the Cylinder Shape.
 * It contains a reference to a Cylinder* (the model of this controller) and the definition of the abstract methods of the main 3D controller.
 */
class CylinderController : public Shape3DController
{
private:
    Cylinder* model = nullptr;
public:
    CylinderController(Cylinder*);
    CylinderController(const CylinderController& other);
    CylinderController& operator=(const CylinderController& other);

    virtual CylinderController* clone() const;
    Cylinder* sum(const Shape3D& s) const;
    Cylinder* sub(const Shape3D& s) const;
    Cylinder* mul(const Shape3D& s) const;
    Cylinder* div(const Shape3D& s) const;

    double volume() const;
    double surface() const;
    double ray() const;
    double height() const;
    ColorRGB* color() const;
    virtual Cylinder* getModel() const;
    virtual void setModel(const Shape3D*);

    virtual ~CylinderController();
};

#endif // CYLINDERCONTROLLER_H

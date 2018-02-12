#ifndef CUBECONTROLLER_H
#define CUBECONTROLLER_H

#include "shape3dcontroller.h"
#include "Shape/Shape3D/Polyhedron/cube.h"

/**
 * @brief The CubeController class is an extension of the Shape3DController, it's the controller for the Cube Shape.
 * It contains a reference to a Cube* (the model of this controller) and the definition of the abstract methods of the main 3D controller.
 */
class CubeController : public Shape3DController
{
private:
    Cube* model = nullptr;
public:
    CubeController(Cube*);
    CubeController(const CubeController& other);
    CubeController& operator=(const CubeController& other);

    virtual CubeController* clone() const;
    Cube* sum(const Shape3D& s) const;
    Cube* sub(const Shape3D& s) const;
    Cube* mul(const Shape3D& s) const;
    Cube* div(const Shape3D& s) const;

    double volume() const;
    double surface() const;
    double side() const;
    ColorRGB* color() const;
    virtual Cube* getModel() const;
    virtual void setModel(const Shape3D*);

    virtual ~CubeController();
};

#endif // CUBECONTROLLER_H

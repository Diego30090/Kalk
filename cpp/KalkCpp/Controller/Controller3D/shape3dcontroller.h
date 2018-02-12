#ifndef SHAPE3DCONTROLLER_H
#define SHAPE3DCONTROLLER_H

#include "Shape/Shape3D/shape3d.h"
#include "Controller/shapecontroller.h"

/**
 * @brief The Shape3DController class is the base abstract class for the 3D shapes controllers.
 * It contains a reference to the UI, and the methods to make the operations on the 3D shapes.
 */
class Shape3DController: public ShapeController
{
public:
    virtual Shape3DController* clone() const=0;
    virtual Shape3D* sum(const Shape3D& s) const =0;
    virtual Shape3D* sub(const Shape3D& s) const =0;
    virtual Shape3D* mul(const Shape3D& s) const =0;
    virtual Shape3D* div(const Shape3D& s) const =0;

    virtual Shape3D* getModel() const =0;
    virtual void setModel(const Shape3D*) =0;

};

#endif // SHAPE3DCONTROLLER_H

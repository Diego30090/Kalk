#ifndef SHAPE2DCONTROLLER_H
#define SHAPE2DCONTROLLER_H

#include "Shape/Shape2D/shape2d.h"
#include "Controller/shapecontroller.h"

/**
 * @brief The Shape2DController class is the base abstract class for the 2D shapes controllers.
 * It contains a reference to the UI, and the methods to make the operations on the 2D shapes.
 */
class Shape2DController: public ShapeController
{
public:
    virtual Shape2DController* clone() const=0;
    virtual Shape2D* sum(const Shape2D& s) const =0;
    virtual Shape2D* sub(const Shape2D& s) const =0;
    virtual Shape2D* mul(const Shape2D& s) const =0;
    virtual Shape2D* div(const Shape2D& s) const =0;

    virtual void Translate(const Point2D&) const=0;
    virtual Shape2D* getModel() const =0;
    virtual void setModel(const Shape2D*) =0;

};

#endif // SHAPE2DCONTROLLER_H

#ifndef SHAPE3DVIEW_H
#define SHAPE3DVIEW_H

#include "UI/CalculatorInterface/calculatorinterface3d.h"
#include "View/shapeview.h"
#include "UI/CreateShape_Windows/createshape.h"
#include "Controller/Controller3D/shape3dcontroller.h"

class CalculatorInterface3D;
class Shape3DController;

/**
 * @brief The Shape3DView class is the base abstract class for the 3D shapes view.
 * It contains a reference to the UI, and the methods to connect the UI to the Controller.
 */
class Shape3DView: public ShapeView
{
private:
    CalculatorInterface3D* view;
protected:
    bool is_first_operator;
    CreateShape* Create_Shape_Window = nullptr;
public:
    Shape3DView(CalculatorInterface3D* v, bool is_first);
    Shape3DView(const Shape3DView& other);
    virtual Shape3DView& operator=(const Shape3DView& other);
    virtual ~Shape3DView();

    virtual Shape3DView* clone() const=0;
    bool CheckInputValue(long v) const;
    virtual void createModel() =0;
    virtual void moreInformation() const =0;
    virtual Shape3DController* getController() const =0;
    CalculatorInterface3D* getView() const;
};

#endif // SHAPE3DVIEW_H

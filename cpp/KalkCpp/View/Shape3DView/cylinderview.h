#ifndef CYLINDERVIEW_H
#define CYLINDERVIEW_H

#include "Controller/Controller3D/cylindercontroller.h"
#include "View/Shape3DView/shape3dview.h"
#include "UI/CalculatorInterface/calculatorinterface3d.h"

/**
 * @brief The CylinderView class is an extension of the Shape3DView, it's the view for the Cylinder Shape.
 * It contains a reference to a CylinderController* (the controller of this view) and the definition of the abstract methods of the main 3D view.
 */
class CylinderView: public Shape3DView
{
private:
    CylinderController* controller = nullptr;
public:
    CylinderView(CalculatorInterface3D* v, bool first_Operator);
    CylinderView(CalculatorInterface3D* v, CylinderController* c, bool first_Operator);
    CylinderView(const CylinderView& other);
    CylinderView& operator=(const CylinderView& other);

    CylinderView* clone() const;
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Cylinder_Data(double ray, double height, const QColor& color);

    CylinderController* getController() const;

    virtual ~CylinderView();
};

#endif // CYLINDERVIEW_H

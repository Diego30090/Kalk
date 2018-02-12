#ifndef SPHEREVIEW_H
#define SPHEREVIEW_H

#include "Controller/Controller3D/spherecontroller.h"
#include "View/Shape3DView/shape3dview.h"
#include "UI/CalculatorInterface/calculatorinterface3d.h"

/**
 * @brief The SphereView class is an extension of the Shape3DView, it's the view for the Sphere Shape.
 * It contains a reference to a SphereController* (the controller of this view) and the definition of the abstract methods of the main 3D view.
 */
class SphereView: public Shape3DView
{
private:
    SphereController* controller = nullptr;
public:
    SphereView(CalculatorInterface3D* v, bool first_Operator);
    SphereView(CalculatorInterface3D* v, SphereController* c, bool first_Operator);
    SphereView(const SphereView& other);
    SphereView& operator=(const SphereView& other);

    SphereView* clone() const;
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Sphere_Data(double ray, const QColor& color);

    SphereController* getController() const;

    virtual ~SphereView();
};

#endif // SPHEREVIEW_H

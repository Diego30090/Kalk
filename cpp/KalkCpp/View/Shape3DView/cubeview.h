#ifndef CUBEVIEW_H
#define CUBEVIEW_H

#include "Controller/Controller3D/cubecontroller.h"
#include "View/Shape3DView/shape3dview.h"
#include "UI/CalculatorInterface/calculatorinterface3d.h"

/**
 * @brief The CubeView class is an extension of the Shape3DView, it's the view for the Cube Shape.
 * It contains a reference to a CubeController* (the controller of this view) and the definition of the abstract methods of the main 3D view.
 */
class CubeView: public Shape3DView
{
private:
    CubeController* controller = nullptr;
public:
    CubeView(CalculatorInterface3D* v, bool first_Operator);
    CubeView(CalculatorInterface3D* v, CubeController* c, bool first_Operator);
    CubeView(const CubeView& other);
    CubeView& operator=(const CubeView& other);

    CubeView* clone() const;
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Cube_Data(double side, const QColor& color);

    CubeController* getController() const;

    virtual ~CubeView();
};

#endif // CUBEVIEW_H

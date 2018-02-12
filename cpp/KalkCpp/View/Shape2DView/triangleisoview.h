#ifndef TRIANGLEISOVIEW_H
#define TRIANGLEISOVIEW_H

#include "Controller/Controller2D/triangleisocontroller.h"
#include "View/Shape2DView/shape2dview.h"
#include "UI/CalculatorInterface/calculatorinterface2d.h"

/**
 * @brief The TriangleIsoView class is an extension of the Shape2DView, it's the view for the Iso. Triangle Shape.
 * It contains a reference to a TriangleIsoController* (the controller of this view) and the definition of the abstract methods of the main 2D view.
 */
class TriangleIsoView: public Shape2DView
{
private:
    TriangleIsoController* controller = nullptr;
public:
    TriangleIsoView(CalculatorInterface2D* v, bool first_Operator);
    TriangleIsoView(CalculatorInterface2D* v, TriangleIsoController* c, bool first_Operator);
    TriangleIsoView(const TriangleIsoView& other);
    TriangleIsoView& operator=(const TriangleIsoView& other);

    TriangleIsoView* clone() const;
    virtual void CreateTranslateWindow();
    virtual void ReceiveTranslateData(const Point2D& p);
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Triangle_Iso_Data(double b, double h,  const QColor& color);

    TriangleIsoController* getController() const;

    virtual ~TriangleIsoView();
};

#endif // TRIANGLEISOVIEW_H

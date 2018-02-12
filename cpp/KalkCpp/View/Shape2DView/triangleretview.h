#ifndef TRIANGLERETVIEW_H
#define TRIANGLERETVIEW_H

#include "Controller/Controller2D/triangleretcontroller.h"
#include "View/Shape2DView/shape2dview.h"
#include "UI/CalculatorInterface/calculatorinterface2d.h"

/**
 * @brief The TriangleRetView class is an extension of the Shape2DView, it's the view for the Right Triangle Shape.
 * It contains a reference to a TriangleRetController* (the controller of this view) and the definition of the abstract methods of the main 2D view.
 */
class TriangleRetView: public Shape2DView
{
private:
    TriangleRetController* controller = nullptr;
public:
    TriangleRetView(CalculatorInterface2D* v, bool first_Operator);
    TriangleRetView(CalculatorInterface2D* v, TriangleRetController* c, bool first_Operator);
    TriangleRetView(const TriangleRetView& other);
    TriangleRetView& operator=(const TriangleRetView& other);

    TriangleRetView* clone() const;
    virtual void CreateTranslateWindow();
    virtual void ReceiveTranslateData(const Point2D& p);
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Triangle_Ret_Data(double b, double h,  const QColor& color);

    TriangleRetController* getController() const;

    virtual ~TriangleRetView();
};

#endif // TRIANGLERETVIEW_H

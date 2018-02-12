#ifndef CIRCLEVIEW_H
#define CIRCLEVIEW_H

#include "Controller/Controller2D/circlecontroller.h"
#include "View/Shape2DView/shape2dview.h"
#include "UI/CalculatorInterface/calculatorinterface2d.h"

/**
 * @brief The CircleView class is an extension of the Shape2DView, it's the view for the Circle Shape.
 * It contains a reference to a CircleController* (the controller of this view) and the definition of the abstract methods of the main 2D view.
 */
class CircleView: public Shape2DView
{
private:
    CircleController* controller = nullptr;
public:
    CircleView(CalculatorInterface2D* v, bool first_Operator);
    CircleView(CalculatorInterface2D* v, CircleController* c, bool first_Operator);
    CircleView(const CircleView& other);
    CircleView& operator=(const CircleView& other);

    CircleView* clone() const;
    virtual void CreateTranslateWindow();
    virtual void ReceiveTranslateData(const Point2D& p);
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Circle_Data(double ray, const QColor& color);

    CircleController* getController() const;

    virtual ~CircleView();
};

#endif // CIRCLEVIEW_H

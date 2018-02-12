#ifndef RECTANGLEVIEW_H
#define RECTANGLEVIEW_H

#include "Controller/Controller2D/rectanglecontroller.h"
#include "View/Shape2DView/shape2dview.h"
#include "UI/CalculatorInterface/calculatorinterface2d.h"

/**
 * @brief The RectangleView class is an extension of the Shape2DView, it's the view for the Rectangle Shape.
 * It contains a reference to a RectangleController* (the controller of this view) and the definition of the abstract methods of the main 2D view.
 */
class RectangleView: public Shape2DView
{
private:
    RectangleController* controller = nullptr;
public:
    RectangleView(CalculatorInterface2D* v, bool first_Operator);
    RectangleView(CalculatorInterface2D* v, RectangleController* c, bool first_Operator);
    RectangleView(const RectangleView& other);
    RectangleView& operator=(const RectangleView& other);

    RectangleView* clone() const;
    virtual void CreateTranslateWindow();
    virtual void ReceiveTranslateData(const Point2D& p);
    virtual void createModel();
    virtual void moreInformation() const;
    virtual void Receive_Create_Rectangle_Data(double b, double h, const QColor& color);

    RectangleController* getController() const;

    virtual ~RectangleView();
};

#endif // RECTANGLEVIEW_H

#ifndef SQUAREVIEW_H
#define SQUAREVIEW_H

#include "Controller/Controller2D/squarecontroller.h"
#include "View/Shape2DView/shape2dview.h"
#include "UI/CalculatorInterface/calculatorinterface2d.h"

/**
 * @brief The SquareView class is an extension of the Shape2DView, it's the view for the Square Shape.
 * It contains a reference to a SquareController* (the controller of this view) and the definition of the abstract methods of the main 2D view.
 */
class SquareView: public Shape2DView
{
private:
    SquareController* controller = nullptr;
public:
    SquareView(CalculatorInterface2D* v, bool first_Operator);
    SquareView(CalculatorInterface2D* v, SquareController* c, bool first_Operator);
    SquareView(const SquareView& other);
    SquareView& operator=(const SquareView& other);

    SquareView* clone() const;
    virtual void createModel();
    virtual void CreateTranslateWindow();
    virtual void ReceiveTranslateData(const Point2D& p);
    virtual void moreInformation() const;
    virtual void Receive_Create_Square_Data(double side, const QColor& color);

    SquareController* getController() const;

    virtual ~SquareView();
};

#endif // SQUAREVIEW_H

#ifndef SHAPE2DVIEW_H
#define SHAPE2DVIEW_H

#include "UI/CalculatorInterface/calculatorinterface2d.h"
#include "View/shapeview.h"
#include "UI/CreateShape_Windows/createshape.h"
#include "Controller/Controller2D/shape2dcontroller.h"
#include "UI/Translate_Windows/translateinput.h"

class CalculatorInterface2D;
class Shape2DController;
class TranslateInput;

/**
 * @brief The Shape2DView class is the base abstract class for the 2D shapes view.
 * It contains a reference to the UI, and the methods to connect the UI to the Controller.
 */
class Shape2DView: public ShapeView
{
private:
    CalculatorInterface2D* view;
protected:
    TranslateInput* Translate_Shape_Window = nullptr;
    CreateShape* Create_Shape_Window = nullptr;
    bool is_first_operator;
    bool just_translated=false;
public:
    Shape2DView(CalculatorInterface2D* v, bool is_first);
    Shape2DView(const Shape2DView& other);
    virtual Shape2DView& operator=(const Shape2DView& other);
    virtual ~Shape2DView();
    virtual Shape2DView* clone() const=0;
    bool CheckInputValueToDouble(long) const;
    bool CheckInputValue(long) const;
    bool GetJustTranslated() const;
    void CancelJustTranslated();
    virtual void CreateTranslateWindow()=0;
    virtual void ReceiveTranslateData(const Point2D&)=0;
    virtual void createModel() =0;
    virtual void moreInformation() const =0;
    virtual Shape2DController* getController() const =0;
    CalculatorInterface2D* getView() const;
};

#endif // SHAPE2DVIEW_H

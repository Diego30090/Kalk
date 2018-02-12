#include "squareview.h"
#include "UI/AboutShape_Windows/about2dsquare.h"
#include "UI/CreateShape_Windows/create2dsquare.h"

SquareView::SquareView(CalculatorInterface2D* v, bool first_Operator): Shape2DView(v, first_Operator)
{
    createModel();
}

SquareView::SquareView(CalculatorInterface2D* v, SquareController* c, bool first_Operator) : Shape2DView(v, first_Operator), controller(c)
{

}

SquareView::SquareView(const SquareView& other) : Shape2DView(other), controller(other.controller->clone())
{
}

SquareView& SquareView::operator=(const SquareView& other)
{
    if(this != &other)
    {
        Shape2DView::operator =(other);
        delete controller;
        controller = new SquareController(*other.controller);
    }
    return *this;
}

void SquareView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create2DSquare(this,getView());
    Create_Shape_Window->show();
}

void SquareView::moreInformation() const
{
    About2DSquare* MoreSQ = new About2DSquare(getView());
    MoreSQ->setBaseVal(controller->side());
    MoreSQ->setPerimeter(controller->perimeter());
    MoreSQ->setArea(controller->area());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void SquareView::Receive_Create_Square_Data(double side, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new SquareController(new Square(side,new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/2D/square");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/2D/square");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

SquareController* SquareView::getController() const
{
    return controller;
}

void SquareView::CreateTranslateWindow()
{
    delete Translate_Shape_Window;
    Translate_Shape_Window = new TranslateInput(getView(), this);
    Translate_Shape_Window->show();
}
void SquareView::ReceiveTranslateData(const Point2D& p)
{
    controller->Translate(p);
    just_translated=true;
    getView()->confirm_translate();
}

SquareView* SquareView::clone() const
{
    return new SquareView(*this);
}

SquareView::~SquareView(){
    delete controller;
}

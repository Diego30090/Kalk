#include "circleview.h"
#include "UI/AboutShape_Windows/about2dcircle.h"
#include "UI/CreateShape_Windows/create2dcircle.h"

CircleView::CircleView(CalculatorInterface2D* v, bool first_Operator): Shape2DView(v, first_Operator)
{
    createModel();
}

CircleView::CircleView(CalculatorInterface2D* v, CircleController* c, bool first_Operator) : Shape2DView(v, first_Operator), controller(c)
{

}

CircleView::CircleView(const CircleView& other) : Shape2DView(other), controller(other.controller->clone())
{
}

CircleView& CircleView::operator=(const CircleView& other)
{
    if(this != &other)
    {
        Shape2DView::operator =(other);
        delete controller;
        controller = new CircleController(*other.controller);
    }
    return *this;
}

void CircleView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create2DCircle(this,getView());
    Create_Shape_Window->show();
}

void CircleView::moreInformation() const
{
    About2DCircle* MoreSQ = new About2DCircle(getView());
    MoreSQ->setRayVal(controller->ray());
    MoreSQ->setDiamVal(controller->diameter());
    MoreSQ->setCircumference(controller->circumference());
    MoreSQ->setArea(controller->area());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void CircleView::Receive_Create_Circle_Data(double ray, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new CircleController(new Circle(ray,new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/2D/circle");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/2D/circle");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

CircleController* CircleView::getController() const
{
    return controller;
}

void CircleView::CreateTranslateWindow()
{
    delete Translate_Shape_Window;
    Translate_Shape_Window = new TranslateInput(getView(), this);
    Translate_Shape_Window->show();
}
void CircleView::ReceiveTranslateData(const Point2D& p)
{
    controller->Translate(p);
    just_translated=true;
    getView()->confirm_translate();
}

CircleView* CircleView::clone() const
{
    return new CircleView(*this);
}

CircleView::~CircleView(){
    delete controller;
}


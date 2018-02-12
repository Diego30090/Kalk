#include "rectangleview.h"
#include "UI/AboutShape_Windows/about2drectangular.h"
#include "UI/CreateShape_Windows/create2drectangular.h"

RectangleView::RectangleView(CalculatorInterface2D* v, bool first_Operator): Shape2DView(v, first_Operator)
{
    createModel();
}

RectangleView::RectangleView(CalculatorInterface2D* v, RectangleController* c, bool first_Operator) : Shape2DView(v, first_Operator), controller(c)
{

}

RectangleView::RectangleView(const RectangleView& other) : Shape2DView(other), controller(other.controller->clone())
{
}

RectangleView& RectangleView::operator=(const RectangleView& other)
{
    if(this != &other)
    {
        Shape2DView::operator =(other);
        delete controller;
        controller = new RectangleController(*other.controller);
    }
    return *this;
}

void RectangleView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create2DRectangular(this,getView());
    Create_Shape_Window->show();
}

void RectangleView::moreInformation() const
{
    About2DRectangular* MoreSQ = new About2DRectangular(getView());
    MoreSQ->setBaseVal(controller->side());
    MoreSQ->setHeightVal(controller->height());
    MoreSQ->setPerimeter(controller->perimeter());
    MoreSQ->setArea(controller->area());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void RectangleView::Receive_Create_Rectangle_Data(double b, double h, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new RectangleController(new Rectangle(b, h, new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/2D/rectangular");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/2D/rectangular");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

RectangleController* RectangleView::getController() const
{
    return controller;
}

void RectangleView::CreateTranslateWindow()
{
    delete Translate_Shape_Window;
    Translate_Shape_Window = new TranslateInput(getView(), this);
    Translate_Shape_Window->show();
}
void RectangleView::ReceiveTranslateData(const Point2D& p)
{
    controller->Translate(p);
    just_translated=true;
    getView()->confirm_translate();
}

RectangleView* RectangleView::clone() const
{
    return new RectangleView(*this);
}

RectangleView::~RectangleView(){
    delete controller;
}


#include "triangleretview.h"
#include "UI/AboutShape_Windows/about2dtriangleret.h"
#include "UI/CreateShape_Windows/create2dtriangleret.h"

TriangleRetView::TriangleRetView(CalculatorInterface2D* v, bool first_Operator): Shape2DView(v, first_Operator)
{
    createModel();
}

TriangleRetView::TriangleRetView(CalculatorInterface2D* v, TriangleRetController* c, bool first_Operator) : Shape2DView(v, first_Operator), controller(c)
{

}

TriangleRetView::TriangleRetView(const TriangleRetView& other) : Shape2DView(other), controller(other.controller->clone())
{
}

TriangleRetView& TriangleRetView::operator=(const TriangleRetView& other)
{
    if(this != &other)
    {
        Shape2DView::operator =(other);
        delete controller;
        controller = new TriangleRetController(*other.controller);
    }
    return *this;
}

void TriangleRetView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create2DTriangleRet(this,getView());
    Create_Shape_Window->show();
}

void TriangleRetView::moreInformation() const
{
    About2DTriangleRet* MoreSQ = new About2DTriangleRet(getView());
    MoreSQ->setBaseVal(controller->base());
    MoreSQ->setHeightVal(controller->height());
    MoreSQ->setPerimeter(controller->perimeter());
    MoreSQ->setArea(controller->area());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void TriangleRetView::Receive_Create_Triangle_Ret_Data(double b, double h, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new TriangleRetController(new RightTriangle(h, b, new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/2D/triangle_ret");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/2D/triangle_ret");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

TriangleRetController* TriangleRetView::getController() const
{
    return controller;
}

void TriangleRetView::CreateTranslateWindow()
{
    delete Translate_Shape_Window;
    Translate_Shape_Window = new TranslateInput(getView(), this);
    Translate_Shape_Window->show();
}
void TriangleRetView::ReceiveTranslateData(const Point2D& p)
{
    controller->Translate(p);
    just_translated=true;
    getView()->confirm_translate();
}

TriangleRetView* TriangleRetView::clone() const
{
    return new TriangleRetView(*this);
}

TriangleRetView::~TriangleRetView(){
    delete controller;
}


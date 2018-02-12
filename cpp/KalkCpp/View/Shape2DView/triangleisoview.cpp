#include "triangleisoview.h"
#include "UI/AboutShape_Windows/about2dtriangleiso.h"
#include "UI/CreateShape_Windows/create2dtriangleiso.h"

TriangleIsoView::TriangleIsoView(CalculatorInterface2D* v, bool first_Operator): Shape2DView(v, first_Operator)
{
    createModel();
}

TriangleIsoView::TriangleIsoView(CalculatorInterface2D* v, TriangleIsoController* c, bool first_Operator) : Shape2DView(v, first_Operator), controller(c)
{

}

TriangleIsoView::TriangleIsoView(const TriangleIsoView& other) : Shape2DView(other), controller(other.controller->clone())
{
}

TriangleIsoView& TriangleIsoView::operator=(const TriangleIsoView& other)
{
    if(this != &other)
    {
        Shape2DView::operator =(other);
        delete controller;
        controller = new TriangleIsoController(*other.controller);
    }
    return *this;
}

void TriangleIsoView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create2DTriangleIso(this,getView());
    Create_Shape_Window->show();
}

void TriangleIsoView::moreInformation() const
{
    About2DTriangleIso* MoreSQ = new About2DTriangleIso(getView());
    MoreSQ->setBaseVal(controller->base());
    MoreSQ->setHeightVal(controller->height());
    MoreSQ->setPerimeter(controller->perimeter());
    MoreSQ->setArea(controller->area());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void TriangleIsoView::Receive_Create_Triangle_Iso_Data(double b, double h, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new TriangleIsoController(new IsoscelesTriangle(b, h, new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/2D/triangle_iso");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/2D/triangle_iso");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

TriangleIsoController* TriangleIsoView::getController() const
{
    return controller;
}

void TriangleIsoView::CreateTranslateWindow()
{
    delete Translate_Shape_Window;
    Translate_Shape_Window = new TranslateInput(getView(), this);
    Translate_Shape_Window->show();
}
void TriangleIsoView::ReceiveTranslateData(const Point2D& p)
{
    controller->Translate(p);
    just_translated=true;
    getView()->confirm_translate();
}

TriangleIsoView* TriangleIsoView::clone() const
{
    return new TriangleIsoView(*this);
}

TriangleIsoView::~TriangleIsoView(){
    delete controller;
}

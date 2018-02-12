#include "sphereview.h"
#include "UI/AboutShape_Windows/about3dsphere.h"
#include "UI/CreateShape_Windows/create3dsphere.h"

SphereView::SphereView(CalculatorInterface3D* v, bool first_Operator): Shape3DView(v, first_Operator)
{
    createModel();
}

SphereView::SphereView(CalculatorInterface3D* v, SphereController* c, bool first_Operator) : Shape3DView(v, first_Operator), controller(c)
{

}

SphereView::SphereView(const SphereView& other) : Shape3DView(other), controller(other.controller->clone())
{
}

SphereView& SphereView::operator=(const SphereView& other)
{
    if(this != &other)
    {
        Shape3DView::operator =(other);
        delete controller;
        controller = new SphereController(*other.controller);
    }
    return *this;
}

void SphereView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create3DSphere(this,getView());
    Create_Shape_Window->show();
}

void SphereView::moreInformation() const
{
    About3DSphere* MoreSQ = new About3DSphere(getView());
    MoreSQ->SetRayVal(controller->ray());
    MoreSQ->SetDiamVal(controller->diameter());
    MoreSQ->SetSurfaceVal(controller->surface());
    MoreSQ->SetVolumeVal(controller->volume());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void SphereView::Receive_Create_Sphere_Data(double ray, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new SphereController(new Sphere(new Circle(ray),new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/3D/sphere");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/3D/sphere");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

SphereController* SphereView::getController() const
{
    return controller;
}

SphereView* SphereView::clone() const
{
    return new SphereView(*this);
}

SphereView::~SphereView(){
    delete controller;
}

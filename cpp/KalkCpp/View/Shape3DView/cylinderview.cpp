#include "cylinderview.h"
#include "UI/AboutShape_Windows/about3dcylinder.h"
#include "UI/CreateShape_Windows/create3dcylinder.h"

CylinderView::CylinderView(CalculatorInterface3D* v, bool first_Operator): Shape3DView(v, first_Operator)
{
    createModel();
}

CylinderView::CylinderView(CalculatorInterface3D* v, CylinderController* c, bool first_Operator) : Shape3DView(v, first_Operator), controller(c)
{

}

CylinderView::CylinderView(const CylinderView& other) : Shape3DView(other), controller(other.controller->clone())
{
}

CylinderView& CylinderView::operator=(const CylinderView& other)
{
    if(this != &other)
    {
        Shape3DView::operator =(other);
        delete controller;
        controller = new CylinderController(*other.controller);
    }
    return *this;
}

void CylinderView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create3DCylinder(this,getView());
    Create_Shape_Window->show();
}

void CylinderView::moreInformation() const
{
    About3DCylinder* MoreSQ = new About3DCylinder(getView());
    MoreSQ->SetRayVal(controller->ray());
    MoreSQ->SetHeightVal(controller->height());
    MoreSQ->SetSurfaceVal(controller->surface());
    MoreSQ->SetVolumeVal(controller->volume());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void CylinderView::Receive_Create_Cylinder_Data(double ray, double height, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new CylinderController(new Cylinder(new Rectangle(ray, height), new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/3D/cylinder");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/3D/cylinder");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

CylinderController* CylinderView::getController() const
{
    return controller;
}

CylinderView* CylinderView::clone() const
{
    return new CylinderView(*this);
}

CylinderView::~CylinderView(){
    delete controller;
}

#include "cubeview.h"
#include "UI/AboutShape_Windows/about3dcube.h"
#include "UI/CreateShape_Windows/create3dcube.h"

CubeView::CubeView(CalculatorInterface3D* v, bool first_Operator): Shape3DView(v, first_Operator)
{
    createModel();
}

CubeView::CubeView(CalculatorInterface3D* v, CubeController* c, bool first_Operator) : Shape3DView(v, first_Operator), controller(c)
{

}

CubeView::CubeView(const CubeView& other) : Shape3DView(other), controller(other.controller->clone())
{
}

CubeView& CubeView::operator=(const CubeView& other)
{
    if(this != &other)
    {
        Shape3DView::operator =(other);
        delete controller;
        controller = new CubeController(*other.controller);
    }
    return *this;
}

void CubeView::createModel()
{
    delete Create_Shape_Window;
    Create_Shape_Window = new Create3DCube(this,getView());
    Create_Shape_Window->show();
}

void CubeView::moreInformation() const
{
    About3DCube* MoreSQ = new About3DCube(getView());
    MoreSQ->SetBaseVal(controller->side());
    MoreSQ->SetSurfaceVal(controller->surface());
    MoreSQ->SetVolumeVal(controller->volume());
    MoreSQ->setColor(controller->color());
    MoreSQ->show();
}

void CubeView::Receive_Create_Cube_Data(double side, const QColor& color)
{
    //FULL CREATION OF THE SHAPE
    controller = new CubeController(new Cube(new Square(side), new ColorRGB(color.red(), color.green(), color.blue())));
    if(is_first_operator){
        getView()->confirm_operator1_creation();
        getView()->getDisplay()->get_img_operator1()->change_image(":shape/3D/cube");
        getView()->getDisplay()->get_label_operator1()->setText(QString::fromStdString(controller->getModel()->getName()));
    }else{
        getView()->confirm_operator2_creation();
         getView()->getDisplay()->get_img_operator2()->change_image(":shape/3D/cube");
         getView()->getDisplay()->get_label_operator2()->setText(QString::fromStdString(controller->getModel()->getName()));
    }
}

CubeController* CubeView::getController() const
{
    return controller;
}

CubeView* CubeView::clone() const
{
    return new CubeView(*this);
}

CubeView::~CubeView(){
    delete controller;
}



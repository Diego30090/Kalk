#include "calculatorinterface3d.h"
#include "../Utils/calcbutton.h"
#include <QGridLayout>
#include "../calculatormaininterface.h"

#include "View/Shape3DView/cubeview.h"
#include "View/Shape3DView/cylinderview.h"
#include "View/Shape3DView/sphereview.h"

CalculatorInterface3D::CalculatorInterface3D(QWidget *parent) : QWidget(parent)
{
//---------------------------------------------------------------------
    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
//---------------------------------------------------------------------
    display = new CalculatorDisplay(this);
    mainLayout->addWidget(display, 1,1,3,5, Qt::AlignCenter);
    connect(display->get_Button_OpenMore_operator1(), SIGNAL (released()), this, SLOT (OpenMoreOperator1()));
    connect(display->get_Button_OpenMore_operator2(), SIGNAL (released()), this, SLOT (OpenMoreOperator2()));
    connect(display->get_Button_OpenMore_result(), SIGNAL (released()), this, SLOT (OpenMoreResult()));

    mainLayout->setRowMinimumHeight(3, 50);
    mainLayout->setColumnMinimumWidth(1, 10);
//---------------------------------------------------------------------
    SP3D = new ShapePanel3D(this);
    mainLayout->addWidget(SP3D, 5,1, 4,5, Qt::AlignTop);
    connect(SP3D->get_Cube_Button(), SIGNAL (released()), this, SLOT (create_Cube()));
    connect(SP3D->get_Sphere_Button(), SIGNAL (released()), this, SLOT (create_Sphere()));
    connect(SP3D->get_Cylinder_Button(), SIGNAL (released()), this, SLOT (create_Cylinder()));
//---------------------------------------------------------------------
    oper = new CalculatorOperations(this);
    mainLayout->addWidget(oper, 5, 6, 4, 2 ,  Qt::AlignRight);
    connect(oper->get_Plus_Button(), SIGNAL (released()), this, SLOT (Plus()));
    connect(oper->get_Minus_Button(), SIGNAL (released()), this, SLOT (Minus()));
    connect(oper->get_Multiply_Button(), SIGNAL (released()), this, SLOT (Multiply()));
    connect(oper->get_Divide_Button(), SIGNAL (released()), this, SLOT (Divide()));
    connect(oper->get_Equal_Button(), SIGNAL (released()), this, SLOT (Equal()));
    connect(oper->get_Clear_Button(), SIGNAL (released()), this, SLOT (Clear_All()));

    flip_flop = true;
    operator_choosen = false;

    setLayout(mainLayout);
    CalculatorMainInterface::PrintLog("3D Interface successfully created");
}
//---------------------------------------------------------------------
CalculatorInterface3D::~CalculatorInterface3D()
{
    delete viewOperator1;
    delete viewOperator2;
    delete viewResult;
    delete temp_viewOperator1;
    delete temp_viewOperator2;
}
//---------------------------------------------------------------------
//SLOTS
//OPERATIONS
void CalculatorInterface3D::Plus()
{
    operaton_state = CalculatorOperations::operations_list::Sum;
    display->get_img_method()->change_image(*oper->get_Plus_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface3D::Minus()
{
    operaton_state = CalculatorOperations::operations_list::Sub;
    display->get_img_method()->change_image(*oper->get_Minus_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface3D::Divide()
{
    operaton_state = CalculatorOperations::operations_list::Div;
    display->get_img_method()->change_image(*oper->get_Divide_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface3D::Multiply()
{
    operaton_state = CalculatorOperations::operations_list::Mul;
    display->get_img_method()->change_image(*oper->get_Multiply_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface3D::Equal()
{
    if(can_execute_operation()){
        CalculatorMainInterface::PrintLog("3D Interface - Executing Operation");
        DeleteResult();
        viewResult = viewOperator1->clone();
        switch(operaton_state){
        case CalculatorOperations::operations_list::Sum:
            viewResult->getController()->setModel(viewOperator1->getController()->sum(*viewOperator2->getController()->getModel()));
                break;
        case CalculatorOperations::operations_list::Sub:
            viewResult->getController()->setModel(viewOperator1->getController()->sub(*viewOperator2->getController()->getModel()));
                break;
        case CalculatorOperations::operations_list::Mul:
            viewResult->getController()->setModel(viewOperator1->getController()->mul(*viewOperator2->getController()->getModel()));
                break;
        case CalculatorOperations::operations_list::Div:
            viewResult->getController()->setModel(viewOperator1->getController()->div(*viewOperator2->getController()->getModel()));
                break;
        }
        display->get_label_ris()->setText(QString::fromStdString(viewResult->getController()->getModel()->getName()));
        display->get_img_result()->change_image(QString::fromStdString(display->get_img_operator1()->GetImagePathString()));
        display->get_Button_OpenMore_result()->setEnabled(true);
        OpenMoreResult();
    }
}
//---------------------------------------------------------------------
//OPEN MORE
void CalculatorInterface3D::OpenMoreOperator1() const
{
    viewOperator1->moreInformation();
}
void CalculatorInterface3D::OpenMoreOperator2() const
{
    viewOperator2->moreInformation();
}
void CalculatorInterface3D::OpenMoreResult() const
{
    viewResult->moreInformation();
}
//---------------------------------------------------------------------
void CalculatorInterface3D::create_Cube()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new CubeView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new CubeView(this, false);
    }
}
void CalculatorInterface3D::create_Sphere()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new SphereView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new SphereView(this, false);
    }
}
void CalculatorInterface3D::create_Cylinder()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new CylinderView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new CylinderView(this, false);
    }
}
//---------------------------------------------------------------------
CalculatorDisplay* CalculatorInterface3D::getDisplay() const
{
    return display;
}
//---------------------------------------------------------------------
//OPERATORS CLEANUP
void CalculatorInterface3D::DeleteFirstOperator()
{
    if(viewOperator1){
        delete viewOperator1;
        viewOperator1 = nullptr;
        display->ClearOperator1();
    }
}
void CalculatorInterface3D::DeleteSecondOperator()
{
    if(viewOperator2){
        delete viewOperator2;
        viewOperator2 = nullptr;
        display->ClearOperator2();
    }
}
void CalculatorInterface3D::DeleteResult()
{
    if(viewResult){
        delete viewResult;
        viewResult = nullptr;
        display->ClearResult();
    }
}
void CalculatorInterface3D::DeleteFirst_Temp_Operator()
{
    if(temp_viewOperator1){
        delete temp_viewOperator1;
        temp_viewOperator1 = nullptr;
    }
}
void CalculatorInterface3D::DeleteSecond_Temp_Operator()
{
    if(temp_viewOperator2){
        delete temp_viewOperator2;
        temp_viewOperator2 = nullptr;
    }
}
//---------------------------------------------------------------------
//FLIP FLOP FUNCTIONS
void CalculatorInterface3D::InvertFlipFlop()
{
    flip_flop=!flip_flop;
}
bool CalculatorInterface3D::change_operator()
{
    if(flip_flop)
    {
        if(viewOperator1 && viewOperator1->getController()){
            CalculatorMainInterface::PrintLog("3D - FLIP FLOP WAITING FOR DELETE FIRST OPERATOR TO CHANGE - DELETING TEMP OP1");
            DeleteFirst_Temp_Operator();
        }else{
            CalculatorMainInterface::PrintLog("3D - FLIP FLOP DELETE FIRST OPERATOR - NOT CHANGING");
            DeleteFirstOperator();
            DeleteFirst_Temp_Operator();
        }
    }else{
        if(viewOperator2 && viewOperator2->getController()){
            CalculatorMainInterface::PrintLog("3D - FLIP FLOP WAITING FOR DELETE SECOND OPERATOR TO CHANGE - DELETING TEMP OP2");
            DeleteSecond_Temp_Operator();
        }else{
            CalculatorMainInterface::PrintLog("3D - FLIP FLOP DELETE SECOND OPERATOR - NOT CHANGING");
            DeleteSecondOperator();
            DeleteSecond_Temp_Operator();
        }
    }
    return flip_flop;

}
//---------------------------------------------------------------------
//OPERATORS CONFIRM
void CalculatorInterface3D::confirm_operator1_creation()
{
    DeleteFirstOperator();
    InvertFlipFlop();
    viewOperator1 = temp_viewOperator1;
    temp_viewOperator1 = nullptr;
    setEnabledMoreInfo_Operator1(true);
    Result_Cleanup_OnChange();
    CalculatorMainInterface::PrintLog("3D Interface - Operator 1 Created");
}
void CalculatorInterface3D::confirm_operator2_creation()
{
    DeleteSecondOperator();
    InvertFlipFlop();
    viewOperator2 = temp_viewOperator2;
    temp_viewOperator2 = nullptr;
    setEnabledMoreInfo_Operator2(true);
    Result_Cleanup_OnChange();
    CalculatorMainInterface::PrintLog("3D Interface - Operator 2 Created");
}
//---------------------------------------------------------------------
//SET ENABLED
void CalculatorInterface3D::setEnabledMoreInfo_Operator1(bool e) const
{
    display->get_Button_OpenMore_operator1()->setEnabled(e);
}
void CalculatorInterface3D::setEnabledMoreInfo_Operator2(bool e) const
{
    display->get_Button_OpenMore_operator2()->setEnabled(e);
}
void CalculatorInterface3D::setEnabledMoreInfo_Result(bool e) const
{
    display->get_Button_OpenMore_result()->setEnabled(e);
}
void CalculatorInterface3D::Result_Cleanup_OnChange()
{
    DeleteResult();
}

//---------------------------------------------------------------------
bool CalculatorInterface3D::can_execute_operation() const{
    return viewOperator1 && viewOperator1->getController() && viewOperator2 && viewOperator2->getController() && operator_choosen;
}
//---------------------------------------------------------------------
void CalculatorInterface3D::Clear_All()
{
    CalculatorMainInterface::PrintLog("3D Interface - Clear pressed - Cleaning Display");
    flip_flop = true;
    operator_choosen = false;
    DeleteFirstOperator();
    DeleteSecondOperator();
    DeleteResult();
    display->ClearMathOperator();
}

#include "calculatorinterface2d.h"
#include "../Utils/calcbutton.h"
#include <QGridLayout>
#include "../calculatormaininterface.h"

#include "View/Shape2DView/squareview.h"
#include "View/Shape2DView/circleview.h"
#include "View/Shape2DView/rectangleview.h"
#include "View/Shape2DView/triangleisoview.h"
#include "View/Shape2DView/triangleretview.h"

CalculatorInterface2D::CalculatorInterface2D(QWidget *parent) : QWidget(parent)
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
    SP2D = new ShapePanel2D(this);
    mainLayout->addWidget(SP2D, 5,1, 4,5, Qt::AlignTop);
    connect(SP2D->get_Rectangular_Button(), SIGNAL (released()), this, SLOT (Create_Rectangular()));
    connect(SP2D->get_Square_Button(), SIGNAL (released()), this, SLOT (Create_Square()));
    connect(SP2D->get_Triangle_Ret_Button(), SIGNAL (released()), this, SLOT (Create_Triangle_Ret()));
    connect(SP2D->get_Triangle_Iso_Button(), SIGNAL (released()), this, SLOT (Create_Triangle_Iso()));
    connect(SP2D->get_Circle_Button(), SIGNAL (released()), this, SLOT (Create_Circle()));
//---------------------------------------------------------------------
    oper = new CalculatorOperations2D(this);
    mainLayout->addWidget(oper, 5, 6, 4, 2 ,  Qt::AlignCenter);
    connect(oper->get_Plus_Button(), SIGNAL (released()), this, SLOT (Plus()));
    connect(oper->get_Minus_Button(), SIGNAL (released()), this, SLOT (Minus()));
    connect(oper->get_Multiply_Button(), SIGNAL (released()), this, SLOT (Multiply()));
    connect(oper->get_Divide_Button(), SIGNAL (released()), this, SLOT (Divide()));
    connect(oper->get_Equal_Button(), SIGNAL (released()), this, SLOT (Equal()));
    connect(oper->get_Clear_Button(), SIGNAL (released()), this, SLOT (Clear_All()));
    connect(oper->get_Translate_Button(), SIGNAL (released()), this, SLOT (Translate()));

    flip_flop = true;
    operator_choosen = false;

    setLayout(mainLayout);
    CalculatorMainInterface::PrintLog("2D Interface successfully created");
}
//---------------------------------------------------------------------
CalculatorInterface2D::~CalculatorInterface2D()
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
void CalculatorInterface2D::Plus()
{
    operaton_state = CalculatorOperations::operations_list::Sum;
    display->get_img_method()->change_image(*oper->get_Plus_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface2D::Minus()
{
    operaton_state = CalculatorOperations::operations_list::Sub;
    display->get_img_method()->change_image(*oper->get_Minus_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface2D::Divide()
{
    operaton_state = CalculatorOperations::operations_list::Div;
    display->get_img_method()->change_image(*oper->get_Divide_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface2D::Multiply()
{
    operaton_state = CalculatorOperations::operations_list::Mul;
    display->get_img_method()->change_image(*oper->get_Multiply_Button()->getPixmapRef(), QSize(42,42));
    operator_choosen = true;
}
void CalculatorInterface2D::Equal()
{
    if(can_execute_operation()){
        CalculatorMainInterface::PrintLog("2D Interface - Executing Operation");
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
        QColor drawColor = QColor(viewResult->getController()->getModel()->getColor()->getRed(),
                                  viewResult->getController()->getModel()->getColor()->getGreen(),
                                  viewResult->getController()->getModel()->getColor()->getBlue());
        DrawInterface->SetPointsShapeResult(viewResult->getController()->getModel()->getPoints(), drawColor);
        OpenMoreResult();
    }
}
//---------------------------------------------------------------------
//OPEN MORE
void CalculatorInterface2D::OpenMoreOperator1() const
{
    viewOperator1->moreInformation();
}
void CalculatorInterface2D::OpenMoreOperator2() const
{
    viewOperator2->moreInformation();
}
void CalculatorInterface2D::OpenMoreResult() const
{
    viewResult->moreInformation();
}
//---------------------------------------------------------------------
//CREATE SHAPE
void CalculatorInterface2D::Create_Rectangular()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new RectangleView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new RectangleView(this, false);
    }
}
void CalculatorInterface2D::Create_Square()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new SquareView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new SquareView(this, false);
    }
}
void CalculatorInterface2D::Create_Triangle_Ret()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new TriangleRetView(this, true);
    }else{
        //operator1;
        temp_viewOperator2 = new TriangleRetView(this, false);
    }
}
void CalculatorInterface2D::Create_Triangle_Iso()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new TriangleIsoView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new TriangleIsoView(this, false);
    }
}
void CalculatorInterface2D::Create_Circle()
{
    if(change_operator())
    {
        //operator1
        temp_viewOperator1 = new CircleView(this, true);
    }else{
        //operator2
        temp_viewOperator2 = new CircleView(this, false);
    }
}
//---------------------------------------------------------------------
CalculatorDisplay* CalculatorInterface2D::getDisplay() const
{
    return display;
}
//---------------------------------------------------------------------
//OPERATORS CLEANUP
void CalculatorInterface2D::DeleteFirstOperator()
{
    if(viewOperator1){
        delete viewOperator1;
        viewOperator1 = nullptr;
        display->ClearOperator1();
    }
}
void CalculatorInterface2D::DeleteSecondOperator()
{
    if(viewOperator2){
        delete viewOperator2;
        viewOperator2 = nullptr;
        display->ClearOperator2();
    }
}
void CalculatorInterface2D::DeleteResult()
{
    if(viewResult){
        delete viewResult;
        viewResult = nullptr;
        display->ClearResult();
    }
}
void CalculatorInterface2D::DeleteFirst_Temp_Operator()
{
    if(temp_viewOperator1){
        delete temp_viewOperator1;
        temp_viewOperator1 = nullptr;
    }
}
void CalculatorInterface2D::DeleteSecond_Temp_Operator()
{
    if(temp_viewOperator2){
        delete temp_viewOperator2;
        temp_viewOperator2 = nullptr;
    }
}
//---------------------------------------------------------------------
//FLIP FLOP FUNCTIONS
void CalculatorInterface2D::InvertFlipFlop()
{
    flip_flop=!flip_flop;
}
bool CalculatorInterface2D::change_operator()
{
    if(flip_flop)
    {
        if(viewOperator1 && viewOperator1->getController()){
            CalculatorMainInterface::PrintLog("2D - FLIP FLOP WAITING FOR DELETE FIRST OPERATOR TO CHANGE - DELETING TEMP OP1");
            DeleteFirst_Temp_Operator();
        }else{
            CalculatorMainInterface::PrintLog("2D - FLIP FLOP DELETE FIRST OPERATOR - NOT CHANGING");
            DeleteFirstOperator();
            DeleteFirst_Temp_Operator();
        }
    }else{
        if(viewOperator2 && viewOperator2->getController()){
            CalculatorMainInterface::PrintLog("2D - FLIP FLOP WAITING FOR DELETE SECOND OPERATOR TO CHANGE - DELETING TEMP OP2");
            DeleteSecond_Temp_Operator();
        }else{
            CalculatorMainInterface::PrintLog("2D - FLIP FLOP DELETE SECOND OPERATOR - NOT CHANGING");
            DeleteSecondOperator();
            DeleteSecond_Temp_Operator();
        }
    }
    return flip_flop;

}
//---------------------------------------------------------------------
//OPERATORS CONFIRM
void CalculatorInterface2D::confirm_operator1_creation()
{
    DeleteFirstOperator();
    InvertFlipFlop();
    viewOperator1 = temp_viewOperator1;
    temp_viewOperator1 = nullptr;
    setEnabledMoreInfo_Operator1(true);
    Result_Cleanup_OnChange();
    QColor drawColor = QColor(viewOperator1->getController()->getModel()->getColor()->getRed(),
                              viewOperator1->getController()->getModel()->getColor()->getGreen(),
                              viewOperator1->getController()->getModel()->getColor()->getBlue());
    DrawInterface->SetPointsShape1(viewOperator1->getController()->getModel()->getPoints(), drawColor);
    CalculatorMainInterface::PrintLog("2D Interface - Operator 1 Created");
}
void CalculatorInterface2D::confirm_operator2_creation()
{
    DeleteSecondOperator();
    InvertFlipFlop();
    viewOperator2 = temp_viewOperator2;
    temp_viewOperator2 = nullptr;
    setEnabledMoreInfo_Operator2(true);
    Result_Cleanup_OnChange();
    QColor drawColor = QColor(viewOperator2->getController()->getModel()->getColor()->getRed(),
                              viewOperator2->getController()->getModel()->getColor()->getGreen(),
                              viewOperator2->getController()->getModel()->getColor()->getBlue());
    DrawInterface->SetPointsShape2(viewOperator2->getController()->getModel()->getPoints(), drawColor);
    CalculatorMainInterface::PrintLog("2D Interface - Operator 2 Created");
}
void CalculatorInterface2D::confirm_translate() const
{
    if(viewOperator1 && viewOperator1->GetJustTranslated()){
        CalculatorMainInterface::PrintLog("2D Interface - Updated Operator1 Draw() after translate");
        viewOperator1->CancelJustTranslated();
        QColor drawColor = QColor(viewOperator1->getController()->getModel()->getColor()->getRed(),
                                  viewOperator1->getController()->getModel()->getColor()->getGreen(),
                                  viewOperator1->getController()->getModel()->getColor()->getBlue());
        DrawInterface->SetPointsShape1(viewOperator1->getController()->getModel()->getPoints(), drawColor);
    }
    if(viewOperator2 && viewOperator2->GetJustTranslated()){
        CalculatorMainInterface::PrintLog("2D Interface - Updated Operator2 Draw() after translate");
        viewOperator2->CancelJustTranslated();
        QColor drawColor = QColor(viewOperator2->getController()->getModel()->getColor()->getRed(),
                                  viewOperator2->getController()->getModel()->getColor()->getGreen(),
                                  viewOperator2->getController()->getModel()->getColor()->getBlue());
        DrawInterface->SetPointsShape2(viewOperator2->getController()->getModel()->getPoints(), drawColor);
    }
    if(viewResult && viewResult->GetJustTranslated()){
        CalculatorMainInterface::PrintLog("2D Interface - Updated Result Draw() after translate");
        viewResult->CancelJustTranslated();
        QColor drawColor = QColor(viewResult->getController()->getModel()->getColor()->getRed(),
                                  viewResult->getController()->getModel()->getColor()->getGreen(),
                                  viewResult->getController()->getModel()->getColor()->getBlue());
        DrawInterface->SetPointsShapeResult(viewResult->getController()->getModel()->getPoints(), drawColor);
    }
}
//---------------------------------------------------------------------
//SET ENABLED
void CalculatorInterface2D::setEnabledMoreInfo_Operator1(bool e) const
{
    display->get_Button_OpenMore_operator1()->setEnabled(e);
}
void CalculatorInterface2D::setEnabledMoreInfo_Operator2(bool e) const
{
    display->get_Button_OpenMore_operator2()->setEnabled(e);
}
void CalculatorInterface2D::setEnabledMoreInfo_Result(bool e) const
{
    display->get_Button_OpenMore_result()->setEnabled(e);
}
void CalculatorInterface2D::Result_Cleanup_OnChange()
{
    DeleteResult();
}

//---------------------------------------------------------------------
bool CalculatorInterface2D::can_execute_operation() const{
    return viewOperator1 && viewOperator1->getController() && viewOperator2 && viewOperator2->getController() && operator_choosen;
}
//---------------------------------------------------------------------
void CalculatorInterface2D::Clear_All()
{
    CalculatorMainInterface::PrintLog("2D Interface - Clear pressed - Cleaning Display");
    flip_flop = true;
    operator_choosen = false;
    DeleteFirstOperator();
    DeleteSecondOperator();
    DeleteResult();
    display->ClearMathOperator();
    DrawInterface->ClearShapeDraw();
}
void CalculatorInterface2D::Translate()
{
    TranslateShapeSelector* input = new TranslateShapeSelector(this, this);
    input->show();
}
//---------------------------------------------------------------------
void CalculatorInterface2D::SetDrawInterfaceRef(CalculatorDrawInterface* r)
{
    DrawInterface=r;
}

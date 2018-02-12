#include "create2dsquare.h"

Create2DSquare::Create2DSquare(SquareView* MainInterf, QWidget *parent) : CreateShape(parent, ":shape/2D/square", "Crea un nuovo quadrato"), MainInterfaceRef(MainInterf)
{
    side = new QLineEdit(this);
    side->setFocus();
    QLabel* base_label = new QLabel("Lato:",this);
    side->setFont(CalculatorMainInterface::getMainFont());
    base_label->setFont(CalculatorMainInterface::getMainFont());

    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(side, 2);

    CreateConfirmAndCancelButton();
    SetDefaultCancelAction();
}

void Create2DSquare::Confirm()
{
    bool check_conversion;
    long val_test = side->text().toLong(&check_conversion);
    if(check_conversion && MainInterfaceRef->CheckInputValue(val_test)){
        MainInterfaceRef->Receive_Create_Square_Data(side->text().toDouble(),getColor());
        close();
    }else{
        ShowConversionErrorDialog();
    }
}

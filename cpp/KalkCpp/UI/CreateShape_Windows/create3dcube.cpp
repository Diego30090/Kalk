#include "create3dcube.h"

Create3DCube::Create3DCube(CubeView* MainInterf, QWidget *parent) : CreateShape(parent, ":shape/3D/cube", "Crea un nuovo Cubo"), MainInterfaceRef(MainInterf)
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

void Create3DCube::Confirm()
{
    bool check_conversion;
    long val_test = side->text().toLong(&check_conversion);
    if(check_conversion && MainInterfaceRef->CheckInputValue(val_test)){
        MainInterfaceRef->Receive_Create_Cube_Data(side->text().toDouble(), getColor());
        close();
    }else{
        ShowConversionErrorDialog();
    }
}

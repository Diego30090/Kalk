#include "create2dcircle.h"

Create2DCircle::Create2DCircle(CircleView* MainInterf, QWidget *parent) : CreateShape(parent, ":shape/2D/circle", "Crea un nuovo cerchio"), MainInterfaceRef(MainInterf)
{
    ray = new QLineEdit(this);
    ray->setFocus();
    QLabel* base_label = new QLabel("Raggio:",this);
    ray->setFont(CalculatorMainInterface::getMainFont());
    base_label->setFont(CalculatorMainInterface::getMainFont());

    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(ray, 2);

    CreateConfirmAndCancelButton();
    SetDefaultCancelAction();
}

void Create2DCircle::Confirm()
{
    bool check_conversion;
    long test_value = ray->text().toLong(&check_conversion);
    if(check_conversion && MainInterfaceRef->CheckInputValue(test_value)){
        MainInterfaceRef->Receive_Create_Circle_Data(ray->text().toDouble(), getColor());
        close();
    }else{
        ShowConversionErrorDialog();
    }
}

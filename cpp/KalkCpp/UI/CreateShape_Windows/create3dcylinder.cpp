#include "create3dcylinder.h"

Create3DCylinder::Create3DCylinder(CylinderView* MainInterf, QWidget *parent) : CreateShape(parent, ":shape/3D/cylinder", "Crea un nuovo Cilindro"), MainInterfaceRef(MainInterf)
{
    ray = new QLineEdit(this);
    ray->setFocus();
    QLabel* base_label = new QLabel("Raggio:",this);
    ray->setFont(CalculatorMainInterface::getMainFont());
    base_label->setFont(CalculatorMainInterface::getMainFont());

    height = new QLineEdit(this);
    QLabel* altezza_label = new QLabel("Altezza:",this);
    height->setFont(CalculatorMainInterface::getMainFont());
    altezza_label->setFont(CalculatorMainInterface::getMainFont());

    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(ray, 2);
    AddWidgetUnder(altezza_label, 1);
    AddWidgetInThisRow(height, 2);

    CreateConfirmAndCancelButton();
    SetDefaultCancelAction();
}

void Create3DCylinder::Confirm()
{
    bool check_conversion;
    long ray_val_test = ray->text().toLong(&check_conversion);
    long h_val_test = height->text().toLong(&check_conversion);
    if(check_conversion && MainInterfaceRef->CheckInputValue(ray_val_test) && MainInterfaceRef->CheckInputValue(h_val_test)){
        MainInterfaceRef->Receive_Create_Cylinder_Data(ray->text().toDouble(), height->text().toDouble(), getColor());
        close();
    }else{
        ShowConversionErrorDialog();
    }
}

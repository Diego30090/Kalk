#include "create3dsphere.h"

Create3DSphere::Create3DSphere(SphereView* MainInterf, QWidget *parent) : CreateShape(parent, ":shape/3D/sphere", "Crea una nuova Sfera"), MainInterfaceRef(MainInterf)
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

void Create3DSphere::Confirm()
{
    bool check_conversion;
    long val_test = ray->text().toLong(&check_conversion);
    if(check_conversion && MainInterfaceRef->CheckInputValue(val_test)){
        MainInterfaceRef->Receive_Create_Sphere_Data(ray->text().toDouble(), getColor());
        close();
    }else{
        ShowConversionErrorDialog();
    }
}

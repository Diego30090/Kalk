#include "create2dtriangleiso.h"

Create2DTriangleIso::Create2DTriangleIso(TriangleIsoView* MainInterf, QWidget *parent) : CreateShape(parent, ":shape/2D/triangle_iso", "Crea un nuovo Triangolo Isoscele"), MainInterfaceRef(MainInterf)
{
    base = new QLineEdit(this);
    base->setFocus();
    QLabel* base_label = new QLabel("Base:",this);
    base->setFont(CalculatorMainInterface::getMainFont());
    base_label->setFont(CalculatorMainInterface::getMainFont());

    height = new QLineEdit(this);
    QLabel* altezza_label = new QLabel("Altezza:",this);
    height->setFont(CalculatorMainInterface::getMainFont());
    altezza_label->setFont(CalculatorMainInterface::getMainFont());

    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(base, 2);
    AddWidgetUnder(altezza_label, 1);
    AddWidgetInThisRow(height, 2);

    CreateConfirmAndCancelButton();
    SetDefaultCancelAction();
}

void Create2DTriangleIso::Confirm()
{
    bool check_conversion;
    long base_val_test = base->text().toLong(&check_conversion);
    long height_val_test = height->text().toLong(&check_conversion);
    if(check_conversion && MainInterfaceRef->CheckInputValue(base_val_test) && MainInterfaceRef->CheckInputValue(height_val_test)){
        MainInterfaceRef->Receive_Create_Triangle_Iso_Data(base->text().toDouble(), height->text().toDouble(), getColor());
        close();
    }else{
        ShowConversionErrorDialog();
    }
}

#include "about3dcube.h"

About3DCube::About3DCube(QWidget *parent) : MoreInfoShape(parent, ":shape/3D/cube", "Caratteristiche del Cubo")
{
    QLabel* base_label = new QLabel("Lato:", this);
    base_label->setFont(CalculatorMainInterface::getMainFont());
    base_val = new QLabel("0", this);
    base_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(base_val, 2);

    QLabel* perim_label = new QLabel("Superficie:", this);
    perim_label->setFont(CalculatorMainInterface::getMainFont());
    surface_val = new QLabel("0", this);
    surface_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(perim_label, 1);
    AddWidgetInThisRow(surface_val, 2);

    QLabel* area_label = new QLabel("Volume:", this);
    area_label->setFont(CalculatorMainInterface::getMainFont());
    volume_val = new QLabel("0", this);
    volume_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(area_label, 1);
    AddWidgetInThisRow(volume_val, 2);

    CreateCancelButton();
    SetDefaultCancelAction();
}

void About3DCube::SetBaseVal(double v)
{
    base_val->setText(QString::number(v));
}
void About3DCube::SetSurfaceVal(double v)
{
    surface_val->setText(QString::number(v));
}
void About3DCube::SetVolumeVal(double v)
{
    volume_val->setText(QString::number(v));
}

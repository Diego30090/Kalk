#include "about3dsphere.h"

About3DSphere::About3DSphere(QWidget *parent) : MoreInfoShape(parent, ":shape/3D/sphere", "Caratteristiche della sfera")
{
    QLabel* base_label = new QLabel("Raggio:", this);
    base_label->setFont(CalculatorMainInterface::getMainFont());
    ray_val = new QLabel("0", this);
    ray_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(ray_val, 2);

    QLabel* altezza_label = new QLabel("Diametro:", this);
    altezza_label->setFont(CalculatorMainInterface::getMainFont());
    diam_val = new QLabel("0", this);
    diam_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(altezza_label, 1);
    AddWidgetInThisRow(diam_val, 2);

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

void About3DSphere::SetRayVal(double v)
{
    ray_val->setText(QString::number(v));
}
void About3DSphere::SetDiamVal(double v)
{
    diam_val->setText(QString::number(v));
}
void About3DSphere::SetSurfaceVal(double v)
{
    surface_val->setText(QString::number(v));
}
void About3DSphere::SetVolumeVal(double v)
{
    volume_val->setText(QString::number(v));
}

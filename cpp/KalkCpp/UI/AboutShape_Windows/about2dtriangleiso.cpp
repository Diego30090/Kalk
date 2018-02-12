#include "about2dtriangleiso.h"

About2DTriangleIso::About2DTriangleIso(QWidget *parent) : MoreInfoShape(parent, ":shape/2D/triangle_iso", "Caratteristiche del Triangolo Is.")
{
    QLabel* base_label = new QLabel("Base:", this);
    base_label->setFont(CalculatorMainInterface::getMainFont());
    base_val = new QLabel("0", this);
    base_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(base_val, 2);

    QLabel* altezza_label = new QLabel("Altezza:", this);
    altezza_label->setFont(CalculatorMainInterface::getMainFont());
    height_val = new QLabel("0", this);
    height_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(altezza_label, 1);
    AddWidgetInThisRow(height_val, 2);

    QLabel* perim_label = new QLabel("Perimetro:", this);
    perim_label->setFont(CalculatorMainInterface::getMainFont());
    perimeter_val = new QLabel("0", this);
    perimeter_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(perim_label, 1);
    AddWidgetInThisRow(perimeter_val, 2);

    QLabel* area_label = new QLabel("Area:", this);
    area_label->setFont(CalculatorMainInterface::getMainFont());
    area_val = new QLabel("0", this);
    area_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(area_label, 1);
    AddWidgetInThisRow(area_val, 2);

    CreateCancelButton();
    SetDefaultCancelAction();
}

void About2DTriangleIso::setBaseVal(double d)
{
    base_val->setText(QString::number(d));
}

void About2DTriangleIso::setHeightVal(double d)
{
    height_val->setText(QString::number(d));
}

void About2DTriangleIso::setPerimeter(double d)
{
    perimeter_val->setText(QString::number(d));
}

void About2DTriangleIso::setArea(double d)
{
    area_val->setText(QString::number(d));
}

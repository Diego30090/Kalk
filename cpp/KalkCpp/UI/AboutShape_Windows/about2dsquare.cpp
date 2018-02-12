#include "about2dsquare.h"

About2DSquare::About2DSquare(QWidget *parent) : MoreInfoShape(parent, ":shape/2D/square", "Caratteristiche del quadrato")
{
    QLabel* base_label = new QLabel("Lato:", this);
    base_label->setFont(CalculatorMainInterface::getMainFont());
    base_val = new QLabel("0", this);
    base_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(base_label, 1);
    AddWidgetInThisRow(base_val, 2);

    QLabel* perim_label = new QLabel("Perimetro:", this);
    perim_label->setFont(CalculatorMainInterface::getMainFont());
    perim_val = new QLabel("0", this);
    perim_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(perim_label, 1);
    AddWidgetInThisRow(perim_val, 2);

    QLabel* area_label = new QLabel("Area:", this);
    area_label->setFont(CalculatorMainInterface::getMainFont());
    area_val = new QLabel("0", this);
    area_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(area_label, 1);
    AddWidgetInThisRow(area_val, 2);

    CreateCancelButton();
    SetDefaultCancelAction();
}

void About2DSquare::setBaseVal(double d)
{
    base_val->setText(QString::number(d));
}

void About2DSquare::setPerimeter(double d)
{
    perim_val->setText(QString::number(d));
}

void About2DSquare::setArea(double d)
{
    area_val->setText(QString::number(d));
}

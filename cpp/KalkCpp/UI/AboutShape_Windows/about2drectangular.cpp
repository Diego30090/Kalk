#include "about2drectangular.h"

About2DRectangular::About2DRectangular(QWidget *parent) : MoreInfoShape(parent, ":shape/2D/rectangular", "Caratteristiche del rettagolo")
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

void About2DRectangular::setBaseVal(double d)
{
    base_val->setText(QString::number(d));
}

void About2DRectangular::setHeightVal(double d)
{
    height_val->setText(QString::number(d));
}

void About2DRectangular::setPerimeter(double d)
{
    perim_val->setText(QString::number(d));
}

void About2DRectangular::setArea(double d)
{
    area_val->setText(QString::number(d));
}

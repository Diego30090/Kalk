#include "about2dcircle.h"

About2DCircle::About2DCircle(QWidget *parent) : MoreInfoShape(parent, ":shape/2D/circle", "Caratteristiche del cerchio")
{
    QLabel* raggio_label = new QLabel("Raggio:", this);
    raggio_label->setFont(CalculatorMainInterface::getMainFont());
    ray_val = new QLabel("0", this);
    ray_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(raggio_label, 1);
    AddWidgetInThisRow(ray_val, 2);

    QLabel* diametro_label = new QLabel("Diametro:", this);
    diametro_label->setFont(CalculatorMainInterface::getMainFont());
    diam_val = new QLabel("0", this);
    diam_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(diametro_label, 1);
    AddWidgetInThisRow(diam_val, 2);

    QLabel* area_label = new QLabel("Area:", this);
    area_label->setFont(CalculatorMainInterface::getMainFont());
    area_val = new QLabel("0", this);
    area_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(area_label, 1);
    AddWidgetInThisRow(area_val, 2);

    QLabel* circ_label = new QLabel("Circonferenza:", this);
    circ_label->setFont(CalculatorMainInterface::getMainFont());
    circ_val = new QLabel("0", this);
    circ_val->setFont(CalculatorMainInterface::getMainFont());
    AddWidgetUnder(circ_label, 1);
    AddWidgetInThisRow(circ_val, 2);

    CreateCancelButton();
    SetDefaultCancelAction();
}

void About2DCircle::setRayVal(double d)
{
    ray_val->setText(QString::number(d));
}

void About2DCircle::setDiamVal(double d)
{
    diam_val->setText(QString::number(d));
}

void About2DCircle::setArea(double d)
{
    area_val->setText(QString::number(d));
}

void About2DCircle::setCircumference(double d)
{
    circ_val->setText(QString::number(d));
}

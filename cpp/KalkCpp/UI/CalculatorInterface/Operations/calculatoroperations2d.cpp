#include "calculatoroperations2d.h"

CalculatorOperations2D::CalculatorOperations2D(QWidget *parent) : CalculatorOperations(parent)
{
    Translate_Button = new CalcButton(":operations/translate", this, QSize(64,64));

    getMainLayout()->addWidget(Translate_Button, 2, 2);
}

CalcButton* CalculatorOperations2D::get_Translate_Button() const{
    return Translate_Button;
}

#include "calculatoroperations.h"

CalculatorOperations::CalculatorOperations(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    Plus_Button = new CalcButton(":operations/plus", this, QSize(64,64));
    Minus_Button = new CalcButton(":operations/minus",this, QSize(64,64));
    Multiply_Button = new CalcButton(":operations/multiply", this, QSize(64,64));
    Divide_Button = new CalcButton(":operations/divide", this, QSize(64,64));
    Equal_Button = new CalcButton(":operations/equal", this, QSize(64,64));
    Clear_Button = new CalcButton(":operations/clear", this, QSize(64,64));

    mainLayout->addWidget(Plus_Button, 1, 1);
    mainLayout->addWidget(Minus_Button, 2, 1);
    mainLayout->addWidget(Multiply_Button, 3, 1);
    mainLayout->addWidget(Divide_Button, 4, 1);
    mainLayout->addWidget(Equal_Button, 4, 2);
    mainLayout->addWidget(Clear_Button, 3, 2);

    setLayout(mainLayout);
}

CalcButton* CalculatorOperations::get_Plus_Button() const
{
    return Plus_Button;
}
CalcButton* CalculatorOperations::get_Minus_Button() const
{
    return Minus_Button;
}
CalcButton* CalculatorOperations::get_Multiply_Button() const
{
    return Multiply_Button;
}
CalcButton* CalculatorOperations::get_Divide_Button() const
{
    return Divide_Button;
}
CalcButton* CalculatorOperations::get_Equal_Button() const
{
    return Equal_Button;
}
CalcButton* CalculatorOperations::get_Clear_Button() const
{
    return Clear_Button;
}

QGridLayout* CalculatorOperations::getMainLayout() const
{
    return mainLayout;
}


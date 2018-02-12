#ifndef CALCULATOROPERATIONS2D_H
#define CALCULATOROPERATIONS2D_H

#include <QWidget>
#include <QGridLayout>
#include "calculatoroperations.h"

class CalculatorOperations2D : public CalculatorOperations{
public:
    CalculatorOperations2D(QWidget *parent = nullptr);

    CalcButton* get_Translate_Button() const;
private:
    CalcButton *Translate_Button;
};

#endif // CALCULATOROPERATIONS2D_H

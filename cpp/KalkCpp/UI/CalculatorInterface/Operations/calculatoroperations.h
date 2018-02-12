#ifndef CALCULATOROPERATIONS_H
#define CALCULATOROPERATIONS_H

#include <QWidget>
#include <QGridLayout>
#include "../../Utils/calcbutton.h"

/**
 * @brief The CalculatorOperations class is a simple Panel for our calculator, that contains the base operations that every panel has.
 * If a panel need more operations, a new class derived from this can be created, re-defining the operations_list enum and using the main layout to add new buttons.
 */
class CalculatorOperations: public QWidget
{
public:
    CalculatorOperations(QWidget *parent = nullptr);

    enum operations_list{
        Sum, Sub, Mul, Div
    };

    CalcButton* get_Plus_Button() const;
    CalcButton* get_Minus_Button() const;
    CalcButton* get_Multiply_Button() const;
    CalcButton* get_Divide_Button() const;
    CalcButton* get_Equal_Button() const;
    CalcButton* get_Clear_Button() const;

    virtual ~CalculatorOperations() = default;
protected:
    QGridLayout* getMainLayout() const;
private:
    CalcButton *Plus_Button, *Minus_Button, *Multiply_Button, *Divide_Button, *Equal_Button, *Clear_Button;

    QGridLayout* mainLayout;
};

#endif // CALCULATOROPERATIONS_H

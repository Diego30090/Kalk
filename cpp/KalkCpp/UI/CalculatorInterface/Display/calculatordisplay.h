#ifndef CALCULATORDISPLAY_H
#define CALCULATORDISPLAY_H

#include <QWidget>
#include "../../Utils/calcbutton.h"
#include "../../Utils/imagelabel.h"
#include <QLabel>

/**
 * @brief The CalculatorDisplay class is a simple Display for our calculator, that contains the image of the 2 operators used in the calculation, and the result.
 * It also has a "open more" button for every shape.
 */
class CalculatorDisplay : public QWidget
{
public:
    CalculatorDisplay(QWidget *parent = nullptr);

    ImageLabel* get_img_operator1() const;
    ImageLabel* get_img_operator2() const;
    ImageLabel* get_img_result() const;
    ImageLabel* get_img_method() const;

    QLabel* get_label_operator1() const;
    QLabel* get_label_operator2() const;
    QLabel* get_label_ris() const;

    CalcButton* get_Button_OpenMore_operator1() const;
    CalcButton* get_Button_OpenMore_operator2() const;
    CalcButton* get_Button_OpenMore_result() const;

    void ClearOperator1() const;
    void ClearOperator2() const;
    void ClearResult() const;
    void ClearMathOperator() const;
private:
    //First Operator
    ImageLabel* img_operator1;
    QLabel* label_operator1;

    //Second Operator
    ImageLabel* img_operator2;
    QLabel* label_operator2;

    ImageLabel* img_method;

    //Result Operator
    ImageLabel* ris_image;
    QLabel* label_ris;

    //more info buttons
    CalcButton* OpenMore_operator1, *OpenMore_operator2, *OpenMore_result;
};

#endif // CALCULATORDISPLAY_H

#ifndef TRANSLATESHAPESELECTOR_H
#define TRANSLATESHAPESELECTOR_H

#include <QWidget>
#include <QGridLayout>
#include "UI/CalculatorInterface/calculatorinterface2d.h"

class CalculatorInterface2D;

/**
 * @brief The TranslateShapeSelector class is a little window to let the user choose what shape translate
 * In this case it contains only 3 buttons, for the first, the second and the result shape, so the user can choose which shape translate
 * It's a friend of CalculatorInterface2D, to access directly the pointers, and then call directly view->CreateTranslateWindow();
 */
class TranslateShapeSelector: public QWidget
{
    Q_OBJECT
public:
    TranslateShapeSelector(QWidget *parent = nullptr, CalculatorInterface2D* = nullptr);
private:
    CalculatorInterface2D* interf;

    void ShowConversionErrorDialog(const QString& error_message);
private slots:
    void Operator1();
    void Operator2();
    void ShapeResult();
    void Close();
};

#endif // TRANSLATESHAPESELECTOR_H

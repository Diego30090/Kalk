#include <QApplication>
#include <iostream>
#include "UI/calculatormaininterface.h"

int main(int argc, char *argv[])
{
    CalculatorMainInterface::PrintLog("Main - Starting MainWIndowInterface...");
    QApplication app(argc, argv);
    CalculatorMainInterface calc;
    calc.show();
    CalculatorMainInterface::PrintLog("Main - Showing Main UI Interface");
    return app.exec();
}

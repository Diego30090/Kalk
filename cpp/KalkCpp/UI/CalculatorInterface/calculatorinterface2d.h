#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H
#include <QWidget>
#include "Shapes/shapepanel2d.h"
#include "../Utils/imagelabel.h"
#include "../Utils/calcbutton.h"
#include "Display/calculatordisplay.h"
#include "Operations/calculatoroperations2d.h"
#include "View/Shape2DView/shape2dview.h"
#include "UI/Translate_Windows/translateshapeselector.h"
#include "calculatordrawinterface.h"

class Shape2DController;
class Shape2DView;

/**
 * @brief The CalculatorInterface2D class is the panel for the 2D operations, there is a Display, a Operations panel, and the ShapePanel to create new shapes.
 * It's this UI_Interface that connect every button to his Shape2DView or to his correct slot, to make everything work.
 */
class CalculatorInterface2D : public QWidget
{
    Q_OBJECT

    friend class TranslateShapeSelector;

public:
    CalculatorInterface2D(QWidget *parent = nullptr);

    ~CalculatorInterface2D();

    void confirm_operator1_creation();
    void confirm_operator2_creation();

    void confirm_translate() const;

    CalculatorDisplay* getDisplay() const;

    void SetDrawInterfaceRef(CalculatorDrawInterface*);

private:

    CalculatorOperations::operations_list operaton_state;

    bool operator_choosen;
    bool flip_flop;
    ShapePanel2D* SP2D;
    CalculatorDisplay* display;
    CalculatorOperations2D* oper;
    Shape2DView* viewOperator1 = nullptr;
    Shape2DView* viewOperator2 = nullptr;
    Shape2DView* viewResult = nullptr;

    //I must have temp because user can cancel the creation of the shape
    //I use the viewOperator1 only when the user confirm the creation of the new shape
    Shape2DView* temp_viewOperator1 = nullptr;
    Shape2DView* temp_viewOperator2 = nullptr;

    CalculatorDrawInterface* DrawInterface;

    bool can_execute_operation() const;

    //The flip flop is useful to manage the creation of the operators (first then second, then first ecc...)
    void InvertFlipFlop();
    bool change_operator();

    //memory cleanup functions
    void DeleteFirstOperator();
    void DeleteFirst_Temp_Operator();
    void DeleteSecondOperator();
    void DeleteSecond_Temp_Operator();
    void DeleteResult();

    void Result_Cleanup_OnChange();

    void setEnabledMoreInfo_Operator1(bool e) const;
    void setEnabledMoreInfo_Operator2(bool e) const;
    void setEnabledMoreInfo_Result(bool e) const;
//Slots
private slots:
    void Plus();
    void Minus();
    void Divide();
    void Multiply();
    void Equal();

    void OpenMoreOperator1() const;
    void OpenMoreOperator2() const;
    void OpenMoreResult() const;

    void Create_Rectangular();
    void Create_Square();
    void Create_Triangle_Ret();
    void Create_Triangle_Iso();
    void Create_Circle();

    void Clear_All();
    void Translate();
};

#endif // CALCULATORINTERFACE_H

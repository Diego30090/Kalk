#ifndef CALCULATORINTERFACE3D_H
#define CALCULATORINTERFACE3D_H
#include <QWidget>
#include "Shapes/shapepanel3d.h"
#include "../Utils/imagelabel.h"
#include "../Utils/calcbutton.h"
#include "Display/calculatordisplay.h"
#include "Operations/calculatoroperations.h"
#include "View/Shape3DView/shape3dview.h"

class Shape3DController;
class Shape3DView;

/**
 * @brief The CalculatorInterface3D class is the panel for the 3D operations, there is a Display, a Operations panel, and the ShapePanel to create new shapes.
 * It's this UI_Interface that connect every button to his Shape3DView or to his correct slot, to make everything work.
 */
class CalculatorInterface3D : public QWidget
{
    Q_OBJECT

public:
    CalculatorInterface3D(QWidget *parent = nullptr);

    ~CalculatorInterface3D();

    void confirm_operator1_creation();
    void confirm_operator2_creation();

    CalculatorDisplay* getDisplay() const;

private:

    CalculatorOperations::operations_list operaton_state;

    bool operator_choosen;
    bool flip_flop;
    ShapePanel3D* SP3D;
    CalculatorDisplay* display;
    CalculatorOperations* oper;
    Shape3DView* viewOperator1 = nullptr;
    Shape3DView* viewOperator2 = nullptr;
    Shape3DView* viewResult = nullptr;

    //I must have temp because user can cancel the creation of the shape
    //I use the viewOperator1 only when the user confirm the creation of the new shape
    Shape3DView* temp_viewOperator1 = nullptr;
    Shape3DView* temp_viewOperator2 = nullptr;

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
private slots:
    void Plus();
    void Minus();
    void Divide();
    void Multiply();
    void Equal();

    void OpenMoreOperator1() const;
    void OpenMoreOperator2() const;
    void OpenMoreResult() const;

    void create_Cube();
    void create_Sphere();
    void create_Cylinder();

    void Clear_All();
};

#endif // CALCULATORINTERFACE3D_H

#ifndef SHAPEPANEL2D_H
#define SHAPEPANEL2D_H

#include "shapepanel.h"

/**
 * @brief The ShapePanel2D class is an extension of ShapePanel, it create the buttons that will added in the ShapePanel to create 2D shapes.
 */
class ShapePanel2D : public ShapePanel
{
public:
    ShapePanel2D(QWidget *parent = nullptr);

private:
    CalcButton *Rectangular_Button, *Square_Button, *Triangle_Ret_Button, *Triangle_Iso_Button, *Circle_Button;
public:
    CalcButton* get_Rectangular_Button() const;
    CalcButton* get_Square_Button() const;
    CalcButton* get_Triangle_Ret_Button() const;
    CalcButton* get_Triangle_Iso_Button() const;
    CalcButton* get_Circle_Button() const;
};

#endif // SHAPEPANEL2D_H

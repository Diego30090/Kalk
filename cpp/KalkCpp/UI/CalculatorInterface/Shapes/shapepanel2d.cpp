#include "shapepanel2d.h"

ShapePanel2D::ShapePanel2D(QWidget *parent) : ShapePanel(parent)
{
    QVector<CalcButton*> buttons;

    Rectangular_Button = new CalcButton("Rettangolo", ":shape/2D/rectangular", this, QSize(64,64));
    Rectangular_Button -> setMinimumSize(QSize(100,120));

    Square_Button = new CalcButton("Quadrato", ":shape/2D/square", this, QSize(64,64));
    Square_Button -> setMinimumSize(QSize(100,120));

    Triangle_Ret_Button = new CalcButton("Triangolo Rettangolo", ":shape/2D/triangle_ret", this, QSize(64,64));
    Triangle_Ret_Button -> setMinimumSize(QSize(100,120));

    Triangle_Iso_Button = new CalcButton("Triangolo Isoscele", ":shape/2D/triangle_iso", this, QSize(64,64));
    Triangle_Iso_Button -> setMinimumSize(QSize(100,120));

    Circle_Button = new CalcButton("Cerchio", ":shape/2D/circle", this, QSize(64,64));
    Circle_Button -> setMinimumSize(QSize(100,120));

    buttons.push_back(Rectangular_Button);
    buttons.push_back(Square_Button);
    buttons.push_back(Triangle_Ret_Button);
    buttons.push_back(Triangle_Iso_Button);
    buttons.push_back(Circle_Button);

    SetButtons(buttons);
}

CalcButton* ShapePanel2D::get_Rectangular_Button() const
{
    return Rectangular_Button;
}
CalcButton* ShapePanel2D::get_Square_Button() const
{
    return Square_Button;
}
CalcButton* ShapePanel2D::get_Triangle_Ret_Button() const
{
    return Triangle_Ret_Button;
}
CalcButton* ShapePanel2D::get_Triangle_Iso_Button() const
{
    return Triangle_Iso_Button;
}
CalcButton* ShapePanel2D::get_Circle_Button() const
{
    return Circle_Button;
}


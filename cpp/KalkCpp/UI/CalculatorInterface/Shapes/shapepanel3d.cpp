#include "shapepanel3d.h"

ShapePanel3D::ShapePanel3D(QWidget *parent) : ShapePanel(parent)
{
    QVector<CalcButton*> buttons;

    Cube_Button = new CalcButton("Cubo", ":shape/3D/cube", this, QSize(64,64));
    Sphere_Button = new CalcButton("Sfera", ":shape/3D/sphere", this, QSize(64,64));
    Cylinder_Button = new CalcButton("Cilindro", ":shape/3D/cylinder", this, QSize(64,64));
    Cube_Button -> setMinimumSize(QSize(100,120));
    Sphere_Button -> setMinimumSize(QSize(100,120));
    Cylinder_Button -> setMinimumSize(QSize(100,120));

    buttons.push_back(Cube_Button);
    buttons.push_back(Sphere_Button);
    buttons.push_back(Cylinder_Button);

    SetButtons(buttons);
}

CalcButton* ShapePanel3D::get_Cube_Button() const
{
    return Cube_Button;
}
CalcButton* ShapePanel3D::get_Sphere_Button() const
{
    return Sphere_Button;
}
CalcButton* ShapePanel3D::get_Cylinder_Button() const
{
    return Cylinder_Button;
}


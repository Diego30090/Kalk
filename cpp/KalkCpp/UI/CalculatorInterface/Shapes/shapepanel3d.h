#ifndef SHAPEPANEL3D_H
#define SHAPEPANEL3D_H

#include "shapepanel.h"

/**
 * @brief The ShapePanel3D class is an extension of ShapePanel, it create the buttons that will added in the ShapePanel to create 3D shapes.
 */
class ShapePanel3D: public ShapePanel
{
public:
    ShapePanel3D(QWidget *parent = nullptr);

private:
    CalcButton *Cube_Button, *Sphere_Button, *Cylinder_Button;

public:
    CalcButton* get_Cube_Button() const;
    CalcButton* get_Sphere_Button() const;
    CalcButton* get_Cylinder_Button() const;
};

#endif // SHAPEPANEL3D_H

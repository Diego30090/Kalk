#ifndef ABOUT3DCYLINDER_H
#define ABOUT3DCYLINDER_H

#include "moreinfoshape.h"

/**
 * @brief The About3DCylinder class is an Extension of MoreInfoShape, it shows Info of the 3DCylinder Shape:
 * There are public methods to set the shape's values to show.
 */
class About3DCylinder : public MoreInfoShape
{
private:
    QLabel* ray_val;
    QLabel* height_val;
    QLabel* surface_val;
    QLabel* volume_val;
public:
    About3DCylinder(QWidget *parent = nullptr);

    void SetRayVal(double);
    void SetHeightVal(double);
    void SetSurfaceVal(double);
    void SetVolumeVal(double);
};

#endif // ABOUT3DCYLINDER_H

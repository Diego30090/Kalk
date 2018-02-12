#ifndef ABOUT3DCUBE_H
#define ABOUT3DCUBE_H

#include "moreinfoshape.h"

/**
 * @brief The About3DCube class is an Extension of MoreInfoShape, it shows Info of the 3DCube Shape:
 * There are public methods to set the shape's values to show.
 */
class About3DCube : public MoreInfoShape
{
private:
    QLabel* base_val;
    QLabel* surface_val;
    QLabel* volume_val;
public:
    About3DCube(QWidget *parent = nullptr);

    void SetBaseVal(double);
    void SetSurfaceVal(double);
    void SetVolumeVal(double);
};

#endif // ABOUT3DCUBE_H

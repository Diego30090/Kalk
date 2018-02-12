#ifndef ABOUT3DSPHERE_H
#define ABOUT3DSPHERE_H

#include "moreinfoshape.h"

/**
 * @brief The About3DSphere class is an Extension of MoreInfoShape, it shows Info of the 3DSphere Shape:
 * There are public methods to set the shape's values to show.
 */
class About3DSphere : public MoreInfoShape
{
private:
    QLabel* ray_val;
    QLabel* diam_val;
    QLabel* surface_val;
    QLabel* volume_val;
public:
    About3DSphere(QWidget *parent = nullptr);

    void SetRayVal(double);
    void SetDiamVal(double);
    void SetSurfaceVal(double);
    void SetVolumeVal(double);
};

#endif // ABOUT3DSPHERE_H

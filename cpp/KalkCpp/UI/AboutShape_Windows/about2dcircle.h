#ifndef ABOUT2DCIRCLE_H
#define ABOUT2DCIRCLE_H

#include "moreinfoshape.h"

/**
 * @brief The About2DCircle class is an Extension of MoreInfoShape, it shows Info of the 2DCircle Shape:
 * There are public methods to set the shape's values to show.
 */
class About2DCircle : public MoreInfoShape
{
private:
     QLabel* ray_val;
     QLabel* diam_val;
     QLabel* circ_val;
     QLabel* area_val;
public:
    About2DCircle(QWidget *parent = nullptr);
    void setRayVal(double);
    void setDiamVal(double);
    void setCircumference(double);
    void setArea(double);
};

#endif // ABOUT2DCIRCLE_H

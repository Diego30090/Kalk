#ifndef ABOUT2DSQUARE_H
#define ABOUT2DSQUARE_H

#include "moreinfoshape.h"

/**
 * @brief The About2DSquare class is an Extension of MoreInfoShape, it shows Info of the 2DSquare Shape:
 * There are public methods to set the shape's values to show.
 */
class About2DSquare : public MoreInfoShape
{
private:
     QLabel* base_val;
     QLabel* perim_val;
     QLabel* area_val;
public:
    About2DSquare(QWidget *parent = nullptr);
    void setBaseVal(double);
    void setPerimeter(double);
    void setArea(double);
};

#endif // ABOUT2DSQUARE_H

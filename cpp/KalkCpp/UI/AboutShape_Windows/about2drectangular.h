#ifndef ABOUT2DRECTANGULAR_H
#define ABOUT2DRECTANGULAR_H

#include "moreinfoshape.h"

/**
 * @brief The About2DRectangular class is an Extension of MoreInfoShape, it shows Info of the 2DRectangular Shape:
 * There are public methods to set the shape's values to show.
 */
class About2DRectangular : public MoreInfoShape
{
private:
     QLabel* base_val;
     QLabel* height_val;
     QLabel* perim_val;
     QLabel* area_val;
public:
    About2DRectangular(QWidget *parent = nullptr);
    void setBaseVal(double);
    void setHeightVal(double);
    void setPerimeter(double);
    void setArea(double);
};

#endif // ABOUT2DRECTANGULAR_H

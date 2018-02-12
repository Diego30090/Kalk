#ifndef ABOUT2DTRIANGLEISO_H
#define ABOUT2DTRIANGLEISO_H

#include "moreinfoshape.h"

/**
 * @brief The About2DTriangleIso class is an Extension of MoreInfoShape, it shows Info of the 2DTriangleIso Shape:
 * There are public methods to set the shape's values to show.
 */
class About2DTriangleIso : public MoreInfoShape
{
private:
     QLabel* base_val;
     QLabel* height_val;
     QLabel* perimeter_val;
     QLabel* area_val;
public:
    About2DTriangleIso(QWidget *parent = nullptr);
    void setBaseVal(double);
    void setHeightVal(double);
    void setPerimeter(double);
    void setArea(double);
};

#endif // ABOUT2DTRIANGLEISO_H

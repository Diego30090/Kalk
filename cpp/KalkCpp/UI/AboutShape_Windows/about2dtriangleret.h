#ifndef ABOUT2DTRIANGLERET_H
#define ABOUT2DTRIANGLERET_H

#include "moreinfoshape.h"

/**
 * @brief The About2DTriangleRet class is an Extension of MoreInfoShape, it shows Info of the 2DTriangleRet Shape:
 * There are public methods to set the shape's values to show.
 */
class About2DTriangleRet : public MoreInfoShape
{
private:
     QLabel* base_val;
     QLabel* height_val;
     QLabel* perimeter_val;
     QLabel* area_val;
public:
    About2DTriangleRet(QWidget *parent = nullptr);
    void setBaseVal(double);
    void setHeightVal(double);
    void setPerimeter(double);
    void setArea(double);
};

#endif // ABOUT2DTRIANGLERET_H

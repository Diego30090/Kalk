#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "../polygon.h"

class Quadrilateral : public Polygon
{
public:
    /**
        Constructor for Quadrilateral with 3 params: points, Quadrilateral's name and color

        @param vp2d The vector of points for the Quadrilateral
        @param name The name for the Quadrilateral
        @param color The color for the Quadrilateral (default is (0,0,0)
    */
    Quadrilateral(const std::vector<Point2D>&, const std::string&, ColorRGB* = new ColorRGB());
	
};

#endif // QUADRILATERAL_H

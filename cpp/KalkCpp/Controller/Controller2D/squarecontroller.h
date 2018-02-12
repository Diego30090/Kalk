#ifndef SQUARECONTROLLER_H
#define SQUARECONTROLLER_H

#include "shape2dcontroller.h"
#include "Shape/Shape2D/Polygon/Quadrilateral/square.h"

/**
 * @brief The SquareController class is an extension of the Shape2DController, it's the controller for the Rectangle Shape.
 * It contains a reference to a Rectangle* (the model of this controller) and the definition of the abstract methods of the main 2D controller.
 */
class SquareController: public Shape2DController
{
private:
    Square* model = nullptr;
public:
    SquareController(Square*);
    SquareController(const SquareController& other);
    SquareController& operator=(const SquareController& other);

    virtual SquareController* clone() const;
    Square* sum(const Shape2D& s) const;
    Square* sub(const Shape2D& s) const;
    Square* mul(const Shape2D& s) const;
    Square* div(const Shape2D& s) const;

    virtual void Translate(const Point2D&) const;
    double area() const;
    double perimeter() const;
    double side() const;
    double diagonal() const;
    ColorRGB* color() const;
    virtual Square* getModel() const;
    virtual void setModel(const Shape2D*);

    virtual ~SquareController();
};

#endif // SQUARECONTROLLER_H

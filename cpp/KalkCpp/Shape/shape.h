#ifndef SHAPE_H
#define SHAPE_H

#include "../Color/colorrgb.h"
#include <string>

class Shape
{
private:
    //The name of the Shape
    std::string name;

    //The ColorRGB of the shape (Pointer for Polymorphism)
    ColorRGB* color = nullptr;
public:
    /**
        Constructor for Shape with 2 params: shape's name and color
        (By default create a simple ColorRGB (0,0,0))

        @param name The name for the shape
        @param color The color for the shape
    */
    Shape(std::string, ColorRGB* = new ColorRGB());

    /**
        Copy constructor for Shape

        @param s the shape to copy
    */
    Shape(const Shape& s);

    /**
     * Clone() virtual method to create a new shape from an existing one
     *
     * @return a new shape that is a copy of the current one
     */
    virtual Shape* clone() const =0;

    /**
        Equal operator for Shape

        @param s the (second) Shape to use
        @return (bool) if the invocation Shape is equal to s
    */
    virtual bool operator==(const Shape& s) const;

    /**
        Assignment operator for Shape

        @param s the (second) Shape to use
        @return the Shape that received s values
    */
    virtual Shape& operator=(const Shape& s);

    /**
        Function to get the number of Vertex of the Shape

        @return The number of vertex
    */
    virtual unsigned int getNumberVertex() const =0;

    /**
        Function to get the current color of the Shape

        @return The color of the shape
    */
    ColorRGB* getColor() const;

    /**
        Function to set the current color of the Shape

        @param newColor The color to assign

    */
    void setColor(const ColorRGB& newColor);

    /**
     * Function that return the name of the current shape
     *
     * @return The name of the current shape
     */
    std::string getName() const;

    /**
        Virtual distructor of the class
    */
    virtual ~Shape();
};

#endif // SHAPE_H

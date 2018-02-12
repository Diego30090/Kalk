#ifndef COLORRGB_H
#define COLORRGB_H

#include <iostream>

class ColorRGB
{
    /**
        Output operator for ColorRGB, print the color in (R,G,B) style

        @param os the ostream for the output
        @param crgb the ColorRGB to print
        @return the ostream used for the output
    */
    friend std::ostream& operator<<(std::ostream&, const ColorRGB&);
private:
    /** The red part of the color (0-255) */
    unsigned short red;
    /** The green part of the color (0-255) */
    unsigned short green;
    /** The blue part of the color (0-255) */
    unsigned short blue;
public:
    /**
        Constructor for ColorRGB with 3 params (R,G,B)
        (By default create the black color (0,0,0))

        @param r the red part of the color
        @param g the green part of the color
        @param b the blue part of the color
    */
    ColorRGB(unsigned short =0, unsigned short =0, unsigned short =0);

    /**
        Equal operator for ColorRGB

        @param crgb the (second) color to use
        @return (bool) if the invocation color is equal to crgb
    */
    virtual bool operator==(const ColorRGB&) const;

    /**
     * Clone() virtual method to create a new color from an existing one
     *
     * @return a new color that is a copy of the current color
     */
    virtual ColorRGB* clone() const;


    /**
        Difference operator for ColorRGB

        @param crgb the (second) color to use
        @return a new color that is the difference between the two colors
    */
    virtual ColorRGB* operator-(const ColorRGB&) const;

    /**
        Sum operator for ColorRGB

        @param crgb the (second) color to use
        @return a new color that is the sum between the two colors
    */
    virtual ColorRGB* operator+(const ColorRGB&) const;

    /**
        Multiply operator for ColorRGB

        @param crgb the (second) color to use
        @return a new color that is the multiplication between the two colors
    */
    virtual ColorRGB* operator*(const ColorRGB&) const;

    /**
        Division operator for ColorRGB

        @param crgb the (second) color to use
        @return a new color that is the Division between the two colors
    */
    virtual ColorRGB* operator/(const ColorRGB&) const;

    /**
        Function that return the red part of the color, useful for childs classes

        @return The Red value of the current color
    */
    unsigned short getRed() const;

    /**
        Function that return the green part of the color, useful for childs classes

        @return The Green value of the current color
    */
    unsigned short getGreen() const;

    /**
        Function that return the blue part of the color, useful for childs classes

        @return The blue value of the current color
    */
    unsigned short getBlue() const;

    /**
        Function that print the ColorRGB stats (red, green, blue)
    */
    virtual void printColor() const;

    /**
        Virtual distructor of the class

    */
    virtual ~ColorRGB();
};

/** Output operator for ColorRGB, see friend definition in class for more*/
std::ostream& operator<<(std::ostream&, const ColorRGB&);

#endif // COLORRGB_H

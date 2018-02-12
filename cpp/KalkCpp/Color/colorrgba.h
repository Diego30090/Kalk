#ifndef COLORRGBA_H
#define COLORRGBA_H

#include <iostream>
#include "colorrgb.h"

class ColorRGBA : public ColorRGB
{
    /**
        Output operator for ColorRGBA, print the color in (R,G,B,A) style

        @param os the ostream for the output
        @param crgba the ColorRGBA to print
        @return the ostream used for the output
    */
    friend std::ostream& operator<<(std::ostream&, const ColorRGBA&);
private:
    /** The alpha part of the color (0-255) */
    unsigned short alpha;
public:
    /**
        Constructor for ColorRGBA with 3 params (R,G,B,A)
        (By default create the black color (0,0,0,0))

        @param r the red part of the color
        @param g the green part of the color
        @param b the blue part of the color
        @param a the alpha part of the color
    */
    ColorRGBA(unsigned short =0, unsigned short =0, unsigned short =0, unsigned short =0);

    /**
        Equal operator for ColorRGBA

        @param crgba the (second) color to use
        @return (bool) if the invocation color is equal to crgba
    */
    bool operator==(const ColorRGB&) const;

    /**
     * Clone() virtual method to create a new color from an existing one
     *
     * @return a new color that is a copy of the current color
     */
    ColorRGBA* clone() const;

    /**
        Difference operator for ColorRGBA

        @param crgba the (second) color to use
        @return a new color that is the difference between the two colors
    */
    ColorRGBA* operator-(const ColorRGB&) const;

    /**
        Sum operator for ColorRGBA

        @param crgba the (second) color to use
        @return a new color that is the sum between the two colors
    */
    ColorRGBA* operator+(const ColorRGB&) const;

    /**
        Multiply operator for ColorRGBA

        @param crgba the (second) color to use
        @return a new color that is the multiplication between the two colors
    */
    ColorRGBA* operator*(const ColorRGB&) const;

    /**
        Division operator for ColorRGBA

        @param crgba the (second) color to use
        @return a new color that is the Division between the two colors
    */
    ColorRGBA* operator/(const ColorRGB&) const;

    /**
        Function that print the ColorRGBA stats (red, green, blue, alpha)
    */
    void printColor() const;
};

/** Output operator for ColorRGBA, see friend definition in class for more*/
std::ostream& operator<<(std::ostream&, const ColorRGBA&);

#endif // COLORRGBA_H

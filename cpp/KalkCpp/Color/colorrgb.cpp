#include "colorrgb.h"
#include "math.h"
#include <typeinfo>

ColorRGB::ColorRGB(unsigned short r, unsigned short g, unsigned short b) : red(r), green(g), blue(b)
{
    red = abs(red) % 256;
    green = abs(green) % 256;
    blue = abs(blue) % 256;
}


unsigned short ColorRGB::getRed() const
{
    return red;
}



unsigned short ColorRGB::getGreen() const
{
    return green;
}



ColorRGB* ColorRGB::clone() const
{
    return new ColorRGB(*this);
}



unsigned short ColorRGB::getBlue() const
{
    return blue;
}



bool ColorRGB::operator==(const ColorRGB& crgb) const
{
    if(this == &crgb)
        return true;
    if(&crgb != 0 && typeid(*this) == typeid(crgb))
    {
        return red == crgb.red && green == crgb.green && blue == crgb.blue;
    }
    return false;
}








ColorRGB* ColorRGB::operator-(const ColorRGB& crgb) const
{
    return new ColorRGB(red-crgb.red, green-crgb.green, blue-crgb.blue);
}



ColorRGB* ColorRGB::operator+(const ColorRGB& crgb) const
{
    return new ColorRGB(red+crgb.red, green+crgb.green, blue+crgb.blue);
}



ColorRGB* ColorRGB::operator*(const ColorRGB& crgb) const
{
    return new ColorRGB(red*crgb.red, green*crgb.green, blue*crgb.blue);
}



ColorRGB* ColorRGB::operator/(const ColorRGB& crgb) const
{
     if(crgb.red == 0 || crgb.green == 0 || crgb.blue == 0){
         return this->clone();
     }
     return new ColorRGB(red/crgb.red, green/crgb.green, blue/crgb.blue);
}



void ColorRGB::printColor() const
{
    std::cout << "ColorRGB(" + std::to_string(red) + "," + std::to_string(green) + "," + std::to_string(blue) + ")";
}



std::ostream& operator<<(std::ostream& os, const ColorRGB& crgb)
{
    return os<<"("<<crgb.red<<","<<crgb.green<<","<<crgb.blue<<")";
}



ColorRGB::~ColorRGB()
{

}

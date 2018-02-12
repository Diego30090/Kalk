#include "colorrgba.h"
#include <typeinfo>



ColorRGBA::ColorRGBA(unsigned short r, unsigned short g, unsigned short b, unsigned short a) : ColorRGB(r,g,b), alpha(a)
{
    alpha = abs(alpha) % 256;
}


bool ColorRGBA::operator==(const ColorRGB& crgb) const
{
    if(ColorRGB::operator ==(crgb))
    {
        const ColorRGBA& crgba = static_cast<const ColorRGBA&>(crgb);
        if(alpha == crgba.alpha)
        {
            return true;
        }
    }
    return false;
}







ColorRGBA* ColorRGBA::clone() const
{
    return new ColorRGBA(*this);
}


ColorRGBA* ColorRGBA::operator-(const ColorRGB& crgba) const
{
    ColorRGB* temp(ColorRGB::operator -(crgba));
    if(typeid(*this) == typeid(crgba))
    {
        const ColorRGBA& t = static_cast<const ColorRGBA&>(crgba);
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha - t.alpha);
    }
    else
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha);
}



ColorRGBA* ColorRGBA::operator+(const ColorRGB& crgba) const
{
    ColorRGB* temp(ColorRGB::operator +(crgba));
    if(typeid(*this) == typeid(crgba))
    {
        const ColorRGBA& t = static_cast<const ColorRGBA&>(crgba);
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha + t.alpha);
    }
    else
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha);
}



ColorRGBA* ColorRGBA::operator*(const ColorRGB& crgba) const
{
    ColorRGB* temp(ColorRGB::operator *(crgba));
    if(typeid(*this) == typeid(crgba))
    {
        const ColorRGBA& t = static_cast<const ColorRGBA&>(crgba);
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha * t.alpha);
    }
    else
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha);
}



ColorRGBA* ColorRGBA::operator/(const ColorRGB& crgba) const
{
    ColorRGB* temp(ColorRGB::operator /(crgba));
    if(typeid(*this) == typeid(crgba))
    {
        const ColorRGBA& t = static_cast<const ColorRGBA&>(crgba);
        if(t.alpha == 0)
            return this->clone();
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha / t.alpha);
    }
    else
        return new ColorRGBA(temp->getRed(), temp->getGreen(), temp->getBlue(), alpha);
}



void ColorRGBA::printColor() const
{
    std::cout << "ColorRGBA(" + std::to_string(getRed()) + "," + std::to_string(getGreen()) + "," + std::to_string(getBlue()) + "," + std::to_string(alpha) + ")";
}



std::ostream& operator<<(std::ostream& os, const ColorRGBA& crgba)
{
   return os<<"("<<crgba.getRed()<<","<<crgba.getGreen()<<","<<crgba.getBlue()<<"," << crgba.alpha << ")";
}

#include "shape.h"
#include <iostream>
#include <string.h>
#include <typeinfo>



Shape::Shape(std::string n, ColorRGB* c): name(n), color(c)
{

}



Shape::Shape(const Shape& s): name(s.name), color(s.color->clone())
{

}


bool Shape::operator ==(const Shape &s) const
{
    if(this == &s)
        return true;
    if(&s != 0 && typeid(*this) == typeid(s))
    {
        return name == s.name && *color==(*s.color);
    }
    return false;
}



Shape& Shape::operator=(const Shape& s)
{
    if(this != &s){
        name = s.name;
        delete color;
        if(s.color){
            color = s.color->clone();
        }else{
            color = nullptr;
        }
    }
    return *this;
}



ColorRGB* Shape::getColor() const
{
    return color;
}



void Shape::setColor(const ColorRGB& newColor)
{
    delete color;
    color = new ColorRGB(newColor);
}



std::string Shape::getName() const
{
    return name;
}



Shape::~Shape(){
    delete color;
    color=nullptr;
}



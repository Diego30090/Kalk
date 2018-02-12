#include "shape3dview.h"
#include <cfloat>

Shape3DView::Shape3DView(CalculatorInterface3D* v, bool is_first): view(v)
{
    is_first_operator = is_first;
}

Shape3DView::Shape3DView(const Shape3DView& other): view(other.view)
{
    is_first_operator = other.is_first_operator;
}

Shape3DView& Shape3DView::operator=(const Shape3DView& other)
{
    if(this != &other)
    {
        view = other.view;
        is_first_operator=other.is_first_operator;
    }
    return *this;
}

CalculatorInterface3D* Shape3DView::getView() const
{
    return view;
}

Shape3DView::~Shape3DView(){
    delete Create_Shape_Window;
}

bool Shape3DView::CheckInputValue(long v) const
{
    if ((v > (long double)DBL_MAX) || (v < (long double)DBL_MIN)) {
        //Value not in range
        return false;
    } else {
        //Value in range
        double x = v;
        return x>0;
    }
    return false;
}

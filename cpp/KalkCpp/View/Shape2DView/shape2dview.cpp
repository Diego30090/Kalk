#include "shape2dview.h"
#include <cfloat>

Shape2DView::Shape2DView(CalculatorInterface2D* v, bool is_first): view(v)
{
    is_first_operator = is_first;
}

Shape2DView::Shape2DView(const Shape2DView& other): view(other.view)
{
    is_first_operator = other.is_first_operator;
}

Shape2DView& Shape2DView::operator=(const Shape2DView& other)
{
    if(this != &other)
    {
        view = other.view;
        is_first_operator = other.is_first_operator;
    }
    return *this;
}

Shape2DView::~Shape2DView(){
    delete Translate_Shape_Window;
    delete Create_Shape_Window;
}

CalculatorInterface2D* Shape2DView::getView() const
{
    return view;
}
bool Shape2DView::GetJustTranslated() const
{
    return just_translated;
}
void Shape2DView::CancelJustTranslated()
{
    just_translated=false;
}
bool Shape2DView::CheckInputValueToDouble(long v) const
{
    if (v==0) return true; //the value 0 doesn't work in the second if
    if ((v > (long double)DBL_MAX) || (v < (long double)DBL_MIN)) {
        //Value not in range
        return false;
    } else {
        //Value in range
        return true;
    }
}
bool Shape2DView::CheckInputValue(long v) const
{
    if (CheckInputValueToDouble(v))
    {
        //Value in range
        double x = v;
        return x>0;
    }
    return false;
}

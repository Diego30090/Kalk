#ifndef CREATE2DRECTANGULAR_H
#define CREATE2DRECTANGULAR_H

#include "createshape.h"
#include "View/Shape2DView/rectangleview.h"
#include <QLineEdit>

class RectangleView;

/**
 * @brief The Create2DRectangular class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 2DRectangular.
 * The values insered will be sent to RectangleView that will check them (After QT confirm that they're numbers).
 */
class Create2DRectangular : public CreateShape
{
    Q_OBJECT
public:
    Create2DRectangular(RectangleView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit *base, *height;
    RectangleView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE2DRECTANGULAR_H

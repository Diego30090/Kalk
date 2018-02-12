#ifndef CREATE2DCIRCLE_H
#define CREATE2DCIRCLE_H

#include "createshape.h"
#include "View/Shape2DView/circleview.h"
#include <QLineEdit>

class CircleView;

/**
 * @brief The Create2DCircle class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 2DCircle.
 * The values insered will be sent to CircleView that will check them (After QT confirm that they're numbers).
 */
class Create2DCircle : public CreateShape
{
    Q_OBJECT
public:
    Create2DCircle(CircleView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit* ray;
    CircleView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE2DCIRCLE_H

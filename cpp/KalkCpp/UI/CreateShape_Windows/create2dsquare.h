#ifndef CREATE2DSQUARE_H
#define CREATE2DSQUARE_H

#include "createshape.h"
#include "View/Shape2DView/squareview.h"
#include <QLineEdit>

class SquareView;

/**
 * @brief The Create2DSquare class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 2DSquare.
 * The values insered will be sent to SquareView that will check them (After QT confirm that they're numbers).
 */
class Create2DSquare : public CreateShape
{
    Q_OBJECT
public:
    Create2DSquare(SquareView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit* side;
    SquareView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE2DSQUARE_H

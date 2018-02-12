#ifndef CREATE2DTRIANGLERET_H
#define CREATE2DTRIANGLERET_H

#include "createshape.h"
#include "View/Shape2DView/triangleretview.h"
#include <QLineEdit>

class TriangleRetView;

/**
 * @brief The Create2DTriangleRet class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 2DRightTriangle.
 * The values insered will be sent to TriangleRetView that will check them (After QT confirm that they're numbers).
 */
class Create2DTriangleRet : public CreateShape
{
    Q_OBJECT
public:
    Create2DTriangleRet(TriangleRetView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit *base, *height;
    TriangleRetView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE2DTRIANGLERET_H

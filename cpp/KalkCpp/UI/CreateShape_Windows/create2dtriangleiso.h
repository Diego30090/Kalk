#ifndef CREATE2DTRIANGLEISO_H
#define CREATE2DTRIANGLEISO_H

#include "createshape.h"
#include "View/Shape2DView/triangleisoview.h"
#include <QLineEdit>

class TriangleIsoView;

/**
 * @brief The Create2DTriangleIso class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 2DIso.Triangle.
 * The values insered will be sent to TriangleIsoView that will check them (After QT confirm that they're numbers).
 */
class Create2DTriangleIso : public CreateShape
{
    Q_OBJECT
public:
    Create2DTriangleIso(TriangleIsoView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit *base, *height;
    TriangleIsoView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE2DTRIANGLEISO_H

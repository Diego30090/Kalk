#ifndef CREATE3DCUBE_H
#define CREATE3DCUBE_H

#include "createshape.h"
#include "View/Shape3DView/cubeview.h"
#include <QLineEdit>

class CubeView;

/**
 * @brief The Create3DCube class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 3DCube.
 * The values insered will be sent to CubeView that will check them (After QT confirm that they're numbers).
 */
class Create3DCube : public CreateShape
{
    Q_OBJECT
public:
    Create3DCube(CubeView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit* side;
    CubeView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE3DCUBE_H
